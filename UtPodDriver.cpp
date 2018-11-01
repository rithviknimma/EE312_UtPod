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

    Song s1("Beatles", "Hey Jude", 4);
    Song s2("Ed Sheeran", "Perfect", 12);
    Song s3("Sheck Wes", "Mo Bamba", 6);
    Song s4("Sheck Wes", "Kyrie", 4);
    Song s5("Ellie Goulding", "Love me like you do", 7);
    Song s6("Shakira", "Hips Don't Lie", 10);
    Song s7("O.T Genesis", "Ricky", 15);
    Song s8("Drake", "Non Stop", 14);
    Song s9("Drake", "In My Feelings", 14);
    Song s10("Drake", "In My Feelings", 15);
    Song s11("Drake", "Gods's Plan", 12);
    Song s12("Drake", "Gods's Plan", 500);

    int result;
    cout << "Results of adding songs" << endl;
    result = t.addSong(s1);
    cout << "result = " << result << endl;
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    result = t.addSong(s5);
    cout << "result = " << result << endl;  

    cout << "*************************" << endl;
    t.showSongList();
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;
    cout << "*************************" << endl;

    result = t.addSong(s6);
    cout << "result = " << result << endl;
    result = t.addSong(s7);
    cout << "result = " << result << endl;
    result = t.addSong(s8);
    cout << "result = " << result << endl;
    result = t.addSong(s9);
    cout << "result = " << result << endl;
    result = t.addSong(s10);
    cout << "result = " << result << endl; 
    result = t.addSong(s11);
    cout << "result = " << result << endl; 
    result = t.addSong(s12);
    cout << "result = " << result << endl; 
    t.showSongList();

    cout << "*************************" << endl;
    cout << "After adding all songs" << endl;
    t.showSongList();
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

    cout << "*************************" << endl;

    cout << "SORTED LIST" << endl;
    t.sortSongList();
    t.showSongList();

    cout << "*************************" << endl;
    cout << "SHUFFLED LIST" << endl;
    t.shuffle();
    t.showSongList();

    cout << "*************************" << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl; 
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl; 
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl; 
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl; 
    result = t.removeSong(s10);
    cout << "delete result = " << result << endl; 
    result = t.removeSong(s12);
    cout << "delete result = " << result << endl; 
    
    cout << "*************************" << endl;
    cout << "AFTER REMOVING SONGS" << endl;
    t.showSongList();

    cout << "*************************" << endl;
    cout << "Memory after removing some songs" << endl;
    t.showSongList();
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

    cout << "*************************" << endl;
    cout << "CLEARED MEM" << endl;
    t.clearMemory();
    t.showSongList();

    cout << "*************************" << endl;
    cout << "After removing all songs" << endl;
    t.showSongList();
    cout << "Total Memory: " << t.getTotalMemory() << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << endl;

    cout << "*************************" << endl;
    cout << "Add song after clearing" << endl;
    t.addSong(s1);
    t.showSongList();

    cout << "*************************" << endl;


    
    
    return 0;
}


