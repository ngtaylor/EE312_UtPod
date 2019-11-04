//UtPod.cpp
//
//EE312
//Author: Nicholas Taylor
//EID: ngt333
//Date: 10/23/2019


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"

using namespace std;

    UtPod::UtPod() {
        memSize = MAX_MEMORY;
        songs = NULL;
        unsigned int currentTime = (unsigned)time(NULL);     //Seeds for shuffle
        srand(currentTime);
    }

    UtPod::UtPod(int size){
        if(size <= 0 || size > MAX_MEMORY){
            memSize = MAX_MEMORY;
        } else {
            memSize = size;
        }
        songs = NULL;
        unsigned int currentTime = (unsigned)time(NULL);     //Seeds for shuffle
        srand(currentTime);
    }

    int UtPod::addSong(Song &s) {
        if(getRemainingMemory() < s.getSize()){
            return NO_MEMORY;
        } else {
            SongNode *newNode = new SongNode;
            newNode->s = s;
            newNode->next = songs;
            songs = newNode;
            return SUCCESS;
        }
    }

    int UtPod::removeSong(Song &s) {
        if((getRemainingMemory() + s.getSize()) > memSize){
            return NOT_FOUND;
        } else {
            SongNode *p2 = songs;
            for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
                if(p1->s == s){
                    if(p1 == songs){
                        songs = p1->next;
                        delete p1;
                        return SUCCESS;
                    } else {
                        p2->next = p1->next;
                        delete p1;
                        return SUCCESS;
                    }
                }
                if(p1 != songs){
                    p2 = p2->next;
                }
            }
            return NOT_FOUND;
        }
    }

    void UtPod::shuffle() {
        int numSongs = 0;
        for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
            numSongs++;
        }
        for(int numSwaps = numSongs*3; numSwaps > 0; numSwaps--){
            SongNode *firstSong = songs;
            SongNode *secondSong = songs;
            for(int first = rand() % numSongs; first > 0; first--){
                firstSong = firstSong->next;
            }
            for(int second = rand() % numSongs; second > 0; second--){
                secondSong = secondSong->next;
            }
            firstSong->s.swap(secondSong->s);
        }
    }

    void UtPod::showSongList() {
        cout << endl;
        for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
            cout << p1->s.getArtist() << ", " << p1->s.getTitle() << ", " << p1->s.getSize() << " MB" << endl;
        }
        cout << endl;
    }

    void UtPod::sortSongList() {
        for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
            for(SongNode *p2 = p1->next; p2 != NULL; p2 = p2->next){
                if(p2->s < p1->s){
                    p1->s.swap(p2->s);
                }
            }
        }
    }

    void UtPod::clearMemory() {
        SongNode *next;
        for(SongNode *clear = songs; clear != NULL; clear = next){
            next = clear->next;
            delete clear;
        }
        songs = NULL;
    }

    int UtPod::getRemainingMemory() {
        int remMem = memSize;
        for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
            remMem = remMem - p1->s.getSize();
        }
        return remMem;
    }

    UtPod::~UtPod() {
        clearMemory();
    }

