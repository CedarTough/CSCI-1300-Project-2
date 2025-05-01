/*
Names: Josiah Galvan 
       Alexander Gholmieh
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
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

        string getAdvisorName();
        string getAdvisorAbility();
        int getPath();

        string getPlayerName();
        int getPridePoints();
        int calculateTotal();

        int getStrength();
        int getWisdom();
        int getStamina();

        vector<string> vectorToFile();
};

struct eventUpdate{
    Board board;
    Player player;
};

#endif
