#ifndef ADVISOR_H
#define ADVISOR_H
#include <iostream>
using namespace std;

class Advisor {
    public:
        Advisor();
        Advisor(string name, string ability, int id);
    private:
        string _name;
        string _ability;
        int _id;
};

#endif