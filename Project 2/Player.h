#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Character.h"
#include "Advisor.h"

using namespace std;

class Player {
    public:

    private:
        int _player_num;
        const static int _max_advisors = 3;
        Character _cub;
        Advisor _advisor[_max_advisors];
};

#endif