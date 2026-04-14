#pragma once
#include <vector>
#include <string>
using namespace std;

vector<string> CommandType = 
{
    "fd",
    "turn",
    "repeat",
    "clear"
    // add the rest later
};

vector<string> CommandWithContent = 
{
    "fd",
    "turn",
    "repeat"
    // add the rest later
};


struct Command{
    string command;
    string content;
};

vector<Command> parse(string command);
string deloop(string command);
vector<string> vectorize(string command);