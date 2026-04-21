#pragma once
#include <vector>
#include <string>
using namespace std;

class Command{
    string command_;

    public :

    Command(string command = ""){command_ = command;};
    string command(){return command_;};
    void commandAt(string c){command_ = c;};
};

class CommandWithContent : public Command{
    string content_;

    public:
    
    CommandWithContent(string content = ""){content_ = content;};
    string content(){return content_;};
    void contentAt(string c){content_ = c;};
};