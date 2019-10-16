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
 
#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"
typedef double Item;
class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix<Item>& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
