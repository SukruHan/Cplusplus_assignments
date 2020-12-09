#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    // Write your code here
    //title=songTitle ; url=songUrl ; score=songScore
    for(unsigned int i=0; i<songs.size(); i++){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Write your code here
    if (songsInfo.find(title) != songsInfo.end() || score > 10 || score <0){
        return false;
    }else{
        songs.push_back(title);
        songsInfo[title] = {url, score};
        return true;
    }
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    // Write your code here
    if(howGood == "abysmal"){
    for(unsigned int i=0; i<songs.size(); i++){
        if(songsInfo[songs[i]].score >= 0 && songsInfo[songs[i]].score<3){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
        }
    }
    }
    else if(howGood == "lousy"){
    for(unsigned int i=0; i<songs.size(); i++){
        if(songsInfo[songs[i]].score >= 3 && songsInfo[songs[i]].score<5){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
        }
    }
    }
    else if(howGood == "meh"){
    for(unsigned int i=0; i<songs.size(); i++){
        if(songsInfo[songs[i]].score >= 5 && songsInfo[songs[i]].score<7){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
        }
    }
    }
    else if(howGood == "cool"){
    for(unsigned int i=0; i<songs.size(); i++){
        if(songsInfo[songs[i]].score >= 7 && songsInfo[songs[i]].score<9){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
        }
    } 
    }
    else if(howGood == "OMG"){
    for(unsigned int i=0; i<songs.size(); i++){
        if(songsInfo[songs[i]].score >= 9 && songsInfo[songs[i]].score<=10){
        cout << "title=" << songs[i]  << "; url=" << songsInfo[songs[i]].url << "; score=" << songsInfo[songs[i]].score <<endl;
        }
    }
    }else{
        return;
    }
}
