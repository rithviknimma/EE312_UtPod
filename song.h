
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

	/* FUNCTION - string getArtistName
	 * Function returns name of artist


     input parms - none

     output parms - string of artist of song

    //pre: UtPod has been constructed
    //post: artist name of song is returned
  */

		string getArtistName() const{
			return artist;
		};

	/* FUNCTION - string getSongName
	* Function returns name of song


	input parms - none

	output parms - string of name of song

	//pre: UtPod has been constructed
	//post: name of song is returned
	*/
		string getSongName() const{
			return songName;
		};

	/* FUNCTION - int getSize
	* Function returns size of song


	input parms - none

	output parms - int of size of song

	//pre: UtPod has been constructed
	//post: size of song is returned
	*/
		int getSize() const{
			return size;
		};
	/* FUNCTION - void setArtistName


     input parms - input string by driver program for artist Name

     output parms - none

    	//pre: song has already been constructed
		//post: song node has been given an artist
  */

		void setArtistName(string artistName);

	/* FUNCTION - void setSongName


 	input parms - input string by driver program for song name

 	output parms - none

    //pre: string is passed to function
	//post: specified object of Song type is given a songName of string type
	*/

		void setSongName(string songN);

	/* FUNCTION - void setSize


 	input parms - input int by driver program for song size

 	output parms - none

	//pre: int is passed to function
	//post: specified object of Song type is given a size of int type
	*/
		void setSize(int songSize);

	/* FUNCTION - void operator <


	input parms -  song to right hand side of operator

	output parms - true if left side song is less than right hand song -- false if right hand song is less than left hand song

	//pre: two valid and populated songs are passed to function through override of < operator (with Song type)
	//post: returns true if song on left side is less than song on right side -- returns false for any other case
*/
		bool operator <(Song const &rhs);

	/* FUNCTION - void operator >


	input parms -  song to right hand side of operator

	output parms - true if right side song is less than left hand song -- false if left hand song is less than right hand song

	//pre: two valid and populated songs are passed to function through overriding of operator
	//post: returns true if left side song is greater than right side song -- returns false for any other case
	*/
		bool operator >(Song const &rhs);

	/* FUNCTION - void operator <


	input parms -  song to right hand side of operator

	output parms - true if left side song is equal to right hand song, vice versa

	 //pre: two valid and populated songs are passed to function through override of < operator (with Song type)
	//post: returns true if song on left side is less than song on right side -- returns false for any other case

	*/
		bool operator ==(Song const &rhs);

};

#endif

