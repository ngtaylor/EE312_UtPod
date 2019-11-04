//Song.h
//
//EE312
//Author: Nicholas Taylor
//EID: ngt333
//Date: 10/23/2019

#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
    private:
        string title;
        string artist;
        int size;

    public:

        Song();
        Song(string _artist, string _title, int _size);

        string getTitle();
        void setTitle(string _title);

        string getArtist();
        void setArtist(string _artist);

        int getSize();
        void setSize(int _size);

        /* Function - void swap
         * Swaps the contents of two songs
         * Inputs: Song being swapped with
         * Outputs: None
        */
        void swap(Song &s);

        /* Function - bool operator ==
         * Checks if two songs hold the same contents
         * Inputs: Song being compared on the rhs
         * Outputs: True for same contents, false otherwise
         */
        bool operator ==(Song const &rhs);

        /* Function - bool operator <
         * Checks if a song is lower on the list alphabetically
         * Priority is Artist, then Title, then Size
         * Inputs: Song being compared on the rhs
         * Outputs: True if rhs is further down the list, false otherwise
         */
        bool operator <(Song const &rhs);

        ~Song();

};



#endif