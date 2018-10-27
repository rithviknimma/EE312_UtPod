#include <cstdlib>
#include <iostream>
#include <string>
#include "UtPod.h"
//#include "Song.h"
using namespace std;

	UtPod::UtPod(){
		songs = NULL;
		memSize = MAX_MEMORY;
	}

	UtPod::UtPod(int size){
		songs = NULL;
		memSize = size;
	}

	int UtPod::addSong(Song const &s){
		// account for memory
		if(getRemainingMemory() < s.getSize()){
			return NO_MEMORY;
		}
//cout << s.getSize() << endl;

		// make new SongNode
		SongNode *newSong = new SongNode;
		//newSong->s = *s;
		newSong->s = s;
		newSong->next = NULL;

		if(songs == NULL){
			songs = newSong;
			return SUCCESS;
		}
		else{
			SongNode *ptr = songs;
			SongNode *trail = ptr;
			while(ptr != NULL){
//cout<< "broken" << endl;
				ptr = ptr->next;
				if(ptr == NULL){
					trail->next = newSong;
				}
				trail = ptr;
			}
			return SUCCESS;
		}
		return SUCCESS;
	}

	// will only delete the first instance of the song
	int UtPod::removeSong(Song const &s){
		SongNode *ptr = songs;
		SongNode *trail; 

		// code for song to be removed if it is the first one
		if(ptr != NULL && ptr->s == s){
			trail = ptr->next;
			delete ptr;
			songs = trail;
			return SUCCESS;
		}

		// code to remove a song if it is not the first one
		while(ptr != NULL){
			if(ptr->s == s){
				trail->next = ptr->next;
				// delete the node
				delete ptr;
				return SUCCESS;
			}
			trail = ptr;
			ptr = ptr->next;
		}

		return NOT_FOUND; // error message if song not found
	}

	void UtPod::shuffle(){

	}

	void UtPod::showSongList(){
		SongNode *ptr = songs;
		while(ptr != NULL){
			cout << "*" << ptr->s.getSongName() << " " << "Aritst: " << ptr->s.getArtistName() << " " << "size: " << ptr->s.getSize() << endl;
			ptr = ptr->next;
		}	
	}

	void UtPod::sortSongList(){

	}

	int UtPod::getRemainingMemory(){
		int usedMem = getUsedMem();
		return memSize - usedMem;
	}

	int UtPod::getUsedMem(){
		int usedMem = 0;
		SongNode *ptr = songs;

		while(ptr != NULL){
			usedMem += ptr->s.getSize();
			ptr = ptr->next;
		}
		return usedMem;
	}

	UtPod::~UtPod(){
		// clean up
		SongNode *ptr = songs;
		SongNode *trail = ptr;
		while(ptr != NULL){
			ptr = trail->next;
			delete trail;
			trail = ptr;
		}
		delete trail;
	}

