/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 * edited on: Oct 10, 2017
 *      edited by: bda5
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

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testReadFromStream();
	void testWriteToFile();
	void testPrepend();
	void testInsert();

	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();

	void testInsertAfter();
	void testInsertBefore();
	void testInsertionOperator();
};

#endif /*LISTTESTER_H_*/
