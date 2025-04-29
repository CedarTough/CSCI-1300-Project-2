#include <iostream>
#include <cstdlib> 
#include "Board.h"
#include "Player.h"
using namespace std;

vector <string> eventSelection (string event) {

    string info;
    vector <string> infos;
    stringstream piece(event); 
    while(getline(piece, info, '|')) {
        infos.push_back(info);
    }

    return infos;
}



eventUpdate eventRed(eventUpdate eventUpdater, int playerNo){
    cout<<"Bruh. You've landed on a graveyard tile"<<endl;
    eventUpdater.player.setStrength(-100);
    eventUpdater.player.setStamina(-100);
    eventUpdater.player.setWisdom(-100);
    eventUpdater.board.movePlayer(playerNo, -10);

    return eventUpdater;
}

eventUpdate eventGreen(eventUpdate eventUpdater, int playerNo){
    cout<<"Something happened :O"<<endl;
    


ifstream eventFile("random_events.txt");
string eventLine;                        //stores character and stats into own line
vector <string> eventLines;              //where each line is a stored 
vector <string> eventVector;

if (eventFile.is_open()) {
    while (getline(eventFile, eventLine)) {
        eventLines.push_back(eventLine);      //stores line into lines as vector
    }
    eventFile.close();
} 
else {
    cout << "Unable to open event file." << endl;
    return eventUpdater;;
}

bool eventFound = false;
while (!eventFound){

int evSize = eventLines.size();
srand(time(0));
eventVector = eventSelection(eventLines[rand() % evSize]);
if (eventUpdater.board.playerBoard[playerNo] == stoi(eventVector[1]))
eventFound=true;
}
cout<<eventVector[0]<<endl;
if (eventUpdater.player.advisorNo == eventVector[2]){
    cout << "Effect is nullifed because of your advisor"<<endl;
    return eventUpdater;
}

cout << "You gain/lose "<<eventVector[3] << " pride points.";
eventUpdater.player.setPridePoints(stoi(eventVector[3]));
return eventUpdater;
}

eventUpdate eventBlue(eventUpdate eventUpdater){
    cout<<"wowowowowowow you found an oasis. Your character feels more buff"<<endl;
    eventUpdater.player.setStrength(200);
    eventUpdater.player.setStamina(200);
    eventUpdater.player.setWisdom(200);

    return eventUpdater;
}

eventUpdate eventPurple(eventUpdate eventUpdater){
    cout<<"Time for a riddle"<<endl;

    ifstream riddleFile("random_riddles.txt");
    string riddleLine;                        //stores character and stats into own line
    vector <string> riddleLines;              //where each line is a stored 
    vector <string> riddleVector;
    
    if (riddleFile.is_open()) {
        while (getline(riddleFile, riddleLine)) {
            riddleLines.push_back(riddleLine);      //stores line into lines as vector
        }
        riddleFile.close();
    } 
    else {
        cout << "Unable to open riddle file." << endl;
        return eventUpdater;
    }
    
    
    int evSize = riddleLines.size();
    string answer;

    srand(time(0));
    riddleVector = eventSelection(riddleLines[rand() % evSize]);
    cout<<riddleVector[0]<<endl;
    cin >> answer;

    if (answer == riddleVector[1]){
        cout << "Correct. Good job, you get 500 wisdom points"<<endl;
        eventUpdater.player.setWisdom(500);
        return eventUpdater;
    }
    
    cout << "Well, you can't win them all"<<endl;
    return eventUpdater;
    }
    


    

eventUpdate eventBrown(eventUpdate eventUpdater, int playerNo){
    cout<<"The Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost."<<endl;
    eventUpdater.player.setStamina(-300);
    eventUpdater.board.movePlayer(playerNo, -eventUpdater.player.roll);
    eventUpdater.board.displayBoard();
    return eventUpdater;
}

eventUpdate eventPink(eventUpdate eventUpdater){
    cout<<"You landed on a counseling tile"<<endl;
    eventUpdater.player.setStrength(300);
    eventUpdater.player.setStamina(300);
    eventUpdater.player.setWisdom(300);
    
    // function to keep advisor or choose a new one

    return eventUpdater;
}

eventUpdate eventOrange(eventUpdate eventUpdater){
    cout<<"Congrats, you have finished"<<endl;
    return eventUpdater;
}

eventUpdate eventGrey(eventUpdate eventUpdater){
    cout<<"Back at the start RIP"<<endl;
    return eventUpdater;
}
