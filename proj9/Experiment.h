/*
 * Experiment.h
 *
 *  Created on: Dec 1, 2017
 *      Author: bda5
 */

#ifndef EXPERIMENT_H_
#define EXPERIMENT_H_


#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

class Experiment {
public:
	Experiment();
	Experiment(string fn);
	unsigned getHeight() const { return bst.getHeight(); }
	unsigned getNumDuplicates() const { return numDuplicates; }
	virtual ~Experiment();

private:
	string fileName;
	unsigned numDuplicates;
	BST<long> bst;
};

#endif /* EXPERIMENT_H_ */
