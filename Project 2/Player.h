#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

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
        void storeStats(const vector<string>);
        void storePath(int);
        void storeAdvisor(string);
        void print();
        void setName(string);
        string getAdvisorName();
        string getAdvisorAbility();
};

#endif
