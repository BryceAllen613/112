/*
 * List.h
 *
 *  Created on: Oct 10, 2017
 *      Author: bda5
 *
 * Written By Bryce Allen:
 * == operator
 * testEquality() method
 * readFrom(istream) method
 * testReadFromStream()method
 * writeTo(string) method
 * testWriteToString() method
 * prepend() method
 * testPrepend() method
 * insert() method
 * testInsert() method
 *
 * Written by Nathan Gamble:
 * != operator
 * testIneqaulity() method
 * writeTo(ostream) method
 * testWriteToStream() method
 * readFrom(string) method
 * testReadFromString() method
 * getIndexOf() method
 * testGetIndexOf() method
 * remove() method
 * testRemove() method
 */

#ifndef LIST_H_
#define LIST_H_
#include "List.h"
#include <cstddef>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
//typedef double Item;
using namespace std;
template <class Item>
class List {
public:
	List();
	List(const List& original);
	List(const vector<Item>& v);
	unsigned getSize()const{ return mySize; }
	Item getFirst();
	Item getLast();
	void append(Item it);
	List<Item>& operator=(const List<Item>& original);
	bool operator==(const List<Item>& l1)const;
	void readFrom(istream& in);
	void writeTo( string fileName )const;

	void prepend( Item it );
	void insert( Item it, unsigned index );
	bool operator!=(List& l);
	void writeTo(ostream& out) const;
	void writeToAlternate( ostream& out ) const;
	void readFrom(string filename);
	int getIndexOf(const Item& it) const;
	Item remove(int idx);

	bool insertAfter(const string& otherPersonsName, const string& newName);
	bool insertBefore(const string& otherPersonsName, const string& newName);
	//ostream& operator<<( List<Item>& list )const;

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




template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
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

template <class Item>
List<Item>::List(const List& original){
	myFirst = myLast = NULL;
	mySize = 0;
	if(original.getSize() > 0){
		Node* oPtr = original.myFirst;
		while (oPtr != NULL){
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
}

template <class Item>
List<Item>::Node::Node(){
	myItem = 0.0;
	myNext = NULL;
}

template <class Item>
List<Item>::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}

template <class Item>
Item List<Item>::getFirst(){
	if(myFirst==NULL){
		throw underflow_error("Empty List.");
	}
	return myFirst->myItem;
}

template <class Item>
Item List<Item>::getLast(){
	if(myLast==NULL){
		throw underflow_error("Empty List.");
	}
	return myLast->myItem;
}

template <class Item>
void List<Item>::append(Item it){
	Node* nodePtr = new Node(it, NULL);
	if(mySize == 0){
		myFirst = nodePtr;
	}else{
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize++;
}

template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original){
	if(original.myFirst == myFirst){return *this ;}
	delete myFirst;
	myFirst = NULL;
	delete myLast;
	myLast = NULL;
	mySize = 0;
	if( original.getSize()>0 ){
	Node* oPtr = original.myFirst;
		while (oPtr != NULL){
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
	mySize = original.getSize();
	return *this ;
}
/* Compares List objects, testing if they are equal.
 * Written by Bryce Allen
 * @param l1, the list to be compared to this list.
 * @return true if the two lists are equal, false if otherwise.
 */
template <class Item>
bool List<Item>::operator==(const List<Item>& l1)const{
	if (l1.mySize != mySize) return false;
	Node* oPtr = myFirst;
	Node* l1Ptr = l1.myFirst;
	while( oPtr && l1Ptr ){
		if( oPtr->myItem != l1Ptr->myItem ) return false;
		oPtr = oPtr->myNext;
		l1Ptr = l1Ptr->myNext;
	}
	return true;
}
/* reads the values from an istream.
 * Written by Bryce Allen
 * @param in, the ostream we will read the values from.
 */
template <class Item>
void List<Item>::readFrom(istream& in){
	Item it;
	in >> it;
	Node* nodePtr;
	nodePtr = new Node(it, NULL);
	for( unsigned i = 0; i < mySize; i++){
		if(myFirst == NULL && myLast == NULL){
			myFirst = nodePtr;
		}else{
			myLast->myNext = nodePtr;
		}
		myLast = nodePtr;

		in >> it;
		nodePtr = new Node(it, NULL);
	}
}

/* writes values to a file from this list.
 * Written by Bryce Allen
 * @param fileName, the name of the file we will write the items to.
 */
template <class Item>
void List<Item>::writeTo( string fileName )const{
	ofstream fout( fileName.c_str() );
	Node* tempPtr = myFirst;
	while( tempPtr ){
		fout << tempPtr->myItem << endl;
		tempPtr = tempPtr->myNext;
	}
}

/* Attaches a new item to the FRONT of the list.
 * Written by Bryce Allen
 * @param it, the item to be prepended.
 */
template <class Item>
void List<Item>::prepend( Item it ){
	Node* newPtr = new Node( it, myFirst );
	if( mySize == 0 ){
		myLast = newPtr;
	}
	myFirst = newPtr;
	mySize ++;
}

/* Inserts and item at desired index
 * Written by Bryce Allen
 * @param it, the item to insert
 * @param index, the position to insert
 */
template <class Item>
void List<Item>::insert( Item it, unsigned index ){
	if( index > mySize ){ throw range_error("index is out of range."); }
	Node * newPtr = new Node( it, NULL ); // the node to be inserted
	Node * tempPtr = myFirst;
	Node * holdNext = NULL;
	if(mySize == 0){
		myFirst = newPtr;
		myLast = newPtr;
		mySize++;
		return;
	}
	if(index == 0){
		newPtr->myNext = myFirst;
		myFirst = newPtr;
		mySize++;
		return;
	}
	unsigned num = 0;
	while ( true ){
		if( num+1 == index ){
			holdNext = tempPtr->myNext;
			tempPtr->myNext = newPtr;
			newPtr->myNext = holdNext;
			break;
		}else{
			num++;
			tempPtr = tempPtr->myNext;
		}
	}
	mySize++;
	if( myLast->myNext != NULL ){
		myLast = myLast->myNext;
	}
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
		out << nodePtr->myItem << "\t"<< flush;
		nodePtr = nodePtr->myNext;
	}
}

/* Written by Bryce Allen
 * writeTo method but modified for conga line symantics.
 * @param out, the ostream we will write into.
 */
template<class Item>
void List<Item>::writeToAlternate( ostream& out ) const{
	Node* nodePtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		out << nodePtr->myItem << "=>"<< flush;
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

/* Written by Bryce Allen
 * Inserts the new name into the list before specific person
 * @param otherPersonsName, the name of the person newName will precede.
 * @param newName, the new name to be inserted into the list
 * @return true if it worked, false if the name does not exist.
 */
template <class Item>
bool List<Item>::insertAfter(const string& otherPersonsName, const string& newName)
{
	unsigned index = 0;
	try {
		index = getIndexOf(otherPersonsName);
	}catch(underflow_error& ue){
		return false;
	}
	insert(newName, index+1);
	return true;
}

/* Written by Bryce Allen
 * Inserts the new name into the list after specific person
 * @param otherPersonsName, the name of the person newName will follow
 * @param newName, the new name to be inserted into the list
 * @return true if it worked, false if the name does not exist.
 */
template <class Item>
bool List<Item>::insertBefore(const string& otherPersonsName, const string& newName)
{
	unsigned index = 0;
	try {
		index = getIndexOf(otherPersonsName);
	}catch(underflow_error& ue){
		return false;
	}
	insert(newName, index);
	return true;
}

/* Written by Bryce Allen
 * Inserts the items in the list in conga-line symantics
 * @param out, the ostream we will insert into
 * @param list, the list of items we want inserted into the ostream
 * @return The ostream
 */
template <class Item>
ostream& operator<<(ostream& out, List<Item>& list){ //List<Item>::	//ostream out;
	list.writeToAlternate(out);
	return out;
}

template <class Item>
List<Item>::~List() {
	Node* first = myFirst;
	Node* next = first;
	while (first != NULL){
		next = first->myNext;
		//first->myItem = 0;
		first->myNext = NULL;
		delete first;
		first = next;
	}
	myFirst = myLast = NULL;
	mySize = 0;
}


#endif /* LIST_H_ */
