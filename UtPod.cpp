#include <cstdlib>
#include <string>
#include "UtPod.h"

using namespace std;

	UtPod::UtPod(){
		memSize = MAX_MEMORY;
	}

	UtPod::UtPod(int size){
		memSize = size;
	}

	int UtPod::addSong(Song const &s){
		// account for memory
		if(getRemainingMemory() < s.getSize()){
			return NO_MEMORY;
		}

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
			while(ptr != NULL){
				if(ptr->next == NULL){
					ptr->next = newSong;
				}
				ptr = ptr->next;
			}
			return SUCCESS;
		}
		return SUCCESS;
	}

	// will only delete the first instance of the song
	int UtPod::removeSong(Song const &s){
		SongNode *ptr = songs;
		SongNode *trail; 
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

		return NOT_FOUND;
	}

	void UtPod::shuffle(){

	}

	void UtPod::showSongList(){

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
	}

