/*
 * PlayList.h
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include<string>
#include <vector>
#include "Song.h"
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist);
	vector<Song> searchByYear(unsigned year);
	vector<Song> searchByTitlePhrase(const string& title);
	void addSong(const Song& newSong);
	void removeSong(const Song& aSong);
private:
	vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
