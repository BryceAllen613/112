/*
 * PlaylistTester.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */
#include "SongTester.h"
#include "PlaylistTester.h"
#include "PlayList.h"
#include<iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

PlaylistTester::PlaylistTester() {


}

PlaylistTester::PlaylistTester(const string& fileName) {


}
void PlaylistTester::runTests() {
	cout<< "\nTesting class Playlist..." << endl;
	testConstructors();
	testSearchByArtist();
	cout<< "all tests passed"<< endl;
}

void PlaylistTester::testConstructors() {
      cout << "- constructors..." << flush;
      PlayList pList("testSongs.txt");
      assert( pList.getNumSongs() == 4 );
      cout << " 0 " << flush;
      testSearchByArtist();
      cout << " Passed!" << endl;
   }

void PlaylistTester::testSearchByArtist() {
	cout<< "- searchByArtist()..."<< flush;
	PlayList pList("testSongs.txt");

	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert( searchResult.size()==0 );
	cout<< " 0 "<< flush;

	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() ==1 );
	assert( searchResult[0].getTitle()=="Let It Be" );
	cout<< " 1 " << flush;

	searchResult = pList.searchByArtist("Beatles");
	assert(searchResult.size()==2);
	assert( searchResult[0].getTitle()=="Let It Be" );
	//assert( searchResult[0].getTitle()=="Penny Lane" );
	cout<<" 2 "<< flush;

	cout<< " PlayList class passed "<< endl;

}
