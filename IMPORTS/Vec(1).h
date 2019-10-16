/* Vec.h provides a simple vector class named Vec.
 * Student Name: Catherine DeJager
 * Date: 9/26/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <fstream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	unsigned getSize() const { return mySize; }
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index); // TODO subscript operator write function
	bool operator!=(Vec& v2); // TODO partner will write != operator
	void readFrom(string fileName); // TODO parnter will write readFrom
	void writeTo(string fileName); // TODO test writeTo, readFrom method needed first
	Vec operator+(const Vec& original); // TODO get + operator to work
	int operator*(const Vec& original);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester; //grants VecTester access to all private parts
};

#endif /*VEC_H_*/
