/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Bryce Allen
 * Date:11-29-17
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template<class Item>

class BST {
public:

	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	unsigned getHeight() const;
	void insert( Item it );
    bool contains( Item it ) const;
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();
            unsigned getHeight() const;
            void insert( Item item );
            bool contains( Item item ) const;
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template<class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

/* Written By Bryce Allen
 * Returns the height of this of the BST from a certain Node.
 * @return an unsigned integer representing the height from a certain Node.
 */
template<class Item>
unsigned BST<Item>::Node::getHeight() const {
	if( myLeft == NULL && myRight == NULL ) return 1;
	if( myLeft != NULL && myRight == NULL ) return 1 + (myLeft->getHeight());
	if( myLeft == NULL && myRight != NULL ) return 1 + (myRight->getHeight());
	if( myLeft != NULL && myRight != NULL )
	{
		unsigned l = 1 + (myLeft->getHeight());
		unsigned r = 1 + (myRight->getHeight());
		if( l > r ) return l;
		else return r;
	}
	else return 1;

}

/* Written By Bryce Allen
 * Returns the height of this BST as an unsigned integer
 * @return an unsigned integer representing the height.
 */
template<class Item>
unsigned BST<Item>::getHeight() const{
	unsigned numItems = getNumItems();
	if( numItems == 0 ) return 0;
	else return myRoot->getHeight();
}

template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::traverseInorder() {
	if( !isEmpty() ){
		myRoot->traverseInorder();
	}
}

template<class Item>
void BST<Item>::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::traversePostorder(){
	if( !isEmpty() ){
		myRoot->traversePostorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePostorder(){
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
	processItem();
}

template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

template<class Item>
void BST<Item>::insert( Item it ) {
	if( myNumItems == 0 ) {
		 myRoot = new Node(it);
		 myNumItems++;
	}else{
		try{
			myRoot->insert(it);
			myNumItems++;
		} catch ( Exception e ){
			throw e;
		}
	}
}

template<class Item>
void BST<Item>::Node::insert( Item item ){
	if( item < myItem ){
		if( myLeft == NULL ){
			myLeft = new Node(item);
		}else{
			myLeft->insert(item);
		}
	}else if( item > myItem ){
		if( myRight == NULL ){
			myRight = new Node(item);
		}else{
			myRight->insert(item);
		}
	}else{ throw Exception("Node::insert()", "item is equal to myItem."); }
}

template<class Item>
bool BST<Item>::contains( Item it ) const {
	if( myNumItems == 0 ) return false;
	else return myRoot->contains( it );
}

template<class Item>
bool BST<Item>::Node::contains( Item item ) const {
	if( item < myItem ){
		if ( myLeft == NULL ) return false;
		else return myLeft->contains(item);
	}else if( item > myItem ){
		if( myRight == NULL ) return false;
		else return myRight->contains(item);
	}else{ return true; }
}


#endif /*BST_H_*/

