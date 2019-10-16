/*
 * PlayList.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#include "PlayList.h"
#include <fstream>
#include <cassert>
#include "Song.h"
using namespace std;

PlayList::PlayList(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Song s;
	string separator;
	while (true){
		s.readFrom(fin);
		if( !fin ){break;}
		getline(fin, separator);
		mySongs.push_back(s);

	}
	fin.close();
}

unsigned PlayList::getNumSongs() const{
	return mySongs.size();
}

vector<Song> PlayList::searchByArtist(const string& artist){
	vector<Song> v;

	for(unsigned i = 0; i<mySongs.size(); i++){
		if(mySongs[i].getArtist().find(artist)!= string::npos){
			v.push_back(mySongs[i]);
		}
	}
	return v;
}

