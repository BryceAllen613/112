/*
 * ReversePoemTester.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: bda5
 */

#include "ReversePoemTester.h"
#include "ReversePoem.h"
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

ReversePoemTester::ReversePoemTester() {
}

void ReversePoemTester::runTests(){
	testConstructors();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
}
void ReversePoemTester::testConstructors(){
	cout << "Testing Constructors..." << flush;

	ReversePoem r("cats.txt");
	assert( r.getAuthor() == "Leo J. Smada" );
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}
void ReversePoemTester::testGetTitle(){
	cout << "Testing getTitle()..." << flush;

	ReversePoem r("cats.txt");
	assert( r.getTitle() == "Cats" );
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}
void ReversePoemTester::testGetAuthor(){
	cout << "Testing getAuthor()..." << flush;

	ReversePoem r("cats.txt");
	assert( r.getAuthor() == "Leo J. Smada");
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}
void ReversePoemTester::testGetBody(){
	cout << "Testing getBody()..." << flush;

	ReversePoem r("cats.txt");
	ifstream fin("cats.txt");

	string t; string u; string v;
	getline( fin, t );
	getline( fin, u );
	getline( fin, v );
	string body = "";
	string next;
	getline(fin, next);
	while(next != ""){
		body+=next + "\n";
		getline(fin, next);
	}
	assert( r.getBody() == body );
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}
void ReversePoemTester::testGetBodyReversed(){
	cout << "Testing getBodyReversed()..." << flush;

	ifstream fin( "cats.txt" );
	string t; string u; string v;

	Stack<string> rp(5);
	getline(fin,t);
	getline(fin,u);
	getline(fin,v);

	string next;
	getline(fin, next);
	while(next != ""){
		rp.push(next);
		getline(fin, next);
	}
	string reverseBody;
	unsigned num = rp.getSize();
	for( unsigned i = 0; i < num; i++ ){
		reverseBody += rp.pop() + "\n";
	}

	ReversePoem r("cats.txt");
	assert( r.getBodyReversed() == reverseBody );//"I hate those purring felines.\nI could never say\nI love it when cats rub against me." );
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}
