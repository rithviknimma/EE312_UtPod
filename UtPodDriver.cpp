/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

// comment inside functions
// write pre and post conditions
// write readme file
// write UtPodDriver file and test extensively
// zip and turn in

int main()
{
    UtPod t;

    /*Song s1("Beatles", "Hey Jude1", 2);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude1", 3);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();

    if(s1 > s2){
        cout << "greater than" << endl;
    }
    else if(s1 < s2){
        cout << "less than" << endl;
    }
    //Song s1("Beatles", "Hey Jude1", 4);
    
    Song s6;
    s6.setArtistName("Carlos");
    s6.setSongName("Ricky is so cool");
    s6.setSize(420);
    int result = t.addSong(s6);
    cout << "result = " << result << endl;
    */
    //t.showSongList();
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    //t.showSongList();
          
    Song s5("Beatles", "Hey Jude1", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s4("Beatles", "Hey Jude1", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s2("Beatles", "Hey Jude1", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
       
    Song s3("Beatles", "Hey Jude1", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    t.showSongList();
       
    t.sortSongList();

    cout << "*************************" << endl;

    t.showSongList();

    t.shuffle();

    cout << "*************************" << endl;

    t.showSongList();
    
    /*result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    */
    
    return 0;
}


