/*
 * ReversePoem.h
 *
 *  Created on: Nov 4, 2017
 *      Author: bda5
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
#include "Stack.h"
class ReversePoem {
public:
	ReversePoem();
	ReversePoem(string fileName);
	string getTitle() const { return myTitle; }
	string getAuthor() const { return myAuthor; }
	string getBody() const { return body; }
	string getBodyReversed() const { return reverseBody; }
private:
	//Stack<string> poemReversed;
	string myTitle;
	string myAuthor;
	string body;
	string reverseBody;
};

#endif /* REVERSEPOEM_H_ */
