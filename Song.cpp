//Song.cpp
//
//EE312
//Author: Nicholas Taylor
//EID: ngt333
//Date: 10/23/2019

#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

    Song::Song() {
        title = "";
        artist = "";
        size = 0;
    }

    Song::Song(string _artist, string _title, int _size){
        title = _title;
        artist = _artist;
        size = _size;
    }

    string Song::getTitle() {
        return title;
    }

    void Song::setTitle(string _title) {
        title = _title;
    }

    string Song::getArtist() {
        return artist;
    }

    void Song::setArtist(string _artist) {
        artist = _artist;
    }

    int Song::getSize() {
        return size;
    }

    void Song::setSize(int _size) {
        size = _size;
    }

    void Song::swap(Song &s){
        Song tempSong;
        tempSong.title = title;
        tempSong.artist = artist;
        tempSong.size = size;
        title = s.title;
        artist = s.artist;
        size = s.size;
        s.title = tempSong.title;
        s.artist = tempSong.artist;
        s.size = tempSong.size;
    }

    bool Song::operator ==(Song const &rhs){
        return(title == rhs.title &&
               artist == rhs.artist &&
               size == rhs.size);
    }

    bool Song::operator <(Song const &rhs){
        if(artist < rhs.artist) {
            return(true);
        } else {
            if(artist == rhs.artist){
                if(title < rhs.title){
                    return(true);
                } else {
                    if(title == rhs.title){
                        return size < rhs.size;
                    } else {
                        return(false);
                    }
                }
            } else {
                return(false);
            }
        }
    }

    Song::~Song() = default;



