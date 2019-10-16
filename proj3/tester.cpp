/* tester.cpp drives the testing of our Vec class.
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

#include "VecTester.h"
#include "Application.h"
int main() {
	VecTester vt;
	vt.runTests();

	Application a;
	a.app();
}
