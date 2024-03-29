/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
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

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
