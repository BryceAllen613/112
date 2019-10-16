/*
 * PalindromeDetector.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: bda5
 */
#include <cstring>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <locale>
#include "PalindromeDetector.h"
#include "Stack.h"
#include "ArrayQueue.h"	//PalindromeDetector pd

using namespace std;

/**
 * constructs a new Palindrome detector.
 */
PalindromeDetector::PalindromeDetector( string fileNameIn, string fileNameOut ){
	fileIn = fileNameIn;
	fileOut = fileNameOut;
}
/*
 * detects a palindrome using the isPalindrome() method.
 */
void PalindromeDetector::detectPalindromes(){
	ifstream fin(fileIn.c_str());
	ofstream fout(fileOut.c_str());
	string str=" ";
	while( str!="" )
	{
		getline(fin, str);
		if(str.size()==0){
			getline(fin, str);
		}
		fout << str << flush;
		if( isPalindrome(str) ) {
			fout << "***" << endl;
		}else {
			fout << endl;
		}
	}
}

/* tests if a line is a palindrome
 * @param str, the string to be tested
 * @return true if palindrome, false otherwise.
 */
bool PalindromeDetector::isPalindrome(string str){
	if(str.size() == 0){ return false; }

	locale loc;
	Stack<char> stack(100);
	ArrayQueue<char> queue(1);
	for( unsigned i = 0; i< str.size(); i++ ){
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		if( isalpha( str[i] ) ){
			stack.push(str[i]);
			try{
				queue.append(str[i]);
			}catch( FullQueueException& fe ){
				queue.setCapacity(queue.getCapacity()*2);
				queue.append(str[i]);
			}
		}
	}
	while( !(stack.isEmpty()) )
	{
		if(stack.pop() == queue.remove() ){}
		else{ return false; }
	}
	return true;
}

PalindromeDetector::~PalindromeDetector() {

}

