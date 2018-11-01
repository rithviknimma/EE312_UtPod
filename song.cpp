#include <cstdlib>
#include <string>
#include "song.h"

// set variable functions and make operator functions
using namespace std;

//pre: Song is passed nothing, and is rather just constructed
//post: Song is initialized to empty string for artist and name, and size is set to zero
	Song::Song(){		
		artist = "";
		songName = "";
		size = 0;
	}

//pre: parameters of int, and two strings are passed to function
//post: object of Song type specified by caller function is given a size of int type, and a songName and artist of string type
	Song::Song(string _artist, string _songName, int _size){		//if called with full parameter list, place input into corresponding instance variables
		artist = _artist;
		songName = _songName;
		size = _size;
	}

//pre: string is passed to function
//post: specified object of Song type is given an artist of string type
	void Song::setArtistName(string artistName){		//solely sets artist name
		artist = artistName;
	}

//pre: string is passed to function
//post: specified object of Song type is given a songName of string type
	void Song::setSongName(string songN){		//solely sets songName
		songName = songN;
	}

//pre: int is passed to function
//post: specified object of Song type is given a size of int type
	void Song::setSize(int songSize){		//solely sets size of song
		size = songSize;
	}

//pre: two valid and populated songs are passed to function through override of < operator (with Song type)
//post: returns true if song on left side is less than song on right side -- returns false for any other case
	
	bool Song::operator <(Song const &rhs){		//override less than operator
   
   		if (artist.compare(rhs.artist) < 0){		//if left handside artist is less than right side artist, return true
//compare function returns less than 0 if artist is less than right hand side artist
      		return true;
   		}
   		else if (artist.compare(rhs.artist) > 0)		//only proceed if artists are not equal -- otherwise return false
      		return false;
   
   		if(songName.compare(rhs.songName) < 0)			//if left side songName is less than right side songName, return true
      		return true;
   		else if (songName.compare(rhs.songName) > 0)	//only proceed if songNames are equal -- otherwise return false
      		return false;
   
   		if (size < rhs.size){		//last comparison -- if left hand side song's size is less than right hand side's song, then return true
      		return true;
   		}
    	else		//if else is reached, then right hand side is smaller
      		return false;
	}



//pre: two valid and populated songs are passed to function through overriding of operator
//post: returns true if left side song is greater than right side song -- returns false for any other case
	bool Song::operator >(Song const &rhs){		//override operator for greater than sign
		if(artist.compare(rhs.artist) > 0){		//compare function returns a number greater than 0 if artist (artist part of left hand side song) is larger than rhs.artist
			return true;
		}
		else if (artist.compare(rhs.artist) < 0){		//only skip if statement if artists are of the same value
			return false;
		}

		if(songName.compare(rhs.songName) > 0){
			return true;
		}
		else if(songName.compare(rhs.songName) < 0){
			return false;
		}
		
		if(size > rhs.size){
			return true;
		}

		return false;
	}


//pre: two valid and populated songs (no nonsense values) are passed to function
//post: returns true if both songs are the same song -- returns false if songs are not the same

	bool Song::operator ==(Song const &rhs){
		return (artist == rhs.artist && songName == rhs.songName && size == rhs.size);		//if all elements of right and left side songs are equal, then return true
	}



