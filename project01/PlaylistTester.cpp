/*
 * PlaylistTester.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */
#include "SongTester.h"
#include "PlaylistTester.h"
#include "PlayList.h"
#include <iostream>
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
	testSearchByTitlePhrase();
	testSearchByYear();
	testAddSong();
	cout<< "all tests passed"<< endl;
}

void PlaylistTester::testConstructors() {
      cout << "- constructors..." << flush;
      PlayList pList("testSongs.txt");
      assert( pList.getNumSongs() == 4 );
      cout << " 0 " << flush;

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

void PlaylistTester::testSearchByYear(){
	cout<< "Testing searchByYear()... "<< flush;
	PlayList p1("testSongs.txt");
	vector<Song> searchResult = p1.searchByYear(2015);

	//p1.searchByYear(2015);
	assert( searchResult.size()==0 );
	cout << " 0 "<< flush;

	searchResult = p1.searchByYear(2012);
	assert( searchResult.size()==1 );
	cout<< " 1 " << flush;

	searchResult = p1.searchByYear(1967);
	assert( searchResult.size()==2 );
	cout<< " 2 " << flush;

	cout<< " Search by Year is working! "<< endl;
}

void PlaylistTester::testSearchByTitlePhrase(){
	cout<< "Testing searchByTitlePhrase()... "<< flush;
	PlayList p1("testSongs.txt");

	vector<Song> searchResult = p1.searchByTitlePhrase("The Scientist");
	assert( searchResult.size()==0 );
	cout << " 0 "<< flush;

	searchResult = p1.searchByTitlePhrase("Let It Be");;
	assert( searchResult.size()==2 );
	cout<< " 1 " << flush;

	searchResult = p1.searchByTitlePhrase("Call Me Maybe");;
	assert( searchResult.size()==1 );
	cout<< " 2 " << flush;

	cout<< " Search by title is working! "<< endl;
}

void PlaylistTester::testAddSong(){
	Song t("The Scientist", "Coldplay", 2002);
	PlayList p1("testSongs.txt");
	cout<< "Testing addSong()..."<< endl;

	p1.addSong(t);
	vector<Song> searchResult = p1.searchByTitlePhrase("The Scientist");
	assert( searchResult.size()==1 );
	cout<< " song added successfully..."<< endl;

	p1.removeSong(t);
	searchResult = p1.searchByTitlePhrase("The Scientist");
	assert( searchResult.size()==0 );
	cout<< " song removed successfully..."<< endl;

	cout<< " addSong() and removeSong() both work! "<< endl;
}
