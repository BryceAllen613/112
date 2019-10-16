/*
 * List.h
 *
 *  Created on: Oct 10, 2017
 *      Author: neg6
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

template<class Item>
class List {
public:
	List();
	List(const vector<Item>& v);
	List(const List& original);
	List& operator=(const List& original);
	unsigned getSize() const	{return mySize;}
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	bool operator==(const List& l) const;
	bool operator!=(List& l);
	void writeTo(ostream& out) const;
	void readFrom(string filename);
	int getIndexOf(const Item& it) const;
	Item remove(int idx);
	virtual ~List();
private:
	unsigned mySize;
	struct Node {
		Node();
		Node(Item it, Node* next);
		~Node();
		Item myItem;
		Node* myNext;
	};
	Node* myFirst;
	Node* myLast;

	friend class ListTester;
};

/* Default Constructor
 * Initializes size to 0; myFirst and myLast to NULL
 */
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = NULL;
}

/* Explicit Constructor
 * @param: a Vector, v containing Items
 * Postcondition: all Items in v are stored in nodes in the List
 */
template<class Item>
List<Item>::List(const vector<Item>& v) {
	myFirst = myLast = NULL;
	mySize = 0;
	for (unsigned i = 0; i < v.size(); i++) {
		this->append(v[i]);
	}
}

/* Copy constructor
 * @param: original, a List
 * PostCondition: all the Items in original are stored in nodes in this, but the pointers are different
 */
template<class Item>
List<Item>::List(const List<Item>& original) {
	myFirst = myLast = NULL;           //  set pointers
	mySize = 0;                        //   and size to 'empty' values
	if (original.getSize() > 0) {      //  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {         //  while there are more nodes:
			append(oPtr->myItem);      //   append the item in that node
			oPtr = oPtr->myNext;       //   advance to next node
		}
	}
}


/* Node default constructor
 * Initializes myNext to NULL and makes sure myItem is an Item
 */
template<class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = NULL;
}

/* Node explicit constructor
 * @param: it, an Item and next, a Node pointer
 * Initializes myItem to it, and myNext to next
 */
template<class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

/* Get First
 * Precondition: mySize is at least 1 && myFirst is not NULL
 * Return: the Item stored in the Node pointed to in myFirst
 */
template<class Item>
Item List<Item>::getFirst() const {
	if (mySize < 1)			{throw underflow_error("Size is not right for this");}
	if (myFirst == NULL)	{throw underflow_error("myFirst doesn't point to anything");}
	return myFirst->myItem;
}

/* Get Last
 * Precondition: mySize is at least 1 && myLast is not NULL
 * Return: the Item stored in the Node pointed to in myLast
 */
template<class Item>
Item List<Item>::getLast() const {
	if (mySize < 1)			{throw underflow_error("Size is not right for this");}
	if (myLast == NULL)		{throw underflow_error("myLast doesn't point to anything");}
	return myLast->myItem;
}

/* Assignment operator
 * @param: original, a const reference to a List
 * sets this to original, if original is not the same as this
 * Return: this
 */
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
	if (myFirst != original.myFirst || myLast != original.myLast) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {
				append(oPtr->myItem);
				oPtr = oPtr->myNext;
			}
		}
	}
	return *this;
}

/* Append
 * @param: it, a const reference to an Item
 * adds a Node containing it to the list
 */
template<class Item>
void List<Item>::append(const Item& it) {
	Node* nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	}
	else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize += 1;
}

/* Equality operator
 * @param: l, a const reference to a List
 * Checks if all the items in both Lists are equal, return true if so, false if not
 */
template<class Item>
bool List<Item>::operator==(const List<Item>& l) const {
	if (mySize != l.mySize)							{return false;}
	Node* nodePtr = myFirst;
	Node* otherPtr = l.myFirst;
	while (true) {
		if (nodePtr->myItem != otherPtr->myItem)	{return false;}
		nodePtr = nodePtr->myNext;
		otherPtr = otherPtr->myNext;
		if (nodePtr == NULL)						{break;}
	}
	delete nodePtr;
	delete otherPtr;
	return true;
}

/* Inequality operator
 * @param: l, a const reference to a List
 * Checks if all the items in both Lists are equal, return false if so, true if not
 */
template<class Item>
bool List<Item>::operator!=(List<Item>& l) {
	if (mySize != l.mySize)							{return true;}
	Node* nodePtr = myFirst;
	Node* otherPtr = l.myFirst;
	while (true) {
		if (nodePtr->myItem != otherPtr->myItem)	{return true;}
		nodePtr = nodePtr->myNext;
		otherPtr = otherPtr->myNext;
		if (nodePtr == NULL)						{break;}
	}
	return false;
}

/* WriteTo(ostream version)
 * @param: out, a reference to an ostream
 * writes the items in this to the stream separated by tabs
 */
template<class Item>
void List<Item>::writeTo(ostream& out) const {
	Node* nodePtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		out << nodePtr->myItem << "\t";
		nodePtr = nodePtr->myNext;
	}
}

/* ReadFrom(string version)
 * @param: filename, a string of a name of a file
 * Reads values from a file and stores the items in Nodes in this
 */
template<class Item>
void List<Item>::readFrom(string filename) {
	mySize = 0;
	myFirst = myLast = NULL;
	ifstream in(filename.c_str());
	unsigned counter = 0;
	while (true) {
		if (!in) 									{break;}
		Item temp;
		in >> temp;
		this->append(temp);
		mySize = counter + 1;
		counter++;
	}
	mySize -= 1;
}

/* getIndexOf
 * @param: it, a const reference to an Item
 * Precondition: mySize is greater than zero
 * goes through the list and finds the first instance of an Item, stores it in index
 * Return: the index of the first instance of it, or -1 if it is not in the List
 */
template<class Item>
int List<Item>::getIndexOf(const Item& it) const {
	if (mySize == 0) {throw underflow_error("Cannot access an item in an empty list!");}
	Node* nodePtr = myFirst;
	unsigned index = 0;
	for (unsigned i = 0; i < mySize; i++) {
		if (nodePtr->myItem == it) {break;}
		nodePtr = nodePtr->myNext;
		index += 1;
		if (index == mySize) {
			index = -1;
			break;
		}
	}
	return index;
}

/* Remove
 * @param idx, an int
 * Precondition: mySize is greater than zero
 * Sets idx to 0 if it is negative, or to mySize -1 if it is greater than or equal to mySize
 * Removes the node at index idx
 * Return: the Item at the deleted node
 */
template<class Item>
Item List<Item>::remove(int idx) {
	if (mySize == 0)	{throw underflow_error("Cannot remove something from empty list");}
	if (idx < 0)		{idx = 0;}
	if (idx >= mySize)	{idx = mySize - 1;}
	Node* nodePtr1 = myFirst;
	Node* nodePtr2 = myFirst;
	Item rem;
	for (int i = 0; i < idx; i++) {
		nodePtr1 = nodePtr1->myNext;
		if (i > 0) {
			nodePtr2 = nodePtr2->myNext;
		}
	}
	rem = nodePtr1->myItem;
	if (nodePtr1 == nodePtr2) {
		myFirst = nodePtr1->myNext;
		nodePtr1->myNext = NULL;
	}
	else if (nodePtr1->myNext == NULL) {
		nodePtr2->myNext = NULL;
		myLast = nodePtr2;
	}
	else {
		nodePtr2->myNext = nodePtr1->myNext;
		nodePtr1->myNext = NULL;
	}
	delete nodePtr1;
	mySize = mySize - 1;
	return rem;
}

/* List Destructor
 * deletes myFirst, resets variables to 0
 */
template<class Item>
List<Item>::~List() {
	delete myFirst;
	mySize = 0;
	myFirst = myLast = NULL;
}

/* Node Destructor
 * calls the destructor for the Node it points to
 */
template<class Item>
List<Item>::Node::~Node() {
	delete myNext;
}

#endif /* LIST_H_ */
