/* Joel C. Adams, for CS 112 at Calvin College.
 *
 * Edited by Bryce Allen and Alex Williams
 *
 * Written by Bryce Allen:
 * != operator
 * + operator
 * readFrom(istream)
 * writeTo(string)
 *
 * Written by Alex Williams:
 * - operator
 * writeTo(ostream)
 * readFrom(string)
 * getTranspose()
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

//typedef double Item;
template <class Item>

class Matrix{
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	Matrix(const Matrix& m);
	unsigned getColumns() const;
	unsigned getRows() const;
	const Vec<Item>& operator[](unsigned i) const;
	Vec<Item>& operator[](unsigned i);
	bool operator==(const Matrix<Item>& m2) const;
	bool operator!=(const Matrix<Item>& m2) const;
	Matrix<Item> operator+(Matrix<Item>& m2);
	void readFrom(istream& cin);
	void writeTo(string fileName) const;
	void readFrom(string fileName);
	Matrix<Item> getTranspose();
	Matrix<Item> operator-(const Matrix& m2);
	void writeTo(ostream& out)const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

template <class Item>
Matrix<Item>::Matrix(){
	myRows = myColumns = 0;
}

template <class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns){
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for(unsigned i = 0; i < rows; i++){
		myVec[i].setSize(columns);
	}
}

template <class Item>
Matrix<Item>::Matrix(const Matrix<Item>& m){
	myRows = m.myRows;
	myColumns = m.myColumns;
	myVec = m.myVec;
}

template <class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned i)const{
	return myVec[i];
}

template <class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned i){
	return myVec[i];
}

template <class Item>
unsigned Matrix<Item>::getColumns()const{
	return myColumns;
}

template <class Item>
unsigned Matrix<Item>::getRows()const{
	return myRows;
}

template <class Item>
bool Matrix<Item>::operator==(const Matrix& m2) const {
	if( myRows != m2.getRows() || myColumns != m2.getColumns() ){
		return false;
	}else { return myVec == m2.myVec; }
}
/*Written by: Bryce Allen
 * Tests if two matrices are unequal.
 * @param m2, the Matrix to be tested against this matrix.
 * @return false if the Matrices are equal, true if the are not.
 */
template <class Item>
bool Matrix<Item>::operator!=(const Matrix& m2) const{
	if(m2.myVec == myVec &&
			m2.getRows() == myRows &&
			m2.getColumns() == myColumns){
		return false;
	}else{ return true; }
}
/* Written by: Bryce Allen
 * Adds two matrices together.
 * @param m2, the Matrix to be added to 'this' matrix.
 * @return m1, the sum of 'this' Matrix and m2.
 */
template <class Item>
Matrix<Item> Matrix<Item>::operator+(Matrix& m2){
	Matrix m1(m2.getRows(), m2.getColumns());
	if(m2.getRows() != myRows ||
		m2.getColumns() != myColumns){
		throw invalid_argument("Rows and Columns need to be of same size.");
	}
	else{

		for(unsigned r = 0; r < m2.getRows(); r++){
			m1[r] = myVec[r] + m2.myVec[r];
		}
	}
	return m1;
}


/* Written by Bryce Allen
 * Reads from an in stream and puts the values in myVec
 * @param in, the stream to receive the values to be stored.
 */
template <class Item>
void Matrix<Item>::readFrom(istream& in){
	//in >> myRows >> myColumns;
	double val;
	for(unsigned r = 0; r < myRows; r++){
		for(unsigned c = 0; c < myColumns; c++){
			in>>val;
			myVec[r][c] = val;
		}
	}
}

/* Written by Bryce Allen
 * Writes the values stored in myVec to a file.
 * @param fileName, the name of the file to write the values into.
 */
template <class Item>
void Matrix<Item>::writeTo(string fileName) const{
	ofstream fout(fileName.c_str());
	fout << myRows << " " << myColumns << endl;
	for(unsigned r = 0; r < myRows; r++){
		for(unsigned c = 0; c < myColumns; c++){
			fout << myVec[r][c]<< " " << flush;
		}
		fout << endl;
	}
}

//DUMMY FUNCTION MADE BY BRYCE ALLEN IN ORDER TO TEST writeTo(string)
//template <class Item>
//void Matrix<Item>::readFrom(string fileName){
//	ifstream fin(fileName.c_str());
//	fin >> myRows >> myColumns;
//	myVec.setSize(myRows);
//	for(unsigned i = 0; i < myRows; i++){
//		myVec[i].setSize(myColumns);
//	}
//	for(unsigned r = 0; r < myRows; r++){
//		for(unsigned c = 0; c < myColumns; c++){
//			fin >> myVec[r][c];
//		}
//	}
//}

/*Written by: Alex Williams
 * Writes matrices to a stream
 * @param a matrix to write to somewhere
 * @return NONE
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& out)const{
for (unsigned i=0; i<myRows; ++i){
	for (unsigned g=0; g<myColumns; ++g){
		out<< myVec[i][g]<< "\t";
	}
	out<<endl;
}

}
/*Written by: Alex Williams
 * Reads a Matrix out of a file
 * @param Correctly formated file to hold the matrix we are reading
 * @return NONE
 */
template<class Item>
void Matrix<Item>::readFrom(string fileName){
    ifstream fin(fileName.c_str());
    fin >> myRows >> myColumns;
    myVec.setSize(myRows);
    for(unsigned i = 0; i < myRows; i++){
        myVec[i].setSize(myColumns);
    }
    for(unsigned r = 0; r < myRows; r++){
        for(unsigned c = 0; c < myColumns; c++){
            fin >> myVec[r][c];
        }
    }
}
/*Written by: Alex Williams
 * Does subtraction on each of the pairs of items in each matrix
 * @param 2 matrices of the same size
 * @return a matrix containing the difference between each of the cells of the other two
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix& m2){
	Matrix result(myRows,myColumns);
	if(myRows==m2.myRows && myColumns==m2.myColumns){
		for (unsigned i=0; i<myRows;++i){
			for (unsigned g=0; g<myColumns;++g){
				result.myVec[i][g]=myVec[i][g]-m2.myVec[i][g];
			}
		}
		return result;
	}
	else{
		throw invalid_argument("Matrices must be the same size.");
	}

}
/*Written by: Alex Williams
 * Flips a Matrix's columns and rows.
 * @param a Matrix
 * @return a Matrix with the contents flipped on their sides.
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose(){
	Matrix result(myColumns,myRows);
	for (unsigned i=0; i<myColumns;++i){
		for(unsigned g=0; g<myRows;++g){
			result.myVec[i][g]=myVec[g][i];
		}
	}
	return result;
}
#endif
