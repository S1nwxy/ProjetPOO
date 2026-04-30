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

class CommandWithParam : public Command{
    string param_;

    public:
    
    CommandWithParam(string param = ""){param = param_;};
    string param(){return param_;};
    void paramAt(string c){param_ = c;};
};