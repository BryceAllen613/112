/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin College.
 *
 * edited on: Oct 10, 2017
 * edited by: bda5
 *
 * Written By Bryce Allen:
 * == operator
 * testEquality() method
 * readFrom(istream) method
 * testReadFromStream()method
 * writeTo(string) method
 * testWriteToString() method
 * prepend() method
 * testPrepend() method
 * insert() method
 * testInsert() method
 *
 * Written by Nathan Gamble:
 * != operator
 * testIneqaulity() method
 * writeTo(ostream) method
 * testWriteToStream() method
 * readFrom(string) method
 * testReadFromString() method
 * getIndexOf() method
 * testGetIndexOf() method
 * remove() method
 * testRemove() method
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>
#include <vector>
using namespace std;
typedef double Item;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();

	testInequality();
	testWriteToStream();
	testReadFromString();
	testGetIndexOf();
	testRemove();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<Item> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<Item>::Node aNode;
	assert( aNode.myItem == Item() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<Item>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<Item>::Node *n3 = new List<Item>::Node(33, NULL);
	List<Item>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<Item> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<Item> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<Item> list1;
	List<Item> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<Item> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<Item> list1;
	List<Item> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<Item> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<Item> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<Item> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<Item> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<Item> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<Item> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<Item> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<Item> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

/* Tests the equality operation.
 * Written by Bryce Allen.
 */
void ListTester::testEquality(){
	cout << "Testing Equality..." << flush;

	//empty case
	List<Item> l0;
	List<Item> l1;
	assert( l0 == l1 );
	cout << " 0 " << flush;
	//non empty case
	List<Item> l2;
	List<Item> l3;
	l2.append(10);
	l2.append(11);
	l3.append(8);
	l3.append(9);
	assert( !(l2 == l3) );
	cout << " 1 " << flush;
	//non empty case (are equal)
	List<Item> l4(l2);//making both l4 and l5 copies of l2 using copy constructor
	List<Item> l5(l2);
	assert( l4==l5 );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

/* Tests the read from stream operation.
 * Written by Bryce Allen.
 */
void ListTester::testReadFromStream(){
	cout << "Testing readFrom() stream..." << flush;

	// empty case
	ifstream fin("listTest1.txt");
	List<Item> l0;
	fin >> l0.mySize;
	l0.readFrom(fin);
	assert( l0.mySize == 4 );
	assert( l0.myFirst->myItem == 3 );
	assert( l0.myFirst->myNext->myItem == 1 );
	assert( l0.myFirst->myNext->myNext->myItem == 2 );
	assert( l0.myFirst->myNext->myNext->myNext->myItem == 3 );
	assert( l0.myLast->myItem == 3 );
	cout << " 0 " << flush;
	// non empty cases
	List<Item> l1;
	ifstream fin1("listTest1.txt");
	l1.append(0);
	unsigned x = 0;
	fin1 >> x;
	l1.mySize = l1.mySize + x;
	l1.readFrom(fin1);
	assert( l1.mySize == 5 );
	assert( l1.myFirst->myItem == 0 );
	assert( l1.myFirst->myNext->myItem == 3 );
	assert( l1.myFirst->myNext->myNext->myItem == 1 );
	assert( l1.myFirst->myNext->myNext->myNext->myItem == 2 );
	assert( l1.myFirst->myNext->myNext->myNext->myNext->myItem == 3 );
	assert( l1.myLast->myItem == 3 );
	cout << " 1 " << flush;
	cout << "Passed!" << endl;
}

/* Tests the write to file operation.
 * Written by Bryce Allen.
 */
void ListTester::testWriteToFile(){
	cout << "Testing writeTo() file..." << flush;
	// empty case (file does not exist)
	ifstream fin( "listTest1.txt" );
	List<Item> l0;
	fin >> l0.mySize;
	l0.readFrom(fin);
	l0.writeTo("listTest1out.txt");
	assert( l0.mySize == 4 );
	assert( l0.myFirst->myItem == 3 );
	assert( l0.myLast->myItem == 3 );
	List<Item> l;
	l.readFrom("listTest1out.txt");
	assert( l == l0 );

	cout << " 0 " << flush;

	List<Item> l1;
	for( int i = 0; i < 4; i++){
		l1.append(i+10);
	}
	l1.writeTo("listTest2out.txt");
	List<Item> l2;
	l2.readFrom("listTest2out.txt");
	assert( l1.mySize == 4 );
	assert( l1.myFirst->myItem == 10 );
	assert( l1.myLast->myItem == 13 );
	assert( l1 == l2 );

	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

/* Tests the prepend operation.
 * Written by Bryce Allen.
 */
void ListTester::testPrepend(){
	cout << "Testing prepend() operation..." << flush;

	// prepending to empty list
	List<Item> l0;
	l0.prepend(0);
	l0.prepend(1);
	l0.prepend(2);
	l0.prepend(3);
	l0.prepend(4);
	l0.prepend(5);
	assert( l0.mySize ==6 );
	List<Item>::Node* tempPtr = l0.myFirst;
	for( int i = 5; i > -1; i-- ){
		assert ( tempPtr->myItem == i );
		tempPtr = tempPtr->myNext;
	}
	cout << " 0 " << flush;

	// prepending to non empty list

	List<Item> l1;
	l1.append(4);
	l1.append(5);
	l1.prepend(3);
	l1.prepend(2);
	l1.prepend(1);
	l1.prepend(0);
	assert( l1.mySize ==6 );
	List<Item>::Node* tempPtr1 = l1.myFirst;
	for(unsigned i = 0; i<6; i++){
		assert ( tempPtr1->myItem == i );
		tempPtr1 = tempPtr1->myNext;
	}
	cout << " 1 " << flush;
	cout << "Passed" << endl;
}

/* Tests the insert operation.
 * Written by Bryce Allen.
 */
void ListTester::testInsert(){
	cout << "Testing insert operation..." << flush;

	//empty test
	List<Item> l;
	for(unsigned i = 0; i<5; i++){
		l.insert(i+10,i);
	}
	assert(l.mySize == 5);
	List<Item>::Node* tempPtr = l.myFirst;
	for(unsigned i = 0; i<l.mySize; i++){
		assert ( tempPtr->myItem == i+10 );
		tempPtr = tempPtr->myNext;
	}
	cout << " 0 " << flush;

	//non empty test
	List<Item> l0;
	l0.append(1);
	l0.append(5);
	l0.insert(2,1);
	l0.insert(3,2);
	l0.insert(4,3);
	assert( l0.mySize ==5 );
	List<Item>::Node* tempPtr1 = l0.myFirst;
	for(unsigned i = 0; i<l0.mySize; i++){
		assert ( tempPtr1->myItem == i+1 );
		tempPtr1 = tempPtr1->myNext;
	}
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	List<double> l1, l2;
	l1.append(3);
	assert( l1 != l2 );
	cout << " 0 " << flush;
	l2.append(1);
	assert( l1 != l2 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;
	List<double> l;
	l.readFrom("ListTest1.txt");
	ofstream fout("ListTest1Copy.txt");
	assert(fout.is_open());
	l.writeTo(fout);
	fout.close();
	List<double> l1;
	l1.readFrom("ListTest1Copy.txt");
	assert(l1 == l);
	cout << "Passed!" << endl;
}

void ListTester::testReadFromString() {
	cout << "Testing readFrom(string)... " << flush;
	List<double> l;
	l.readFrom("ListTest1.txt");
	assert(l.mySize == 6);
	assert(l.myFirst->myItem == 3);
	assert(l.myFirst->myNext->myItem == 1);
	assert(l.myFirst->myNext->myNext->myItem == 4);
	assert(l.myFirst->myNext->myNext->myNext->myItem == 1);
	assert(l.myFirst->myNext->myNext->myNext->myNext->myItem == 5);
	cout << l.myLast->myItem << flush;
	assert(l.myLast->myItem == 9);

	cout << "Passed!" << endl;
}

void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf()... " << flush;
	List<double> l;
	try {
		l.getIndexOf(0);
		cerr << "getIndexOf worked with empty case" << flush;
		exit(-1);
	}
	catch (underflow_error&) {
		cout << " 0 " << flush;

	}
	List<double> l1;
	l1.readFrom("ListTest1.txt");
	assert( l1.getIndexOf(3) == 0 );
	assert( l1.getIndexOf(1) == 1 );
	assert( l1.getIndexOf(4) == 2 );
	assert( l1.getIndexOf(5) == 4 );
	assert( l1.getIndexOf(9) == 5 );
	cout << " 1 " << flush;

	List<double> l2;
	l2.append(33);
	assert( l2.getIndexOf(74) == -1 );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testRemove() {
	cout << "Testing remove()..." << flush;
	vector<double> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(9000);
	v.push_back(6);
	List<double> l(v);
	double rem;
	rem = l.remove(2);
	assert( rem == 9000 );
	assert( l.mySize == 3 );
	assert( l.myFirst->myItem == 3 );
	assert( l.myFirst->myNext->myItem == 4 );
	assert( l.myFirst->myNext->myNext->myItem == 6 );
	assert( l.myLast->myItem == 6 );
	assert( l.myFirst->myNext->myNext == l.myLast );
	cout << " 0 " << flush;

	rem = l.remove(5);
	assert(rem == 6);
	assert(l.mySize == 2);
	assert(l.myFirst->myItem == 3);
	assert(l.myFirst->myNext->myItem == 4);
	cout << l.myLast->myItem << flush;		//Testing
	assert(l.myLast->myItem == 4);
	assert(l.myFirst->myNext == l.myLast);
	cout << " 1 " << flush;

	rem = l.remove(-3);
	assert(rem == 3);
	assert(l.mySize == 1);
	assert(l.myFirst->myItem == 4);
	assert(l.myLast->myItem == 4);
	assert(l.myFirst == l.myLast);
	cout << " 2 " << flush;

	List<double> l2;
	try {
		rem = l2.remove(0);
		cerr << "Removing worked on empty list" << flush;
		exit(-1);
	}
	catch(underflow_error&) {
		cout << " 3 " << flush;
	}

	cout << "Passed!" << endl;
}

