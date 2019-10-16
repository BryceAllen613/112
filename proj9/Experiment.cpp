/*
 * Experiment.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: bda5
 */

#include "Experiment.h"

Experiment::Experiment() {}

/* Written by Bryce Allen
 * Constructs a new Experiment object.
 * @param fn, the file name to be opened via ifstream()
 */
Experiment::Experiment(string fn)
{
	fileName = "/home/cs/112/proj/09/";
	fileName += fn;
	ifstream fin(fileName.c_str());
	numDuplicates = 0;

	long c = 0;
	string num = "";
	for( int i = 0; i < 1048575; i++){
		fin >> c;
		try{
			bst.insert( c );
		}catch ( Exception& e ){
			numDuplicates++;
		}
	}
}

Experiment::~Experiment() {
	// TODO Auto-generated destructor stub
}

