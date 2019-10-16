/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin College.
 */
 
#include "StackTester.h"
#include "ReversePoemTester.h"
#include "ReversePoem.h"
#include <iostream>
using namespace std;

int main() {
	StackTester st;
	st.runTests();

	ReversePoemTester rpt;
	rpt.runTests();
	//while (in != q)
	cout << "enter the name of a poem:" <<endl;
	string in;
	cin>> in;
	ReversePoem rp(in);
	cout << "\n" << endl;
	cout << rp.getTitle() << endl;
	cout << rp.getAuthor() << endl;
	cout << "\n*** Top-To-Bottom ***\n" << endl;
	cout << rp.getBody() << endl;
	cout << "\n*** Bottom-To-Top ***\n" << endl;
	cout << rp.getBodyReversed() << endl;
}

