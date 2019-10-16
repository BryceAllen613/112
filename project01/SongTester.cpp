/*
 * SongTester.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#include "SongTester.h"
#include <iostream>
#include <cassert>
#include "Song.h"
#include <fstream>
using namespace std;

void SongTester::testConstructors(){
	cout<< "- constructors..."<< flush;
	Song s;
	assert( s.getTitle() == "" );
	assert( s.getArtist()=="");
	assert( s.getYear() == 0);
	cout<< " 0 "<< flush;
	cout<< "passed!"<< endl;

	Song s1("Badge", "Cream", 1969);
	assert( s1.getTitle() == "Badge" );
	assert( s1.getArtist() == "Cream" );
	assert( s1.getYear() == 1969 );
}
void SongTester::runTests() {
	cout << "Testing class Song..." << endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	testOperator();
	cout << "Tests passed!"<< endl;

}
void SongTester::testReadFrom() {
	cout<< "- readFrom()..."<< flush;
	ifstream fin("testSongs.txt");
	assert( fin.is_open() );
	Song s;

	s.readFrom(fin);
	assert( s.getTitle() == "Call Me Maybe" );
    assert( s.getArtist() == "Carly Rae Jepsen" );
    assert( s.getYear() == 2012 );
    cout << " 0 " << flush;

    string separator;
    getline(fin, separator);
    s.readFrom(fin);
    assert( s.getTitle() == "Let It Be" );
    assert( s.getArtist() == "The Beatles" );
    assert( s.getYear() == 1967 );
    cout << " 1 " << flush;

    getline(fin, separator);
    s.readFrom(fin);
    assert( s.getTitle() == "Let It Be" );
    assert( s.getArtist() == "Joan Baez" );
    assert( s.getYear() == 1971 );
    cout << " 2 " << flush;

    fin.close();
    cout << "Passed!" << endl;
}
void SongTester::testWriteTo() {
	cout<< "- testWriteTo()..."<< flush;
	// declare three songs
	      Song s1("Badge", "Cream", 1969);
	      Song s2("Godzilla", "Blue Oyster Cult", 1977);
	      Song s3("Behind Blue Eyes", "The Who", 1971);

	      // write the three songs to an output file
	      ofstream fout("testSongOutput.txt");
	      assert( fout.is_open() );
	      s1.writeTo(fout);
	      s2.writeTo(fout);
	      s3.writeTo(fout);
	      fout.close();

	      // use readFrom() to see if writeTo() worked
	      ifstream fin("testSongOutput.txt");
	      assert( fin.is_open() );
	      Song s4, s5, s6;

	      // read and check the first song
	      s4.readFrom(fin);
	      assert( s4.getTitle() == "Badge" );
	      assert( s4.getArtist() == "Cream" );
	      assert( s4.getYear() == 1969 );
	      cout << " 0 " << flush;

	      // read and check the second song
	      s5.readFrom(fin);
	      assert( s5.getTitle() == "Godzilla" );
	      assert( s5.getArtist() == "Blue Oyster Cult" );
	      assert( s5.getYear() == 1977 );
	      cout << " 1 " << flush;

	      // read and check the third song
	      s6.readFrom(fin);
	      assert( s6.getTitle() == "Behind Blue Eyes" );
	      assert( s6.getArtist() == "The Who" );
	      assert( s6.getYear() == 1971 );
	      cout << " 2 " << flush;

	      fin.close();
	      cout << " Passed!" << endl;
}

void SongTester::testOperator(){
	cout<< "testing operator ==..."<< flush;
	Song s1("Let It Be", "The Beatles", 1967);
	Song s2("Let It Be", "Joan Baez", 1971);
	assert(!(s1==s2));
	cout<< " 0 "<< flush;

	Song s3("songName","artistName", 1990);
	Song s4("songName","artistName", 1992);
	assert(!(s3==s4));
	cout<< " 1 "<< flush;

	Song s5("songName","artistName", 1992);
	Song s6("songName","artistName", 1992);
	assert(!(s5==s6));
	cout<< " 2 "<< endl;

	cout<< "operator is working!"<< endl;
}

