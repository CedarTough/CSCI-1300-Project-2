#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;

class Character {
    public:
        Character();
        Character(string name, int age, int strength, int stamina, int wisdom, int pridePoints, bool isAvaliable);
    private:
        string _name;
        int _age;
        int _strength;
        int _stamina;
        int _wisdom;
        int _pride_Points;
        bool _is_Avaliable;
};

#endif
