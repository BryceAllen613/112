/*
 * ReversePoem.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: bda5
 */

#include "ReversePoem.h"
#include <fstream>
#include <stdexcept>
#include <cstdlib>

ReversePoem::ReversePoem(){

}
/* Written by Bryce Allen
 * Constructs a new Reverse Poem problem-solving class.
 * @param fileName, the name of the file in which the poem to be reversed is found.
 */
ReversePoem::ReversePoem(string fileName){
	ifstream fin( fileName.c_str() );
	getline( fin, myTitle );
	getline( fin, myAuthor );

	Stack<string> poemReverse(30);
	string next;
	getline(fin, next);
	getline(fin, next);
	while(next != ""){
		try{
			poemReverse.push(next);
			//cerr << "push() worked on full stack...";
			//exit(1);
		}catch( StackException ){
			poemReverse.setCapacity( poemReverse.getCapacity()*2 );
			poemReverse.push(next);
		}
	body+=next + "\n";
	getline(fin, next);
	}
	unsigned num = poemReverse.getSize();
	for( unsigned i = 0; i < num; i++ ){
		reverseBody += poemReverse.pop() + "\n";
	}
}


