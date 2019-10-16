/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec<Item>& operator=( const Vec<Item>& original );
	unsigned getSize() const { return mySize; }
	void setItem( unsigned index, const Item& it );
	Item getItem( unsigned index ) const;
	void setSize( unsigned newSize );
	bool operator==( const Vec<Item>& v2 ) const;
	void writeTo( ostream& out );
	void readFrom( istream& in );
	bool operator!=( const Vec<Item>& original );
	void readFrom( string fileName );
	void writeTo(string fileName);
	int operator*(const Vec<Item>& original);
	Vec<Item> operator+(const Vec<Item>& original);
	Vec<Item> operator-(const Vec<Item>& original);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

template<class Item>
Vec<Item>::Vec(unsigned size){

	mySize = size;
	if(size>0){
		myArray = new Item[size]();
	}else{ myArray = NULL; }
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original){
	mySize = original.mySize;
	if(original.mySize>0){
			myArray = new Item[original.mySize]();
			for(unsigned i = 0; i<original.mySize; i++ ){
				myArray[i] = original.myArray[i];
			}
		}else{ myArray = NULL; }
}

template<class Item>
Vec<Item>::~Vec() {
	mySize = 0;
	delete[] myArray; myArray = NULL;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=( const Vec<Item> & original ){
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

template<class Item>
void Vec<Item>::setItem( unsigned index, const Item& it ){
	if( index>= mySize ){ throw range_error("index is out of range."); }
	else{ myArray[index] = it; }
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if( index>= mySize ){ throw range_error("index is out of range."); }
	else{ return myArray[index]; }
}

template<class Item>
void Vec<Item>::setSize( unsigned newSize ){
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

template<class Item>
bool Vec<Item>::operator==( const Vec<Item>& v2 )const{
	if( mySize == v2.mySize ){
		for( unsigned i = 0; i<mySize; i++){
			if( myArray[i] == v2.myArray[i] ){}else{ return false; }
		}
		return true;
	}else{ return false; }
}

template<class Item>
void Vec<Item>::writeTo( ostream& out ) {
	for( unsigned i = 0; i<mySize; i++ ){
		out<< myArray[i]<< " "<< flush;
	}
}

template<class Item>
void Vec<Item>::readFrom( istream& in ) {
	for( unsigned i = 0; i<mySize; i++){
		in>> myArray[i];
	}
}

template<class Item>
bool Vec<Item>::operator!=( const Vec<Item>& original ){
	if( mySize!=original.mySize ){return true;}
	for( unsigned i = 0; i<mySize; i++){
		if( myArray[i]!=original.myArray[i] ){
			return true;
		}
	}
	return false;
}

template<class Item>
void Vec<Item>::readFrom( string fileName ) {
	ifstream fin1( fileName.c_str() );
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

template<class Item>
void Vec<Item>::writeTo(string fileName) {
	ofstream fout(fileName.c_str());
    //assert(fout.is_open());
	fout << mySize << '\n';
	for (unsigned i=0; i<mySize; i++) {
		fout << myArray[i] << '\n';
	}
}

template<class Item>
int Vec<Item>::operator*(const Vec<Item>& original) {
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

template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& original) {
	Vec result(original.getSize());
	if (mySize != original.mySize) {
		throw invalid_argument("Vectors of different sizes cannot be added together.");
	}
	else {

		for (unsigned i = 0; i < mySize; i++) {
			result.setItem(i, (myArray[i] + original.myArray[i]));
		}
		return result;
	}
}

template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& original){
	if(original.mySize!=mySize){throw invalid_argument("Vecs must be of the same size to subtract.");}
	Vec result( original.getSize() );
	for( unsigned i = 0; i<mySize; i++ ){
		Item t = myArray[i]-original.myArray[i];
		result.setItem(i, t);
	}
	return result;
}

template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index < mySize){
		return myArray[index];
	}
	else {
		throw range_error("Out of range: index must be less than Vec.mySize");
	}
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index){
	if( index>=mySize ){
		throw range_error("The index is too large.");
	}
	return myArray[index];
}
#endif /*VEC_H_*/
