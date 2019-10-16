/*
 * ImageConverter.cpp declares a class for
 *  various image conversion operations.
 *
 *  Author:  Joel Adams, CS112 @ Calvin College.
 *  Created: March 2015
 *  Revised: November 2016
 *  Revised By: Bryce Allen
 */

#include "ImageConverter.h"
#include <unistd.h>            // sleep()

//-----------------  Method definitions ------------------------------

/* explicit constructor
 *
 * @param imageFileName, a string.
 * @param width, an int.
 * @param height, an int.
 *
 * Precondition: imageFileName contains the name of a valid image file
 *               && width > 0 && height > 0
 * Postcondition: myImageFileName == imageFileName
 *                && myWidth == width && myHeight = height
 *                && width x height Canvas containing the image
 *                    from imageFileName has been displayed on screen.
 */
ImageConverter::ImageConverter(const std::string& imageFileName, int width, int height)
 : myCanvas1(0, 0, width, height, imageFileName),
   myImageFileName(imageFileName),
   myWidth(width),
   myHeight(height)
{
	//myHeight = height;
    myCanvas1.start();
    myCanvas1.drawImage(myImageFileName, 0, 0, width, height);
    sleep(1);

}

/* destructor
 *
 * Precondition: this ImageConverter object is going out of scope.
 * Postcondition: myCanvas1 has disappeared from the screen.
 */
ImageConverter::~ImageConverter() {
    myCanvas1.wait();
    cout << "\nImageConverter terminated normally." << endl;
}

/* written by Bryce Allen
 * displays the same image but in black and white
 */
void ImageConverter::toBlackAndWhite(){
	double startTime = omp_get_wtime();

	Canvas canvas2(myWidth+50, 0, myWidth, myHeight, myImageFileName+" black and white");
	canvas2.start();

	#pragma omp parallel
	{
		unsigned num_threads = omp_get_num_threads();
		unsigned id = omp_get_thread_num();

		for( int row = id; row < myHeight; row += num_threads ){
			canvas2.sleep();
			for( int col = 0; col < myWidth; col++ ){
				ColorInt pixelColor = myCanvas1.getPixel(row, col);

				int r = pixelColor.R;
				int g = pixelColor.G;
				int b = pixelColor.B;

				int GRAY = 0;
				if( r > g )
				{
					if( r > b )GRAY = r;
					else GRAY = b;
				}else{
					if ( g > b )GRAY = g;
					else GRAY = b;
				}
				canvas2.drawPixel(row, col, ColorInt(GRAY,GRAY,GRAY));
			}
		}
	}
	double endTime = omp_get_wtime();
	canvas2.takeScreenShot();
	canvas2.wait();

	double totalTime = (endTime - startTime);
	cout << "Total time to execute toBlackAndWhite() is: " << totalTime << endl;
}

/* written by Bryce Allen
 * displays the same image but mirrored horizontally
 */
void ImageConverter::mirrorHorizontal(){
	double startTime = omp_get_wtime();

	Canvas canvas3(myWidth+50, 0, myWidth, myHeight, myImageFileName+" black and white");
	canvas3.start();

	#pragma omp parallel
	{
		unsigned num_threads = omp_get_num_threads();
		unsigned id = omp_get_thread_num();

		int c = myWidth;
		for( int row = id; row < myHeight; row += num_threads )
		{
			c = myWidth;
			canvas3.sleep();
			for( int col = 0; col < myWidth; col++ )
			{
				ColorInt pixelColor = myCanvas1.getPixel(row,col);

				int red = pixelColor.R;
				int green = pixelColor.G;
				int blue = pixelColor.B;

				canvas3.drawPixel(row, c, ColorInt(red,green,blue));
				c--;
			}
		}
	}
	double endTime = omp_get_wtime();
	canvas3.takeScreenShot();
	canvas3.wait();

	double totalTime = (endTime - startTime);
	cout << "Total time to execute mirrorHorizontal() is: " << totalTime << endl;
}

