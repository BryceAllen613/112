/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Bryce Allen
 * Date: 10-31-17
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

//typedef int Item;
template<class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack<Item>& original);
	~Stack();
	Stack<Item>& operator=(const Stack<Item>& original);
	
	bool isEmpty() const;
	bool isFull() const;
	void push(Item it);
	Item& peekTop() const;
	Item& pop();

	unsigned getSize() const { return mySize; }
	unsigned getCapacity() const { return myCapacity; }
	void setCapacity(int newCapacity);

protected:
	void makeCopyOf(const Stack<Item>& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
	if( capacity == 0 ){
		throw StackException("Stack(capacity)", "cannot set stack to size 0.");
	}else{
		mySize = 0;
		myCapacity = capacity;
		myArray = new Item[capacity];
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* Written by Bryce Allen
 * Tells user if stack is empty.
 * @return true if the Stack is empty, false if otherwise.
 */
template<class Item>
bool Stack<Item>::isEmpty() const{
	return (mySize == 0);
}

/* Written by Bryce Allen
 * Tells user if stack is full.
 * @return true if the Stack is full, false if otherwise.
 */
template<class Item>
bool Stack<Item>::isFull() const{
	return (mySize == myCapacity);
}

/* Written by Bryce Allen
 * pushes an item onto the stack.
 * @param it, the item to pe pushed.
 */
template<class Item>
void Stack<Item>::push(Item it){
	if( isFull() ){
		throw StackException("push()", "stack is full.");
	}else{
		myArray[mySize] = it;
		mySize ++;
	}
}

/* Written by Bryce Allen
 * Allows us to "peek" at the top of this stack.
 * @return An item&, representing the top of the stack.
 */
template<class Item>
Item& Stack<Item>::peekTop() const{
	if ( isEmpty() ){
		throw StackException("peekTop()", "stack is empty.");
	}else{
		return myArray[mySize-1];
	}
}

/* Written by Bryce Allen
 * removes the top item in this stack.
 * @return The top item of the stack (also removes it from stack).
 */
template<class Item>
Item& Stack<Item>::pop(){
	if( isEmpty() ){
		throw StackException("isEmpty()", "stacj us empty");
	}else{
		mySize--;
		return myArray[mySize];
	}
}

/* Written by Bryce Allen
 * Resets the capacity of this Stack.
 * @param newCapacity, the new capacity of our stack
 */
template<class Item>
void Stack<Item>::setCapacity( int newCapacity ){
	if( newCapacity < mySize ){
		throw StackException("setCapacity(newCapacity)", "newCapacity is less than current size");
	}else if( newCapacity == mySize ){
		return;
	}else{
		Item* newPtr = new Item[newCapacity];
		for( unsigned i = 0; i < mySize; i++ ){
			newPtr[i] = myArray[i];
		}
		delete myArray;
		myArray = newPtr;
		myCapacity = newCapacity;
	}
}


#endif

