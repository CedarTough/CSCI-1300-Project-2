#include <iostream>
#include <cstdlib> 
#include "Board.h"
using namespace std;

void runEvent(int playerNo,int pos,Board board){
    int color = board.returnTileColor(playerNo,pos);  // Change function names when we know what each color reps.
    if (color == 'R') {
        eventRed(board);
    }
    else if (color == 'G') {
        eventGreen(board);
    }
    else if (color == 'B') {
        eventBlue(board);
    }
    else if (color == 'U') {
        eventPurple(board);
    }
    else if (color == 'N') {
        eventBrown(board);
    }
    else if (color == 'P') {
        eventPink(board);
    }
    else if (color == 'O') {
        eventOrange(board);
    }
    else if (color == 'Y') {
        eventGrey(board);
  }
}


void eventRed(Board board){
    cout<<"this tile is red"<<endl;
}

void eventGreen(Board board){
    cout<<"this tile is green"<<endl;
}

void eventBlue(Board board){
    cout<<"this tile is blue"<<endl;
}

void eventPurple(Board board){
    cout<<"this tile is purple"<<endl;
}

void eventBrown(Board board){
    cout<<"this tile is brown"<<endl;
}

void eventPink(Board board){
    cout<<"this tile is pink"<<endl;
}

void eventOrange(Board board){
    cout<<"this tile is orange"<<endl;
}

void eventGrey(Board board){
    cout<<"this tile is grey"<<endl;
}

