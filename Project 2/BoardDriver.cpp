#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "Board.h"
#include "EventsFunctions.cpp"
using namespace std;
// board.movePlayer(0); this moves player 1
// board.movePlayer(1); this move player 2


// Literally just a dice roll
int rollDice(){ 
    int seed = time(0);
    srand(seed);
   return (rand() % 6) + 1;
} 

// Will move a character however many times the roll dictates and then display the board
Board movePhase(int roll, int playerNumber, Board board) {
  
    for (int i = 0; i < roll; i++) {
        board.movePlayer(playerNumber); // moves once cause function
    }
    return board; 
}

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



//  MAIN CODE STARTS HERE
int main () {
    int seed = time(0);
    srand(seed);
    Board board(2);

    // Insert beginning menu here

    board.playerBoard[0] = 1;   // 0 means start on cub training. One is for pride lands ask once game start
    board.playerBoard[1] = 1;   // Can also be used in the future for switching boards mechanic :O
    board.displayBoard(); // initial positions
   
 
  bool playerNotDone[2] = {true, true}; // tests to see if players have reached the goal
  
  // while loop as we play, main gameplay loop
   while (playerNotDone[0] || playerNotDone[1]){ 
    for (int i=0;i<2;i++){

    if (playerNotDone[i]){
        cin.get();
        // Insert menu function here that will be used for chossing actions!!!!!!!
        board = movePhase(rollDice(),i,board);
    }
    else{
        cin.get(); // gets can be commented out once the menus done
        cout<< "Player "<< i+1<< " has finished \n";
    }

    if (board.getPlayerPosition(i)>=51){
        playerNotDone[i]=false;
        board._player_position[i] = 51;
    }

    board.displayBoard();  // displays board after each individual move
    runEvent(i,board.getPlayerPosition(i),board);  // After displaying, we want to run the event
    } 
  }
  // after both players have reached the end, this is run
 
 


  return 0;
}

