#include <cstdlib>
#include <string>

using namespace std;

	Song::Song(){

	}
	Song::Song(string _artist, string _songName, int _size){
		artist = _artist;
		songName = _songName;
		size = _size;
	}

	bool Song::operator == (Song const &rhs){
		return (artist == rhs.artist && songName == rhs.songName && size == rhs.size);
	}

