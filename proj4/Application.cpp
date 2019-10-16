/* Joel C. Adams, for CS 112 at Calvin College.
 *
 * Edited by Bryce Allen and Alex Williams
 *
 * Written by Bryce Allen:
 * != operator
 * + operator
 * readFrom(istream)
 * writeTo(string)
 *
 * Written by Alex Williams:
 * - operator
 * writeTo(ostream)
 * readFrom(string)
 * getTranspose()
 */

#include "Application.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Application::Application() {}

/* Runs the Application part of the assignment.
 * Written by Bryce Allen and Alexzander Williams
 * Precondition: The files the user inputs exist in the project folder.
 */
void Application::app(){
	while (true){

		cout << "What would you like to do? Enter the corresponding number..." << endl;
		cout << "1. Add two Matrices together \n"
				"2. Subtract two matrices \n"
				"3. Transpose a Matrix \n"
				"0. QUIT"<< endl;
		string input;
		cin >> input;
		if(input == "1"){
			string input1;
			cout << "Please enter the file name of the Matrix values:" << endl;
			cin >> input1;
			Matrix<double> m1;
			m1.readFrom(input1);
			string input2;
			cout << "Please enter another file name of the Matrix (to be added):" << endl;
			cin >> input2;
			Matrix<double> m2;
			m2.readFrom(input2);

			Matrix<double> m3 = m1+m2;
			m3.writeTo(cout);
		}
		if(input == "2"){
			string input1;
			cout << "Please enter the file name of the Matrix values:" << endl;
			cin >> input1;
			Matrix<double> m1;
			m1.readFrom(input1);
			string input2;
			cout << "Please enter another file name of the Matrix (to be subtracted):" << endl;
			cin >> input2;
			Matrix<double> m2;
			m2.readFrom(input2);

			Matrix<double> m3 = m1-m2;
			m3.writeTo(cout);
		}
		if(input == "3"){
			string input1;
			cout << "Please enter the file name of the Matrix values:" << endl;
			cin >> input1;
			Matrix<double> m1;
			m1.readFrom(input1);

			Matrix<double> m3 = m1.getTranspose();
			m3.writeTo(cout);
		}
		if (input=="0"){
			cout << "Goodbye" << endl;
				exit(0);
		}
	}
}
