#pragma once
#include <vector>
#include <string>
#include "command.h"
using namespace std;

vector<string> CommandList{
    "fd",
    "turn",
    "clear"
};

vector<string> CommandWithContentList{
    "fd",
    "turn"
};

class RawInput{
    string input_;

    public :

    RawInput(string input);
    string input(){return input_;};

    vector<Command> parse(string command);
    string deloop(string command);
    vector<string> vectorize(string command);
    bool ValidBracketing(string command); //check bracketing
};