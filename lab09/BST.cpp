/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 */
 
#include "BST.h"

BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::traverseInorder() {
	if( !isEmpty() ){
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::traversePostorder(){
	if( !isEmpty() ){
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder(){
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
	processItem();
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::insert( Item it ) {
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

void BST::Node::insert( Item item ){
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
	}else{ throw Exception("Node::insert()", "it is equal to myItem."); }
}

bool BST::contains( Item it ) const {
	if( myNumItems == 0 ) return false;
	else return myRoot->contains( it );
}

bool BST::Node::contains( Item item ) const {
	if( item < myItem ){
		if ( myLeft == NULL ) return false;
		else return myLeft->contains(item);
	}else if( item > myItem ){
		if( myRight == NULL ) return false;
		else return myRight->contains(item);
	}else{ return true; }
}
