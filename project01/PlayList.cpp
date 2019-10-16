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

	//nt.stop();
	for(unsigned i = 0; i<mySongs.size(); i++){
		if(mySongs[i].getArtist().find(artist)!= string::npos){
			v.push_back(mySongs[i]);
		}
	}
	return v;
}


vector<Song> PlayList::searchByYear(unsigned year){
	vector<Song> v;
	for(unsigned i = 0; i<mySongs.size(); i++){
		if(mySongs[i].getYear()==year){v.push_back(mySongs[i]);}
	}
	return v;
}

vector<Song> PlayList::searchByTitlePhrase(const string& title){
	vector<Song> v;
	for(unsigned i = 0; i<mySongs.size(); i++){
			if(mySongs[i].getTitle()==title){v.push_back(mySongs[i]);}
		}
	return v;
}

void PlayList::addSong(const Song& newSong){
	mySongs.push_back(newSong);
}
void PlayList::removeSong(const Song& aSong){
	for( unsigned i = 0; i<mySongs.size(); i++ ){
		//if( aSong == mySongs[i] ){mySongs.erase(i);break;}
	}
}
