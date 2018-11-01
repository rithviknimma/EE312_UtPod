
/*

Code By: Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:	10/28/18

song.h has function prototypes for song.cpp functions 

*/



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

		void setArtistName(string artistName);
		void setSongName(string songN);
		void setSize(int songSize);

		bool operator <(Song const &rhs);
		bool operator >(Song const &rhs);
		bool operator ==(Song const &rhs);

};

#endif

