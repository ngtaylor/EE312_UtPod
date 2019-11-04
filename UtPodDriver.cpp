/* UtPodDriver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
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

    //Tests removing from an empty SongList, -2 expected
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    //Tests memory clear, 0 expected
    t.clearMemory();
    cout << "memory = " << t.getRemainingMemory() << endl;

    t.showSongList();

    //Tests adding a song that uses all space to an empty UtPod, 0 expected
    Song s6("Queen", "Killer Queen", 512);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    //Tests adding a song to a full UtPod, -1 expected
    result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    t.clearMemory();

    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s6);
    Song s7("Beatles", "Hey Jude1", 9);
    t.addSong(s7);

    //Killer Queen should not show up as it is too large
    t.showSongList();

    //Tests sort function, songs were added in reverse order should print in the correct order, s7 should be before s1 due to smaller size
    t.sortSongList();
    t.showSongList();

    //Tests removing only one copy of a song if there are more than one
    t.addSong(s4);
    t.sortSongList();
    t.showSongList();
    t.removeSong(s4);
    t.showSongList();
    t.clearMemory();

    //Tests getTotalMemory
    cout << "Total Memory = " << t.getTotalMemory() << endl;

    //Tests shuffling
    Song s8("Queen", "Killer Queen", 2);
    t.addSong(s8);
    Song s9("Kendrick Lamar", "King's Dead", 4);
    t.addSong(s9);
    Song s10("Toto", "Africa", 5);
    t.addSong(s10);
    Song s11("Micheal Jackson", "Thriller", 6);
    t.addSong(s11);
    Song s12("Tyler, The Creator", "Boredom", 4);
    t.addSong(s12);
    Song s13("Billy Joel", "Piano Man", 2);
    t.addSong(s13);

    t.showSongList();
    t.shuffle();
    t.showSongList();
    t.sortSongList();
    t.showSongList();

}