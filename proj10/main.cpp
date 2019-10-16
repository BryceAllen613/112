/*
 * main.cpp is a driver for an ImageConverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 * Date: March 2015.
 * Revised: November 2016.
 */

#include "ImageConverter.h"

int main() {
	for( int i = 2; i <= 16; i+=2 ){
		omp_set_num_threads(i);
	    ImageConverter iConverter("pics/beads.jpg", 800, 800);
	    cout << "number of threads: " << i << endl;
	    iConverter.toBlackAndWhite();
	    iConverter.mirrorHorizontal();
	}

}
