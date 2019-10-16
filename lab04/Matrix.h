/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	Matrix(const Matrix& m);
	unsigned getColumns() const;
	unsigned getRows() const;
	const Vec<Item>& operator[](unsigned i) const;
	Vec<Item>& operator[](unsigned i);
	bool operator==(const Matrix& m2) const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};


#endif
