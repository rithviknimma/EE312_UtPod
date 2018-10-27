#include <cstdlib>
#include <string>
#include "Song.h"

// set variable functions and make operator functions
using namespace std;

	Song::Song(){
		artist = "";
		songName = "";
		size = 0;
	}
	
	Song::Song(string _artist, string _songName, int _size){
		artist = _artist;
		songName = _songName;
		size = _size;
	}

	void Song::setArtistName(string artistName){
		artist = artistName;
	}

	void Song::setSongName(string songN){
		songName = songN;
	}

	void Song::setSize(int songSize){
		size = songSize;
	}

	bool Song::operator <(Song const &rhs){

	}

	bool Song::operator >(Song const &rhs){

	}

	bool Song::operator ==(Song const &rhs){
		return (artist == rhs.artist && songName == rhs.songName && size == rhs.size);
	}



