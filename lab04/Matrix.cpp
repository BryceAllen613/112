/* Matrix.cpp defines Matrix class methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

typedef double Item;

Matrix::Matrix(){
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns){
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for(unsigned i = 0; i < rows; i++){
		myVec[i].setSize(columns);
	}
}

Matrix::Matrix(const Matrix& m){
	myRows = m.myRows;
	myColumns = m.myColumns;
	myVec = m.myVec;
}

const Vec<Item>& Matrix::operator[](unsigned i)const{
	return myVec[i];
}

Vec<Item>& Matrix::operator[](unsigned i){
	return myVec[i];
}

unsigned Matrix::getColumns()const{
	return myColumns;
}

unsigned Matrix::getRows()const{
	return myRows;
}

bool Matrix::operator==(const Matrix& m2) const {
	if( myRows != m2.getRows() || myColumns != m2.getColumns() ){
		return false;
	}else { return myVec == m2.myVec; }
}
