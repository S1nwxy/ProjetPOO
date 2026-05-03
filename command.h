#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//original author : Axel, modifications : Johann

class Command{ // this class holds a command
    string command_;

    public :

    Command(string command = ""){command_ = command;};
    string command(){return command_;};
    // In InputHandling, we hold a vector of Command. 
    // But when executing the program we need to acces the param_ attribute, which is only in CommandWithParam class. 
    // So we have to define a virtual param() accessor function that will be replaced by the CommandWithParam own param() function.
    virtual string param() {return "";}; 
    void commandAt(string c){command_ = c;};

    virtual ~Command() = default;
};

class CommandWithParam : public Command{ // this subclass holds a command's parameter
    string param_;

    public:
    
    CommandWithParam(string param = "") : Command() {
        param_ = param;
    };
    CommandWithParam(string command, string param) {
        commandAt(command);
        param_ = param;
    };
    string param() {return param_;};
};
