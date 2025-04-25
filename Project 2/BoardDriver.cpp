#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <sstream>
#include <fstream>
#include <vector>
#include <conio.h> 
#include "Board.h"
#include "EventsFunctions.h"
#include "Player.h"
using namespace std;
// board.movePlayer(0); this moves player 1
// board.movePlayer(1); this move player 2

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

int dice(int roll) {
    cout << "You Rolled a:" << endl;
    cout << "-----" << endl;
    cout << "| " << roll <<" |" << endl;
    cout << "-----" << endl;
    return roll;
}

void displayVector(const vector<string> line, int index) {
    for (size_t i = 0; i < line.size(); i++) { //size_t is an unsigend integer that large enough to hold any size array
        if ((int)i == index) { //(int) converts i to int
            cout << "> ";
        }
        else {
            cout << " ";
        }
        cout << line[i] << endl;
    }
}

int arrowKeys (const vector<string> lines, int index, const vector<string> header) {
    char ch;

    while(true) {
        system("cls");
        int size = header.size();
        for(int i = 0; i < size; i++) {
            cout << header[i] << endl;
        }
        displayVector(lines, index);
        ch = _getch(); //detects if a special key was a pressed 

        if (ch == 0 || ch == -32) { //checks if it was a special key which return either 0 or -32
            ch = _getch(); //this is to acutally detect the arrow key
            switch(ch) {
                case 72: // ASCII number for up arrow 
                    index = (index - 1 + lines.size()) % lines.size();
                    break;
                case 80: // ASCII number for down arrow
                    index = (index + 1) % lines.size();
                    break;
            }
        }
        else if (ch == 13) { // ASCII number for enter 
            break;
        }
    }
    return index;
}

vector<string> characterSelection (const vector<string> character, int index, const vector<string> header) {
    string chosen;
    vector <string> infos;
    string info;

    index = arrowKeys(character, index, header);
    
    chosen = character[index];
    stringstream piece(chosen); 
    while(getline(piece, info, '|')) {
        infos.push_back(info);
    }

    return infos;
}


//  MAIN CODE STARTS HERE
int main () {
    Board board(2);

//Beginning Menu
ifstream characterFile("Characters.txt");
string characterLine;                        //stores character and stats into own line
vector <string> characterLines;              //where each line is a stored 

if (characterFile.is_open()) {
    while (getline(characterFile, characterLine)) {
        characterLines.push_back(characterLine);      //stores line into lines as vector
    }
    characterFile.close();
} 
else {
    cout << "Unable to open file." << endl;
    return 1;
}

ifstream advisorFile("Advisor.txt");
string advisorLine;
vector<string> advisorLines;

if(advisorFile.is_open()) {
    while (getline(advisorFile, advisorLine)) {
        advisorLines.push_back(advisorLine);
    }
    advisorFile.close();
}
else {
    cout << "Unable to open file." << endl;
    return 1;
}


//Enter Player Name
string playerName;
Player p[2];
vector<string> path = {"1: Go straight to the Pride lands", "2: Go to cub training"};

for (int i = 0; i < 2; i++) {
    int index = 0;
    cout << "Player " << i + 1 << " Enter Your Name: ";
    cin >> playerName;
    p[i].setName(playerName);

    vector<string> selectionHeader = {playerName +", Please Choose a Character:", 
                                     "Name|Age|Strength|Stamina|Wisdom|PridePoints"};
    vector<string> selected1 = characterSelection(characterLines, index, selectionHeader);
    p[i].storeStats(selected1);

    vector<string> pathHeader = {playerName + " Choose Your Path:"};
    index = arrowKeys(path, index, pathHeader);
    p[i].storePath(index);

    if (index == 1) {
        string randoAdvisor;
        cout << playerName << ": You chose Cub Training, a random Advisor will now be given to you." << endl << endl;
        cout << "----Advisor List----" << endl;
        cout << "Name|Ability" << endl;
        int adSize = advisorLines.size();
        for (int j = 0; j < adSize; j++) {
            cout << j+1 << ": " << advisorLines[j] << endl;
        }
        cout << endl;
        randoAdvisor = advisorLines[dice(rollDice()) - 1];
        p[i].storeAdvisor(randoAdvisor);
        string randoName = p[i].getAdvisorName();
        string randoAbility = p[i].getAdvisorAbility();
        cout << "You got: " << randoName << ", Their ability is: " << randoAbility << endl;
    }
}
//End of menu

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
  // after both players have reached the end, this is run (point calculation, winner, etc.)
 
 


  return 0;
}
