#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Tile.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
     
    void displayTile(int player_index, int pos);
    void initializeTiles(int boardType);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index,int num);
    int getPlayerPosition(int player_index) const;
    int _player_position[_MAX_PLAYERS];
    int playerBoard[2]={0,0};
    char returnTileColor(int playerNo, int pos);


};

#endif
