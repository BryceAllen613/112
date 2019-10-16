/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

ArrayQueue::ArrayQueue(unsigned i){
	if( i == 0 ){ throw QueueException("ArrayQueue(unsigned i)","queue can't be capacity 0."); }
	myCapacity = i;
	mySize = 0;
	myFirstIndex = 0;
	myLastIndex = i-1;
	myArrayPtr = new Item[myCapacity];
}

ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

unsigned ArrayQueue::getSize() const {
	return mySize;
}

Item& ArrayQueue::getFirst() const {
	if( mySize == 0 ){ throw EmptyQueueException("getFirst()"); }
	else{ return myArrayPtr[myFirstIndex]; }
}

Item& ArrayQueue::getLast() const {
	if( mySize == 0 ){ throw EmptyQueueException("getLast()"); }
	else{ return myArrayPtr[myLastIndex]; }
}

void ArrayQueue::append(const Item& it){
	if( isFull() ){ throw FullQueueException("append()"); }
	else{
		myLastIndex = (myLastIndex+1)%myCapacity;
		myArrayPtr[myLastIndex] = it;
		mySize++;
	}
}

Item ArrayQueue::remove(){
	if( isEmpty() ){ throw EmptyQueueException("remove"); }
	else{
		Item store = myArrayPtr[myFirstIndex];
		//myArrayPtr[myFirstIndex] = NULL;
		myFirstIndex = (myFirstIndex+1)%myCapacity;
		mySize--;
		return store;
	}
}


ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}


