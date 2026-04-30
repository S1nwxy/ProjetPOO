#pragma once
#include <vector>
#include <string>
#include "command.h"
using namespace std;

vector<string> CommandList = 
{
    "fd",
    "turn",
    "repeat",
    "clear"
    // add the rest later
};

vector<string> CommandWithParamList = 
{
    "fd",
    "turn",
    "repeat"
    // add the rest later
};

class InputHandling{

    string input_;
    string delooped_;
    vector<string> vectorized_;
    vector<Command> result_;

    vector<string> CommandList_;
    vector<string> CommandWithParamList_;
    public :

    InputHandling(string input_ = "");

    void update();
    string input(){return input_;};
    void parse();
    void deloop();
    void vectorize();
    bool ValidBracketing(string command); //check bracketing

};