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

void pause() {
    cout << "Press Enter to Return to Main Menu..." << endl;
    cin.ignore(100000, '\n');
    cin.get();
}

eventUpdate runEvent(int playerNo,int pos,eventUpdate eventUpdater){
    int color = eventUpdater.board.returnTileColor(playerNo,pos);  // Change function names when we know what each color reps.
    if (color == 'R') {
        eventUpdater = eventRed(eventUpdater, playerNo);
    }
    else if (color == 'G') {
        eventUpdater = eventGreen(eventUpdater, playerNo);
    }
    else if (color == 'B') {
        eventUpdater = eventBlue(eventUpdater);
    }
    else if (color == 'U') {
        eventUpdater = eventPurple(eventUpdater);
    }
    else if (color == 'N') {
        eventUpdater = eventBrown(eventUpdater, playerNo);
    }
    else if (color == 'P') {
        eventUpdater = eventPink(eventUpdater);
    }
    else if (color == 'O') {
        eventUpdater = eventOrange(eventUpdater);
    }
    else if (color == 'Y') {
        eventUpdater = eventGrey(eventUpdater);
  }
  return eventUpdater;
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
        board.movePlayer(playerNumber,1); // moves once cause function
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

vector<string> characterSelection (const vector<string> character, int index) {
    string chosen;
    vector <string> infos;
    string info;    
    chosen = character[index];
    stringstream piece(chosen); 
    while(getline(piece, info, '|')) {
        infos.push_back(info);
    }

    return infos;
}

void compareStats (int stat1, int stat2, string name1, string name2) {
    system("cls");
    if (stat1 > stat2) {
        cout << name1 << " Is in the lead" << endl;
        cout << name1 << " has " << stat1 << " Points" <<endl;
        cout << name2 << " has " << stat2 << " Points" << endl;
    }
    else if (stat1 < stat2) {
        cout << name2 << " Is in the lead" << endl;
        cout << name2 << " has " << stat2 << " Points" << endl;
        cout << name1 << " has " << stat1 << " Points" << endl;
    }
    else if (stat1 == stat2) {
        cout << "Neither Player are in the Lead" << endl;
        cout << "Both Players are at " << stat1 << " Points" << endl;
    }
}

bool displayMenu (int index, Player player[], Board board, string name) {
    vector<string> mainHeader = {name + " Its Your Turn!", "Main Menu: Select an Option to Continue"};
    vector<string> adHeader = {"----View Name or Ability----"};
    vector<string> statHeader = {"----Choose Stat To Compare----"};
    vector<string> adMenu = {"1: Advisor Name", "2: Advisor Ability", "-Return to Main Menu-"};
    vector<string> menu = {"1. Move Forward", "2. Review Advisor",
        "3. View Board", "4. Compare Progress", "5. Check Player Progress"};
    vector<string> statMenu = {"1: Compare Strength", "2: Compare Stamina", "3: Compare Wisdom",
         "4: Compare Pride Points"};

    int chosenIndex = 0;
    chosenIndex = arrowKeys(menu, chosenIndex, mainHeader);

    switch(chosenIndex) {
        case 0: //move foward
            return false;
        case 1: //Review Advisor
            system("cls");
            if(player[index].getAdvisorName() == "") {
                cout << "You have no Advisor" << endl;
                pause();
                break;
            }
            else {
                bool review = true;
                while(review) {
                    int newIndex = 0;
                    newIndex = arrowKeys(adMenu, newIndex, adHeader);
                    switch(newIndex) {
                    case 0:
                        system("cls");
                        cout << "Your Advisors Name is: " << player[index].getAdvisorName() << endl;
                        cout << "Press Enter to Return to Advisor Menu..." << endl;
                        cin.ignore();
                        cin.ignore();
                        cin.get();
                        break;
                    case 1:
                        system("cls");
                        cout << "Your Advisors Ability is: " << player[index].getAdvisorAbility() << endl;
                        cout << "Press Enter to Return to Advisor Menu..." << endl;
                        cin.ignore();
                        cin.ignore();
                        cin.get();
                        break;
                    case 2:
                        review = false;
                    }
                }
            }
            break;
        case 2: //View Board
            system("cls");
            board.displayBoard();
            pause();
            break;

        case 3: {//Check Standing
            system("cls");
            int newIndex = 0;
            newIndex = arrowKeys(statMenu, newIndex, statHeader);
            switch(newIndex) {
                case 0:
                    system("cls");
                    compareStats(player[0].getStrength(), player[1].getStrength(),
                    player[0].getPlayerName(), player[1].getPlayerName());
                    break;
                case 1:
                    system("cls");
                    compareStats(player[0].getStamina(), player[1].getStamina(),
                    player[0].getPlayerName(), player[1].getPlayerName());
                    break;
                case 2:
                    system("cls");
                    compareStats(player[0].getWisdom(), player[1].getWisdom(),
                    player[0].getPlayerName(), player[1].getPlayerName());
                    break;
                case 3:
                    system("cls");
                    compareStats(player[0].getPridePoints(), player[1].getPridePoints(),
                    player[0].getPlayerName(), player[1].getPlayerName());
                    break;
            }
        }
            pause();
            break;
        
        case 4: //Check Player Progress
            system("cls");
            player[index].print();
            cout << endl;
            pause();
            break;
    }
    return true;
}

//  MAIN CODE STARTS HERE
int main () {
    Board board(2);
    eventUpdate eventUpdater; 

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
string enter;
Player p[2];
vector<string> path = {"1: Go to cub training", "2: Go straight to the Pride lands", "--See Path Details--"};

for (int i = 0; i < 2; i++) {
    int index = 0;
    int chosenIndex;
    cout << "Player " << i + 1 << " Enter Your Name: ";
    cin >> playerName;
    p[i].setName(playerName);

    vector<string> selectionHeader = {playerName +", Please Choose a Character:", 
                                     "Name|Age|Strength|Stamina|Wisdom|PridePoints"};
    chosenIndex = arrowKeys(characterLines, index, selectionHeader);
    vector<string> selected = characterSelection(characterLines, chosenIndex);
    p[i].storeStats(selected);

    characterLines.erase(characterLines.begin() + chosenIndex);

    vector<string> pathHeader = {playerName + " Choose Your Path:"};
    index = arrowKeys(path, index, pathHeader);
   
    while (index == 2) {
        system("cls");
        cout << "----Cub Training----" << endl;
        cout << "Spend 5,000 pride to gain a random Advisor" << endl;
        cout << "+500 Strength and Stamina" << endl;
        cout << "+1,000 Wisdom points" << endl << endl;
        cout << "----Straight to Pride Lands----" << endl;
        cout << "Gain 5,000 pride points" << endl;
        cout << "+200 Strength, Stamina, and Wisdom Points" << endl << endl;
        cout << "Press Enter to return to Path Selection..." << endl;
        cin.ignore(100000, '\n');
        cin.get();
        index = arrowKeys(path, index, pathHeader);
    }
        p[i].storePath(index);

    if (index == 0) {
        p[i].setPridePoints(-5000);
        p[i].setStamina(500);
        p[i].setStrength(500);
        p[i].setWisdom(1000);

        string randoAdvisor;
        cout << endl;
        cout << playerName << ": You chose Cub Training, a random Advisor will now be given to you." << endl << endl;
        cout << "----Advisor List----" << endl;
        cout << "Name|Ability" << endl;
        int adSize = advisorLines.size();
        for (int j = 0; j < adSize; j++) {
            cout << j+1 << ". " << advisorLines[j] << endl;
        }
        cout << endl;
        int rollAdvisor = rand() % advisorLines.size();
        randoAdvisor = advisorLines[rollAdvisor];
        dice(rollAdvisor + 1);
        p[i].storeAdvisor(randoAdvisor);
        p[i].advisorNo = rollAdvisor;

        advisorLines.erase(advisorLines.begin() + (rollAdvisor - 1));

        string randoName = p[i].getAdvisorName();
        string randoAbility = p[i].getAdvisorAbility();
        cout << "You got: " << randoName << ", Their ability is: " << randoAbility << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.ignore(100000, '\n');
        cin.get();
    }
    if (index == 1) {
        p[i].setPridePoints(5000);
        p[i].setStamina(200);
        p[i].setStrength(200);
        p[i].setWisdom(200);
    }
}
//End of menu

    board.playerBoard[0] = p[0].getPath();   // 0 means start on cub training. One is for pride lands ask once game start
    board.playerBoard[1] = p[1].getPath();   // Can also be used in the future for switching boards mechanic :O

    system("cls");
    cout << "Time to Start!" << endl;
    cout << "These are your Starting Positions!" << endl;
    board.displayBoard(); // initial positions
    cout << "Press Enter to Begin!" << endl;
    cin.ignore(100000, '\n');
    cin.get();
   
  bool playerNotDone[2] = {true, true}; // tests to see if players have reached the goal
  
  // while loop as we play, main gameplay loop
   while (playerNotDone[0] || playerNotDone[1]){ 
    for (int i=0;i<2;i++){
        string name = p[i].getPlayerName();

    if (playerNotDone[i]){
        // Insert menu function here that will be used for chossing actions!!!!!!!
        bool choosing = true;
        while(choosing) {
            choosing = displayMenu(i, p, board, name);
        }
        int moved;
        cout << endl;
        cout << name <<", Roll Your Dice To Move (Press Enter)";
        cin.ignore(100000, '\n');
        cin.get();

        moved = dice(rollDice());
        p[i].roll = moved;
        board = movePhase(moved,i,board);
    }
    else{
        cin.get(); // gets can be commented out once the menus done
        cout<< "Player "<< i+1 << " has finished \n";
    }

    if (board.getPlayerPosition(i)>=51){
        playerNotDone[i]=false;
        board._player_position[i] = 51;
    }

    board.displayBoard();  // displays board after each individual move

    eventUpdater.board = board;
    eventUpdater.player = p[i];
    eventUpdater = runEvent(i,board.getPlayerPosition(i),eventUpdater);  // After displaying, we want to run the event
    board = eventUpdater.board;
    p[i] = eventUpdater.player;

    cout << endl;
    cout << "Press Enter to Continue..." << endl;
    cin.ignore(100000, '\n');
    cin.get();
    } 
  }
  // after both players have reached the end, this is run (point calculation, winner, etc.)
  cout << "Both Players Have Reached the End Congratulations!" << endl << endl;
  cout << "And the Winner is..." << endl;

  if(p[0].calculateTotal() > p[1].calculateTotal()) {
    cout << p[0].getPlayerName() << " Has Won with a total of " << p[0].getPridePoints() << " Pride Points!" << endl;
    cout << "While " << p[1].getPlayerName() << " came in second with " << p[1].getPridePoints() 
    << " Pride Points!" << endl;
  }
  else if(p[0].calculateTotal() < p[1].calculateTotal()) {
    cout << p[1].getPlayerName() << " Has Won with a total of " << p[1].getPridePoints() << " Pride Points!" << endl;
    cout << "While " << p[0].getPlayerName() << " came in second with " << p[0].getPridePoints() 
    << " Pride Points!" << endl;
  }
 
  return 0;
}
