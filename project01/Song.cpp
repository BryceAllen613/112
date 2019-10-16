/*
 * Song.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#include "Song.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Song::Song() {
	myTitle = myArtist = "";
	myYear = 0;
}
Song::Song(const string& title, const string& artist, unsigned year){
	myTitle = title;
	myArtist = artist;
	myYear = year;
}
string Song::getTitle() const {
	return myTitle;
}
string Song::getArtist() const {
	return myArtist;
}
unsigned Song::getYear() const {
	return myYear;
}
void Song::readFrom(istream& in){
	getline(in, myTitle);
	getline(in, myArtist);
    string yearString;
	getline(in, yearString);
	myYear = atoi( yearString.c_str() );
}
void Song::writeTo(ostream& out) const {
	out << myTitle << '\n'
		<< myArtist << '\n'
		<< myYear  << '\n';
}

bool Song::operator==(const Song& song2) const{
	if( myTitle==song2.getTitle() ){
		if( myArtist == song2.getArtist() ){
			if( myYear == song2.getYear() ){
				return true;
			}else{return false;}
		}else{return false;}
	}else{return false;}
}


