//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"

/*

Code By: Rithvik Baddam (rrb2442) and Carlos Villapudua (civ298)
Date:	10/28/18

UtPod.h has prototypes for functions in UtPod.cpp and has const values for 
return codes of success/failure and max memory of any UtPod object

*/

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         Song s;
         SongNode *next;
      };
      
      SongNode *songs;  //the head pointer
      
      int memSize;

     /* FUNCTION - int numNodes
       * finds number of nodes (songs) in the UtPod
       * returns int type

         input parms - none

         output parms - number of songs, of int type
      */

      int numNodes();


      /* FUNCTION - int getUsedMem
       *  returns the amount of memory used to store songs

         input parms -  none

         output parms - returns amount of memory (MB) taken by songs in int data type
      */

      int getUsedMem();   
      
   public:
      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod();

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod(int size);

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - address of song variable to add to UTPod

       output parms - success/no memory code
      */

      int addSong(Song const &s);


      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -2 if nothing is removed


         input parms -	address of object of song to remove

         output parms - success/fail code 
      */

      int removeSong(Song const &s);


      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - none
      */

      void shuffle();


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms - none

         output parms - none, but prints list of songs to console
      */

      void showSongList();

      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - none
      */

      void sortSongList();

      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms - none

         output parms - none
      */
      void clearMemory();

      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - size (MB) of int data type
      */

      int getTotalMemory() {
         return memSize;
      }

     /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -  none

         output parms - returns amount of memory (MB)  left in int data type
      */

      int getRemainingMemory();
      
      // UtPod Destructor
      ~UtPod();
 
};



#endif