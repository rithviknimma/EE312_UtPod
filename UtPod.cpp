#include <cstdlib>
#include <iostream>
#include <string>
#include "UtPod.h"
#include <time.h>

//#include "Song.h"

using namespace std;

//pre: no parameters passed to construct UTPod
//post: UtPod is constructed with nothing in it and MAX_MEMORY

	UtPod::UtPod(){
		songs = NULL;
		memSize = MAX_MEMORY;
	}

//pre: size is given in int form
//post: UtPod is constructed with nothing inside, but with memSize of parameter passed size

	UtPod::UtPod(int size){
		songs = NULL;
		if(size > MAX_MEMORY || size < 0){
			memSize = MAX_MEMORY;
		}
		else{
			memSize = size;
		}
	}

	
//pre: song has to be initialized
//post: songs list populated with a song

	int UtPod::addSong(Song const &s){
		// account for memory
		if(getRemainingMemory() < s.getSize()){
			return NO_MEMORY;
		}
		// make new SongNode
		SongNode *newSong = new SongNode;
		//newSong->s = *s;
		newSong->s = s;		//write song to utPod
		newSong->next = NULL;	//add a null at the end of list each time

		if(songs == NULL){
			songs = newSong;			//if nothing in utPod, place new song in UTPPod
			//return SUCCESS;
		}
		else{				//link newly created node by adding to last node
			SongNode *ptr = songs;
			SongNode *trail = ptr;
			while(ptr != NULL){
				ptr = ptr->next;
				if(ptr == NULL){		//if last node has been found, insert link at end of node that trail points to
					trail->next = newSong;
				}
				trail = ptr;
			}
			//return SUCCESS;
		}
		return SUCCESS;			//return success if whole process is gone through
	}

//pre: 
//post: will only delete the first instance of the song
	
	int UtPod::removeSong(Song const &s){
		SongNode *ptr = songs;
		SongNode *trail; 

		// code for song to be removed if it is the first one
		if(ptr != NULL && ptr->s == s){
			trail = ptr->next;
			delete ptr;		//delete first node
			songs = trail;		//make head/songs equal to second node (ptr->nxt)
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
			ptr = ptr->next;		//leave trail pointing at one node behind ptr
		}

		return NOT_FOUND; // error message if song not found
	}

//pre: UtPod has not been shuffled
//post: UtPod is shuffled
	void UtPod::shuffle(){
		unsigned int currentTime = (unsigned) time(0);
		srand(currentTime);		//seed rand function with time, which is different at ANY moment

		int numLoops = numNodes();
//create two random Numbers to choose which two nodes to swap
		int randomNum1;		
		int randomNum2;

		Song temp; 
		//SongNode *ptr = songs;
//set both potential adr to head
		SongNode *adr1 = songs;
		SongNode *adr2 = songs;

		for(int i = 0; i < 2*numLoops; i++){		//shuffle for however many songs you have in UtPod * 2
//mod with numLoops (number of songs in UtPod) so that we are given a value in possible range of numbers of songs
			randomNum1 = rand() % numLoops + 1;
			randomNum2 = rand() % numLoops + 1;

			//go through next for loops until we find address of random node to swap (number determined by upper for loop limit
			for(int node1 = 1; node1 < randomNum1; node1++){
				adr1 = adr1->next;
			}

			for(int node2 = 1; node2 < randomNum2; node2++){
				adr2 = adr2->next;
			}
		//swap info from adr1 to adr2, vice versa
			temp = adr1->s;
			adr1->s = adr2->s;
			adr2->s = temp;

			adr1 = songs;
			adr2 = songs;
		}

	}


//pre: UtPod has been constructed
//post: number of songs in UtPod is returned
	int UtPod::numNodes(){
		SongNode *ptr = songs;
		int nodes = 0;
//have ptr traverse whole node LL until null -- add to number of nodes until NULL reached
		while (ptr != NULL){
			nodes++;
			ptr = ptr->next;
		}
		return nodes;
	}

//pre: have utPod constructed
//post: print out contents of UtPod
	void UtPod::showSongList(){
		SongNode *ptr = songs;
		while(ptr != NULL){
			cout << "Song:" << ptr->s.getSongName() << ", Artist: " << ptr->s.getArtistName() << ", Size: " << ptr->s.getSize() << " (MB)" << endl;
			ptr = ptr->next;
		}	
	}


//pre: UtPod has been constructed
//post: UtPod will be sorted from smallest to largest 
	void UtPod::sortSongList(){
   		SongNode *minNode = songs;           //used to know where to insert larger song of pair of compared songs
   		SongNode *ptr = songs;               //outer while loop
   		SongNode *cmpr = songs;              //inner while loop
    	Song min = ptr->s;                   //copy of song (min song)

//nested while loop used to make search for smallest number smaller each time
   		while (ptr != NULL){		
     		while (cmpr != NULL){
        		cmpr = cmpr->next;
		//if song smaller than min has been found in UtPod, override min to be = to that song and set minNode to address of that Node
         		if (cmpr != NULL && cmpr->s < min){
          		   min = cmpr->s;
          		   minNode = cmpr;
        		}
      		}
      //swap whatever was in minNode and ptr
      		minNode->s = ptr->s;
     		ptr->s = min;
//reset ptr and cmpr to make search list smaller this time -- only reset min if not at NULL ptr
      		ptr = ptr->next;
      		minNode = ptr;
     		cmpr= ptr;
     		if(ptr != NULL){
     			min = ptr->s;
     		}
    	}
	}

//pre: UtPod has been constructed
//post: utPod object is completely deleted
	void UtPod::clearMemory(){
		// clean up
		SongNode *ptr = songs;
		SongNode *trail = ptr;
//delete all nodes until you reach NULL ptr
		while(ptr != NULL){
			ptr = trail->next;
			delete trail;
			trail = ptr;
		}
		delete trail;	
		songs = NULL;  //head pointed set to null to show that the list is empty
	}

//pre: have a constructed UtPod
//post: number of MB in memory available is returned
	int UtPod::getRemainingMemory(){
		int usedMem = getUsedMem();
		return memSize - usedMem;
	}

//pre: have a constructed UtPod
//post: number of MB in memory already used is returned

	int UtPod::getUsedMem(){
		int usedMem = 0;
		SongNode *ptr = songs;

//add up all sizes of each node until NULL ptr is reached
		while(ptr != NULL){
			usedMem += ptr->s.getSize();
			ptr = ptr->next;
		}
		return usedMem;
	}

//pre: have a constructed UtPod
//post: utPod object is completely deleted
	UtPod::~UtPod(){
		clearMemory();
	}

