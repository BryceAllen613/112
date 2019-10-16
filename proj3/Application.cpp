/*
 * Application.cpp
 * Student Name:Bryce Allen & Catherine DeJager
 * Date:9-26-17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: Bryce Allen and Catherine DeJager, for CS 112 project 3 at Calvin College.
 *
 * Bryce Allen:
 * Retrieve [] operator
 * != operator
 * subtraction (-) operator
 * readFrom() method
 *
 * Catherine DeJager:
 * assignment [] operator
 * + operator
 * * operator
 * writeTo() method
 */

#include "Application.h"
#include<iostream>
#include"Vec.h"
using namespace std;

/*
 * Default constructor
 * (no instance variables... this is the only constructor we need.)
 */
Application::Application() {

}
/*
 * prompts the user to input dimensions for a new postition...
 * @params num: number of spaces in the position. vec: the Vector the positions will be stored into.
 */
void Application::inputDimensions(unsigned num, Vec& vec) {
	for (unsigned i = 0; i < num; i++) {
		cout << "Enter a value for dimension " << i + 1 << endl;
		double j;
		cin >> j;
		vec[i]=j;
	}
}
/* Written by Bryce Allen and Catherine DeJager.
 * Writes the application
 */
void Application::app(){
	//1
	cout<<"Welcome to vector simulator application!"<< endl<< "Enter the number of dimensions..."<< endl;
	unsigned numDimensions;
	cin>>numDimensions;
	//2
	cout<< "Enter a starting position..."<< endl;
	Vec startVec(numDimensions);
	inputDimensions(numDimensions, startVec);
	//3
	Vec resultVec(startVec);
	unsigned numVecs;
	numVecs = 0;
	cout<< "Enter as many Vectors as you would like."<< endl;
	while(true){
		Vec v0(numDimensions);
		inputDimensions(numDimensions, v0);
		resultVec = resultVec+v0;
		cout<<
		numVecs++;
		cout<<"You have entered "<< numVecs<< " position(s)."<<endl;
		string t;
		cout<< "Would you want to put in another position? (y for yes, anything else for no)"<< endl;
		cin>>t;
		if(t=="y"){}else{break;}
	}
	//4
	cout<<"Here is the sum of all the positions: " << endl;
	resultVec.writeTo(cout);
}

