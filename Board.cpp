/*
Names: Josiah Galvan 
       Alexander Gholmieh
*/

#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"


void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++){
    initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

void Board::initializeTiles(int boardType)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int greenMax, probBlue, probPink, probBrown, probRed, probPurple;       // Max Green tiles and probabilities declared

    if (boardType==0) {
        greenMax=30;

        probBlue=20;
        probPink=20;
        probBrown=10;
        probRed=25;
        probPurple=25;
    }
    else {
        greenMax=15;
        
        probBlue=20;
        probPink=20;
        probBrown=20;
        probRed=20;
        probPurple=20;
    }

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            temp.color = 'O';

        }
        else if (i == 0) {
            temp.color = 'Y';
        }
        else if (green_count < greenMax && (rand() % (total_tiles - i) < greenMax - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
        // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
        int color_choice = rand() % 100;
        if (color_choice < probBlue)
                temp.color = 'B'; // Blue
        else if (color_choice < probBlue+probPink)
                temp.color = 'P'; // Pink
        else if (color_choice < probBlue+probPink+probBrown)
                temp.color = 'N'; // Brown
        else if (color_choice < probBlue+probPink+probBrown+probRed)
                temp.color = 'R'; // Red
        else if (color_choice < probBlue+probPink+probBrown+probRed+probPurple)
                temp.color = 'U'; // Purple 
        else {
            cout <<  "You are a monkey. Learn probability please" <<endl;
            break;
        }            
            
        }
    // Assign the tile to the board for the specified lane
    _tiles[boardType][i] = temp;
    }
}

Board::Board() {
    _player_count = 1;
    _player_position[0] = 0;
    initializeTiles(0);
}

Board::Board(int player_count) {
    if (player_count > _MAX_PLAYERS) {
        _player_count = _MAX_PLAYERS;
    }
    else {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++) {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos) {
if (_player_position[player_index] == pos) {
    return true;
}
    return false;
}

void Board::displayTile(int player_index, int pos)
{
    string color = " ";

    bool player1here = false;
    bool player2here = false;

  
    if (_player_position[0] == pos && player_index == playerBoard[0]) {
        player1here = true;
    }
    if (_player_position[1] == pos && player_index == playerBoard[1]) {
        player2here = true;
    }
      
    if (_tiles[player_index][pos].color == 'R') {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G') {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B') {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U') {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N') {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P') {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O') {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y') {
        color = GREY;
    }
    if (player1here && player2here) {
        cout << color << "|" << "1&2" << "|" << RESET;
    }
    else if (player1here) {
        cout << color << "|" << "1" << "|" << RESET;
    }
    else if (player2here) {
        cout << color << "|" << "2" << "|" << RESET;
    }
    else {
        cout << color << "| |" << RESET;
    }

}

void Board::displayTrack(int track_index) {
    for (int i = 0; i < _BOARD_SIZE; i++) {
        displayTile(track_index, i);
    }
    cout << "                                                                                                                                       "<< endl;
}

void Board::displayBoard() {
    for (int i = 0; i < 2; i++) {
        displayTrack(i);
        if (true) {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int num) {
    _player_position[player_index]+=num;
    
    if (_player_position[player_index] < 0) {
            _player_position[player_index]=0;
    }
    if (_player_position[player_index] == _BOARD_SIZE -1) {
        return true;
    }
    
    return false; 
}

int Board::getPlayerPosition (int player_index) const {
    if (player_index >= 0 && player_index <= _player_count) {
        return _player_position[player_index];
    }
    return -1;
}


// Func. I added

char Board::returnTileColor(int playerNo, int pos){
    return _tiles[playerBoard[playerNo]][pos].color;
}
