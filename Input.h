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

class Input{

    string input_;
    string delooped_;
    vector<string> vectorized_;
    vector<Command> result_;

    vector<string> CommandList_;
    vector<string> CommandWithParamList_;
    public :

    Input(string input = "");
    string input(){return input_;};
    vector<Command> parse();
    string deloop();
    vector<string> vectorize();
    bool ValidBracketing(string command); //check bracketing

};