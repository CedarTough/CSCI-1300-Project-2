#include <iostream>
#include <vector>
#include <sstream>
#include "Player.h"

using namespace std;

Player::Player() {
    playerName = "";
    characterName = "";
    advisorName = "";
    advisorAbility = "";
    age = 0;
    strength = 0;
    stamina = 0;
    wisdom = 0;
    pridePoints = 0;
    path = 0;
}

void Player::storeStats(const vector<string> values) {
    characterName = values[0];
    age = stoi(values[1]);
    strength = stoi(values[2]);
    stamina = stoi(values[3]);
    wisdom = stoi(values[4]);
    pridePoints = stoi(values[5]);
}

void Player::storePath(int value) {
    path = value;
}

void Player::storeAdvisor(string givenAdvisor) {
    string info;
    vector<string> infos;
    stringstream part(givenAdvisor);
    while(getline(part, info, '|')) {
        infos.push_back(info);
    }
    advisorName = infos[0];
    advisorAbility = infos[1];
}

void Player::setName(string name) {
    playerName = name;
}

string Player::getAdvisorName() {
    return advisorName;
}

string Player::getAdvisorAbility() {
    return advisorAbility;
}

void Player::print(){
    cout << "Player Name: " << playerName << endl;
    cout << "Character Name: " << characterName << endl;
    cout << "Age: " << age << endl;
    cout << "Strength: " << strength << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Pride Points: " << pridePoints << endl;
    cout << "Path Choosen: ";
    if (path == 0) {
        cout << "Pride Lands" << endl;
    }
    else if (path == 1) {
        cout << "Cub Training" << endl;
    }
    cout << "Advisor: ";
    if (advisorName == "") {
        cout << "None" << endl;
    }
    else {
        cout << advisorName << endl;
        cout << "Advisor Ability: " << advisorAbility;
    }
}
