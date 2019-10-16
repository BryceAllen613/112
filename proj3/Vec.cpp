/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:Bryce Allen & Catherine DeJager
 * Date:9-26-17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: Bryce Allen and Catherine DeJager, for CS 112 project 3 at Calvin College.
 *
 * Bryce Allen:
 * Retrieve [] operator
 * != operator
 * subtraction (-) operator
 * readFrom() method
 *
 * Catherine DeJager:
 * assignment [] operator
 * + operator
 * * operator
 * writeTo() method
 */
 
#include "Vec.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

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
/* Finds the item of the specified index of the vector.
 * Written By Bryce Allen and Catherine DeJagger
 * @param index, the position of the item to be returned.
 * @return The item at postition index
 */
Item& Vec::operator[](unsigned index){
	if( index>=mySize ){
		throw range_error("The index is too large.");
	}
	return myArray[index];
}

/* assignment subscript operator
 * Written by Catherine Dejager
 * @param index, the position of the item in the vector we want to update
 * @return The Item to be updated.
 */
const Item& Vec::operator[](unsigned index) const {
	if (index < mySize){
		return myArray[index];
	}
	else {
		throw range_error("Out of range: index must be less than Vec.mySize");
	}
}

/*Subtracts Vectors from Vector.
 * Written by Bryce Allen
 * @param original, the Vec to be subtracted.
 * @return the Vector leftover after subtraction.
 */
Vec Vec::operator-(const Vec& original){
	if(original.mySize!=mySize){throw invalid_argument("Vecs must be of the same size to subtract.");}
	Vec result( original.getSize() );
	for( unsigned i = 0; i<mySize; i++ ){
		Item t = myArray[i]-original.myArray[i];
		result.setItem(i, t);
	}
	return result;
}
/*Tests if two Vecs are equal.
 * Written by Bryce Allen
 * @param original, the Vec to be compared to 'this' Vec.
 * @return true if the Vecs are not equal, false if they are.
 */
bool Vec::operator!=( const Vec& original ){
	if( mySize!=original.mySize ){return true;}
	for( unsigned i = 0; i<mySize; i++){
		if( myArray[i]!=original.myArray[i] ){
			return true;
		}
	}
	return false;
}
/*
 * Reads values from a file and stores them in myArray.
 * Written By Bryce Allen
 * @param: fileName, the name of the file from which we will obtain the values.
 */
void Vec::readFrom( string fileName ) {
	ifstream fin1(fileName.c_str() );
	string temp;
	getline( fin1, temp );
	int numValues = (int)atoi(temp.c_str());
	mySize = numValues;
	Item * newArray = new Item[numValues]();
	for( unsigned i = 0; i<numValues; i++ ){
		string t;
		getline( fin1, t );
		newArray[i] = (Item)atoi(t.c_str());
	}
	delete[] myArray;
	myArray = newArray;
	fin1.close();
}
/*
 * Write the contents of the Vec to a file with the name fileName.
 * Written by Catherine DeJagger
 * @params: string fileName
 * Precondition:
 * Postcondition: The first line is the size of the Vec. Each line afterwards contains the next value in the Vec.
 * Retrieve:
 * Return:
 */
void Vec::writeTo(string fileName) {
	ofstream fout(fileName.c_str());
    //assert(fout.is_open());
	fout << mySize << '\n';
	for (unsigned i=0; i<mySize; i++) {
		fout << myArray[i] << '\n';
	}
}
/* Dot product: returns the sum of the products of each item in the Vecs.
 * Written by Catherine DeJagger
 * @params: const Vec& original
 * Precondition:
 * Postcondition:
 * Retrieve:
 * Return: an int equal to the dot product of both Vecs
 */
int Vec::operator*(const Vec& original) {
	if (mySize != original.mySize) {
			throw invalid_argument("Vectors of different sizes cannot be added together.");
		}
	else {
		int product = 0;
		for (unsigned i = 0; i < mySize; i++) {
			product += (myArray[i] * original.myArray[i]);
		}
		return product;
	}
}
/* Vector addition: adds each item in the Vec together.
 * Written by Catherine DeJagger
 * @params: const Vec& original
 * Precondition:
 * Postcondition:
 * Retrieve:
 * Return: a Vec containing the result of adding this Vec and the other Vec together.
 */
Vec Vec::operator+(const Vec& original) {
	Vec result(original.getSize());
	if (mySize != original.mySize) {
		throw invalid_argument("Vectors of different sizes cannot be added together.");
	}
	else {

		for (unsigned i = 0; i < mySize; i++) {
			result.setItem(i, (myArray[i] + original.myArray[i])); // TODO change setItem to subscript operator
		}
		return result;
	}
}
