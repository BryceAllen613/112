/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>      // memcpy()
using namespace std;

template<class Item>

class ArrayQueue {
public:
	ArrayQueue(unsigned i);
	ArrayQueue(const ArrayQueue<Item>& original);
	virtual ~ArrayQueue();
	ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	Item& getFirst() const;
	Item& getLast() const;
	void append(const Item& it);
	Item remove();
	void setCapacity(unsigned newCapacity);
protected:
	virtual void makeCopyOf(const ArrayQueue<Item>& original);
private:
	friend class ArrayQueueTester;
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

	friend class ArrayQueueTester;
};

template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned i){
	if( i == 0 ){ throw QueueException("ArrayQueue(unsigned i)","queue can't be capacity 0."); }
	myCapacity = i;
	mySize = 0;
	myFirstIndex = 0;
	myLastIndex = i-1;
	myArrayPtr = new Item[myCapacity];
}

template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

template<class Item>
Item& ArrayQueue<Item>::getFirst() const {
	if( mySize == 0 ){ throw EmptyQueueException("getFirst()"); }
	else{ return myArrayPtr[myFirstIndex]; }
}

template<class Item>
Item& ArrayQueue<Item>::getLast() const {
	if( mySize == 0 ){ throw EmptyQueueException("getLast()"); }
	else{ return myArrayPtr[myLastIndex]; }
}

template<class Item>
void ArrayQueue<Item>::append(const Item& it){
	if( isFull() ){ throw FullQueueException("append()"); }
	else{
		myLastIndex = (myLastIndex+1)%myCapacity;
		myArrayPtr[myLastIndex] = it;
		mySize++;
	}
}

template<class Item>
Item ArrayQueue<Item>::remove(){
	if( isEmpty() ){ throw EmptyQueueException("remove"); }
	else{
		Item store = myArrayPtr[myFirstIndex];
		//myArrayPtr[myFirstIndex] = NULL;
		myFirstIndex = (myFirstIndex+1)%myCapacity;
		mySize--;
		return store;
	}
}

/*
 * sets a new capacity to this array based queue.
 * @param newCapacity, the new capacity of the queue.
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity){
	if( newCapacity == 0 || newCapacity < mySize )
	{ throw EmptyQueueException("setCapacity()"); }
	Item* newArrayPtr = new Item[newCapacity];
	unsigned x = myFirstIndex;
	for( unsigned i = 0; i < mySize; i++ ){
		newArrayPtr[i] = myArrayPtr[(x % myCapacity)];
		x++;
	}
	delete [] myArrayPtr;
	myArrayPtr = newArrayPtr;
	myCapacity = newCapacity;
	myFirstIndex = 0;
	myLastIndex = mySize-1;
}

template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

#endif /*ARRAY_QUEUE_H_*/
