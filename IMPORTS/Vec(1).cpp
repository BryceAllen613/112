/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Catherine DeJager
 * Date: 9/26/17
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if (mySize == 0) {
		myArray = NULL;
	}
	else {
	myArray = new Item[mySize](); //dynamically allocate an array of mySize values of type item
			//and store the address of the array in myArray and set each of the Items in that array to 0
	}
}


Vec::Vec(const Vec & original) {
	mySize = original.mySize;
	if (mySize==0) {
		myArray = NULL;
	}
	else {
		myArray = new Item[mySize];
		for (unsigned i=0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
}

Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize>0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize>0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i=0; i<mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index < mySize){
		myArray[index] = it;
	}
	else {
		throw range_error("Out of range: index must be less than Vec.mySize");
	}
}

Item Vec::getItem(unsigned index) const {
	if (index < mySize){
		return myArray[index];
	}
	else {
		throw range_error("Out of range: index must be less than Vec.mySize");
	}
}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			mySize = 0;
			myArray = NULL;
		}
		else {
			Item * newArray = new Item [newSize](); //create a new array and set all the values to 0
			if (mySize < newSize) {
				for (unsigned i=0; i < mySize; i++) {
					newArray[i] = myArray[i]; //copy over all values from myArray
				}
			}
			else {
				for (unsigned i=0; i < newSize; i++) {
					newArray[i] = myArray[i]; //copy over values from myArray until the length of newArray == newSize
				}
			}
			delete [] myArray;
			myArray = newArray;
			mySize = newSize;
		}
	}
}

bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.mySize) { //if different size the vectors cannot be equal
		return false;
	}
	else {
		for (unsigned i=0; i<mySize; i++) {
			if(myArray[i] != v2.myArray[i]) {
				return false;
			}
		}
		return true; //if none of the values are different the vectors are equal;
	}
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i=0; i<mySize; i++) {
		out << myArray[i] << "\n";
	}
}

void Vec::readFrom(istream& in) {
	for (unsigned i=0; i<mySize; i++) {
		in >> myArray[i];
	}
}
/* Subscript operator for assignment
 * @params: unsigned index
 * Precondition:
 * Postcondition:
 * Retrieve:
 * Return:
 */
Item& Vec::operator[](unsigned index) {
	if (index < mySize){
		return myArray[index];
	}
	else {
		throw range_error("Out of range: index must be less than Vec.mySize");
	}
}

/* Write the contents of the Vec to a file with the name fileName.
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
		//Vec result(mySize);
		for (unsigned i = 0; i < mySize; i++) {
			result.setItem(i, (myArray[i] + original.myArray[i])); // TODO change setItem to subscript operator
		}
		return result;
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

Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}
