#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "Board.h"
using namespace std;

int main () {
    int seed = time(0);
    srand(seed);
    Board board(2);
    board.displayBoard();
    
}
