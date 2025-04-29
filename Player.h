#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

class Player {
    private:
        string playerName;
        string characterName;
        string advisorName;
        string advisorAbility;
        int age;
        int strength;
        int stamina;
        int wisdom;
        int pridePoints;
        int path;
    public:
        Player();
        int roll;
        string advisorNo;
        void storeStats(const vector<string>);
        void storePath(int);
        void storeAdvisor(string);
        void print();
        void setName(string);
        void setStrength(int);
        void setStamina(int);
        void setWisdom(int);
        void setPridePoints(int);
        string getCharacterName();
        int getStrength();
        int getStamina();
        int getWisdom();
        string getAdvisorName();
        string getAdvisorAbility();
        int getPath();
        string getPlayerName();
};

struct eventUpdate{
    Board board;
    Player player;
};

#endif
