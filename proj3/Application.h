/*
 * Application.h
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

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Vec.h"

class Application {
public:
	Application();
	void app();
private:
	void inputDimensions(unsigned num, Vec& vec);
};

#endif /* APPLICATION_H_ */
