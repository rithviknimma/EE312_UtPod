#include <cstdlib>
#include <iostream>
#include <string>
#include "UtPod.h"
#include <time.h>

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

	/*
		pre: song has to be initialized
		post: songs list populated with a song
	*/
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
			//return SUCCESS;
		}
		else{
			SongNode *ptr = songs;
			SongNode *trail = ptr;
			while(ptr != NULL){
				ptr = ptr->next;
				if(ptr == NULL){
					trail->next = newSong;
				}
				trail = ptr;
			}
			//return SUCCESS;
		}
		return SUCCESS;
	}

	/*  pre: 
		post: will only delete the first instance of the song
	*/
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
		unsigned int currentTime = (unsigned) time(0);
		srand(currentTime);

		int numLoops = numNodes();
		int randomNum1; 
		int randomNum2;

		Song temp; 
		//SongNode *ptr = songs;
		SongNode *adr1 = songs;
		SongNode *adr2 = songs;

		for(int i = 0; i < 2*numLoops; i++){
			randomNum1 = rand() % numLoops + 1;
			randomNum2 = rand() % numLoops + 1;

			for(int node1 = 1; node1 < randomNum1; node1++){
				adr1 = adr1->next;
			}

			for(int node2 = 1; node2 < randomNum2; node2++){
				adr2 = adr2->next;
			}

			temp = adr1->s;
			adr1->s = adr2->s;
			adr2->s = temp;

			adr1 = songs;
			adr2 = songs;
		}

	}

	int UtPod::numNodes(){
		SongNode *ptr = songs;
		int nodes = 0;

		while (ptr != NULL){
			nodes++;
			ptr = ptr->next;
		}
		return nodes;
	}

	void UtPod::showSongList(){
		SongNode *ptr = songs;
		while(ptr != NULL){
			cout << "* Artist: " << ptr->s.getArtistName() << endl;
			cout << "  Song: " << ptr->s.getSongName() << endl;
			cout << "  Size: " << ptr->s.getSize() << endl;
			ptr = ptr->next;
		}	
	}



	void UtPod::sortSongList(){
   		SongNode *minNode = songs;           //used to know where to insert larger song of pair of compared songs
   		SongNode *ptr = songs;               //outer while loop
   		SongNode *cmpr = songs;              //inner while loop
    	Song min = ptr->s;                   //copy of song (min song)

   		while (ptr != NULL){
     		while (cmpr != NULL){
        		cmpr = cmpr->next;
         		if (cmpr != NULL && cmpr->s < min){
          		   min = cmpr->s;
          		   minNode = cmpr;
        		}
      		}
      
      		minNode->s = ptr->s;
     		ptr->s = min;
      		ptr = ptr->next;
     		cmpr= ptr;
     		if(ptr != NULL){
     			min = ptr->s;
     		}
    	}
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

