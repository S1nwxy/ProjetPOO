#pragma once
#include <vector>
#include <string>
using namespace std;

enum CommandType{
    fd,
    turn,
    repeat
};

struct Command{
    CommandType c;
    string content;
};

// vector<Command> parse(string command);
