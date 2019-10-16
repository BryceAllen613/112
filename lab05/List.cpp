/*
 * List.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: bda5
 */

#include "List.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;
typedef double Item;

List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

List::List(const List& original){
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

List::Node::Node(){
	myItem = 0.0;
	myNext = NULL;
}

List::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}

Item List::getFirst(){
	if(myFirst==NULL){
		throw underflow_error("Empty List.");
	}
	return myFirst->myItem;
}

Item List::getLast(){
	if(myLast==NULL){
		throw underflow_error("Empty List.");
	}
	return myLast->myItem;
}

void List::append(Item it){
	Node* nodePtr = new Node(it, NULL);
	if(mySize == 0){
		myFirst = nodePtr;
	}else{
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize++;
}

List& List::operator=(const List& original){
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

List::~List() {
	Node* first = myFirst;
	Node* next = first;
	while (first != NULL){
		next = first->myNext;
		first->myItem = 0;
		first->myNext = NULL;
		delete first;
		first = next;
	}
	myFirst = myLast = NULL;
	mySize = 0;
}
