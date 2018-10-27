// need check if equal operator
// need greater than and less than operators for sorting 
// need getSize fucntion

//i dont know what this is but since Utpod has this I'll include this
#ifndef SONG_H
#define SONG_H

using namespace std;

class Song{
	private:
		string artist;
		string songName;
		int size;

	public:
		Song();   // not sure if this is needed
		Song(string artist, string songName, int size);

		string getArtistName() const{
			return artist;
		};
		string getSongName() const{
			return songName;
		};
		int getSize() const{
			return size;
		};

		bool operator ==(Song const &rhs);
};

#endif

