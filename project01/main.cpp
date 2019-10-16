/*
 * main.cpp
 * tests the classes in our project
 *  Created on: Sep 12, 2017
 *      Author: bda5, cs112, at Calvin College
 */
#include "SongTester.h"
#include "PlaylistTester.h"
using namespace std;

int main() {
	SongTester sTester;
	sTester.runTests();
	PlaylistTester plTester;
	plTester.runTests();
}


