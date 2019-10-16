/*
 * Song.h
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
using namespace std;

class Song {
public:
	Song(const string& title, const string& artist, unsigned year);
	Song();
	void readFrom(istream& in);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void writeTo(ostream& out) const;
	bool operator==(const Song& song2) const;

private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
