/*
 * List.h
 *
 *  Created on: Oct 10, 2017
 *      Author: bda5
 */

#ifndef LIST_H_
#define LIST_H_
typedef double Item;
//using namespace std;

class List {
public:
	List();
	List(const List& original);
	unsigned getSize()const{ return mySize; }
	Item getFirst();
	Item getLast();
	void append(Item it);
	List& operator=(const List& original);
	virtual ~List();
private:
	struct Node{
		Item myItem;
		Node* myNext;
		Node();
		Node(Item it, Node* next);
	};
	Node* myFirst;
	Node* myLast;
	unsigned mySize;
	friend class ListTester;
};

#endif /* LIST_H_ */
