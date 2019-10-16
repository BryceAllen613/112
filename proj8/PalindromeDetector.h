/*
 * PalindromeDetector.h
 *
 *  Created on: Nov 18, 2017
 *      Author: bda5
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include <cstring>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

using namespace std;
class PalindromeDetector {
public:
	PalindromeDetector( string fileNameIn, string fileNameOut );
	void detectPalindromes();
	bool isPalindrome(string str);
	virtual ~PalindromeDetector();
private:
	string fileIn;
	string fileOut;
};

#endif /* PALINDROMEDETECTOR_H_ */
