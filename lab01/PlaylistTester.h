/*
 * PlaylistTester.h
 *
 *  Created on: Sep 12, 2017
 *      Author: bda5
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_
#include <string>
using namespace std;

class PlaylistTester {
public:
	PlaylistTester();
	PlaylistTester(const string& fileName);
	void runTests();
	void testConstructors();
	void testSearchByArtist();
};

#endif /* PLAYLISTTESTER_H_ */
