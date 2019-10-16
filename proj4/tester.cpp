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

#include "VecTester.h"
#include "MatrixTester.h"
#include "Application.h"

int main() {
//	VecTester vt;
//	vt.runTests();
	MatrixTester mt;
	mt.runTests();

	Application a1;
	a1.app();
}
