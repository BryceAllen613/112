/* Vec.h provides a simple vector class named Vec.
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

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	
	Vec& operator=( const Vec& original );
	unsigned getSize() const { return mySize; }
	void setItem( unsigned index, const Item& it );
	Item getItem( unsigned index ) const;
	void setSize( unsigned newSize );
	bool operator==( const Vec& v2 );
	void writeTo( ostream& out );
	void readFrom( istream& in );

	Item& operator[](unsigned index); 	//Bryce
	const Item& operator[](unsigned index) const; 		//Catherine
	bool operator!=(const Vec& original);
	Vec operator-(const Vec& original);
	void readFrom( string fileName );
	void writeTo(string fileName);

	int operator*(const Vec& original);
	Vec operator+(const Vec& original);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
