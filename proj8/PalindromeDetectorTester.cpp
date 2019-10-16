/*
 * PalindromeDetectorTester.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: bda5
 */

#include "PalindromeDetectorTester.h"
#include "PalindromeDetector.h"
#include <cstring>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
using namespace std;

PalindromeDetectorTester::PalindromeDetectorTester() {

}

/*
 * runs tests.
 */
void PalindromeDetectorTester::runTests(){
	testDetectPalindromes();
}

/*
 * tests the PalindromeDetector class
 */
void PalindromeDetectorTester::testDetectPalindromes(){
	cout << "testing detectPalindromes and isPalindrome methods..." << endl;

	PalindromeDetector pd("test.txt","testOut.txt");
	pd.detectPalindromes();
	ifstream fin ("testOut.txt");
	string str = " ";
	getline(fin,str);
	assert ( str == "racecar***");
	getline(fin,str);
	assert ( str == "RaceCar***");
	getline(fin,str);
	assert ( str == "madam i'm adam.***");
	getline(fin,str);
	assert ( str == "madam, I'm Adam.***");
	getline(fin,str);
	assert ( str == "Race Car.***");
	getline(fin,str);
	assert ( str == "Not a palindrome.");
	cout << " 0 " << flush;

	PalindromeDetector pd1("DrawnOnward.txt","DrawnOnwardOut.txt");
	pd1.detectPalindromes();
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

