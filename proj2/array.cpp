/* array.cpp defines "C style" array operations
 * Name:Bryce Allen
 * Date:9-25-17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * edited by: Bryce Allen, for cs 112, project 2, at Calvin College.
 */
#include "array.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
/*
 * Initializes the dynamic array with values from 1 to 'size'
 * Precondition: The dynamic array must have been declared and initialized to be 'size' long.
 * @param a: The dynamic array to be initialized.
 * @param size: The size of our dynamic array.
 */
void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 /*
  * Prints all values in the dynamic array.
  * @param a: The dynamic array.
  * @param size: The size of the array.
  */
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		
/*
 * Finds the average of the values of the dynamic array.
 * @param a: The dynamic array from which we will obtain our values.
 * @param size: The size of the dynamic array.
 */
double average(double *a, unsigned size) {
	double sum=0;
	for(unsigned i = 0; i<size; i++){
		sum+=*a;
		a++;
	}
	return sum/size;
}

/*
 * Computes the sum of the values in the array
 * @return The sum of the values in an array passed as a parameter.
 * @param The array.
 * @param The size of the array.
 */
double sum(double *a, int size){
	double sum=0;
	for(unsigned i = 0; i<size; i++){
		sum+=*a;
		a++;
	}
	return sum;
}
/*
 *reads data from arrayData.txt and stores it in *a
 *Precondition: istream in has been initialized to read in from a file.
 *@param in: The in stream from which we will get the data from the file.
 *@param a: The dynamic array which we will read values into.
 *@param size: The size of the dynamic array.
 */
void read(istream& in, double *a, int size){
	for(unsigned i = 0; i<size; i++){
		string t;
		getline(in,t);
		*a = (double)atoi( t.c_str() );
		a++;
	}
}
/*
 * Fills the dynamic array with numbers from a file.
 * @param fileName: The name of the file that conatains our values to be stored
 * @param a: our dynamic array to be filled.
 * @param numValues: the number of values we want stored.
 */
void fill(const string & fileName, double *&a, int &numValues){
	ifstream fin(fileName.c_str());
	assert( fin.is_open() );
	string temp;
	getline(fin,temp);
	numValues = (int)atoi( temp.c_str() );
	double *b = new double[numValues]();
	for( unsigned i = 0; i<numValues; i++ ){
		string t;
		getline(fin,t);
		b[i] = (double)atoi( t.c_str() );
	}
	delete[] a; a=b;
	fin.close();
}
/*
 * resizes our dynamic array.
 * @param a: our dynamic array to be resized.
 * @param oldSize: The old size of our array.
 * @param newSize: Our desired size of the array.
 */
void resize(double *&a, int oldSize, int newSize){
		double *b = new double[newSize]();
		int t = oldSize;
		if(oldSize>newSize){t = newSize;}
		for( unsigned i = 0; i<t; i++ ){
			b[i]=a[i];
		}
		delete [] a;
		a = b;
}
/*
 * Takes two dynamic arrays and attaches them together by storing them in a third.
 * @param a1: The first dynamic array.
 * @param size1: The size of the first dynamic array.
 * @param a2: The second dynamic array.
 * @param size2: The size of the second dynamic array.
 * @param a3: The third dynamic array.
 * @param size3: The size of the third dynamic array.
 */
void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3){
	size3 = size1+size2;
	double *b = new double[size3]();
	for( unsigned i = 0; i<size1; i++ ){
		b[i]=a1[i];
	}
	for(unsigned i = 0; i<size2; i++ ){
		b[size1+i]=a2[i];
	}
	delete[] a3;
	a3=b;
}

