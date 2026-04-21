#pragma once
#include <vector>
#include <string>
using namespace std;


class Command{
    string command_;

    public :

    Command(string command = "");
    string command(){return command_;};
    void commandAt(string c){command_ = c;};
};

class CommandWithContent : public Command{
    string content_;

    public:
    
    CommandWithContent(string content = "");
    string content(){return content_;};
    void contentAt(string c){content_ = c;};
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

