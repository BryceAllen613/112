/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:Bryce Allen
 * Date:9-26-17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: Bryce Allen, for CS 112 lab 3 at Calvin College.
 */
 
#include "Vec.h"
#include <stdexcept>
#include <iostream>

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}
Vec::Vec(unsigned size){

	mySize = size;
	if(size>0){
		myArray = new Item[size]();
	}else{ myArray = NULL; }
}
Vec::Vec(const Vec& original){
	mySize = original.mySize;
	if(original.mySize>0){
			myArray = new Item[original.mySize]();
			for(unsigned i = 0; i<original.mySize; i++ ){
				myArray[i] = original.myArray[i];
			}
		}else{ myArray = NULL; }
}

Vec::~Vec() {
	mySize = 0;
	delete[] myArray; myArray = NULL;
}

Vec& Vec::operator=( const Vec& original ){
	if ( myArray == original.myArray ) return *this;
	mySize = original.mySize;
	if(original.mySize>0){
		myArray = new Item[original.mySize]();
			for(unsigned i = 0; i<original.mySize; i++ ){
				myArray[i] = original.myArray[i];
			}
	}else{ myArray = NULL; }
	return *this;
}

void Vec::setItem( unsigned index, const Item& it ){
	if( index>= mySize ){ throw range_error("index is out of range."); }
	else{ myArray[index] = it; }
}

Item Vec::getItem(unsigned index) const {
	if( index>= mySize ){ throw range_error("index is out of range."); }
	else{ return myArray[index]; }
}

void Vec::setSize( unsigned newSize ){
	if( mySize == newSize ){}
	else if( newSize == 0 ){
		delete[] myArray; myArray = NULL;
		mySize = 0;
	}else{
		Item * b = new Item[newSize]();
		if( mySize<newSize ){
			for( unsigned i = 0; i<mySize; i++ )
			{b[i] = myArray[i];}
		}else{
			for( unsigned i = 0; i<newSize; i++ )
			{b[i] = myArray[i];}
		}
		mySize = newSize;
		delete[] myArray;
		myArray = b;
	}
}

bool Vec::operator==( const Vec& v2 ){
	if( mySize == v2.mySize ){
		for( unsigned i = 0; i<mySize; i++){
			if( myArray[i] == v2.myArray[i] ){}else{ return false; }
		}
		return true;
	}else{ return false; }
}

void Vec::writeTo( ostream& out ) {
	for( unsigned i = 0; i<mySize; i++ ){
		out<< myArray[i]<< " "<< flush;
	}
}

void Vec::readFrom( istream& in ) {
	for( unsigned i = 0; i<mySize; i++){
		in>> myArray[i];
	}
}
