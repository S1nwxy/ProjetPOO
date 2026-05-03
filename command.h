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
    virtual string param() {return "";}; 
    void commandAt(string c){command_ = c;};
    // virtual void display() const {std::cout << command_;}; test function

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
    // void paramAt(string c){param_ = c;};
};