#pragma once
#include <vector>
#include <string>
using namespace std;


struct Command{
    string command;
    string content;
};

vector<Command> parse(string command);
string deloop(string command);
vector<string> vectorize(string command);