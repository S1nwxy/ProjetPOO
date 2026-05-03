#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Command{
    string command_;

    public :

    Command(string command = ""){command_ = command;};
    string command(){return command_;};
    virtual string param() {return "";};
    void commandAt(string c){command_ = c;};
    virtual void display() const {std::cout << command_;};

    virtual ~Command() = default;
};

class CommandWithParam : public Command{
    string param_;

    public:
    
    CommandWithParam(string param = "") : Command() {
        param_ = param;
    };
    CommandWithParam(string command, string param) {
        commandAt(command);
        param_ = param;
    };
    string param() override {return param_;};
    void paramAt(string c){param_ = c;};
    void display() const override {
        Command::display();
        cout << ' ' << param_;
    }
};
