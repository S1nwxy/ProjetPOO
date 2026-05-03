#pragma once
#include <vector>
#include <string>
#include "command.h"
using namespace std;

// Author : Axel, modifications : Johann

// this file holds the InputHandling class, which takes a string input from the user (a command)
// and turns it into an interpretable vector of commands for the system.
// it handles parsing, and (somewhat) error-checking.

class InputHandling{

    string input_; // raw user input
    string delooped_; // delooped (aka repeats are transformed into straight commands) command
    vector<string> vectorized_; // each individual word is in a separate string (for handling)
    vector<Command*> result_; // final result : a vector of commands

    vector<string> CommandList_; // this list is initialized in the constructor and is used in parse()
    vector<string> CommandWithParamList_; // this one as well
    public :

    InputHandling(string input = "");
    string input(){return input_;};
    void inputAt(string input) {input_ = input;};
    string delooped() {return delooped_;};
    vector<string> vectorized() {return vectorized_;};
    vector<Command*>& result() {return result_;};

    void update(); // this function deloops and vectorizes the raw input
    void parse(); // this function takes the vectorized command and formats it into Command classes
    void deloop(); // this function removes the "repeat" commands for easier parsing
    void vectorize(); // this function separates the delooped input into a string vector of individual words
    bool ValidBracketing(string command); //checks bracketing
    
    ~InputHandling() { // destructor
        for(auto it : result_) {
            delete it;
        }
        vectorized_.clear();
        result_.clear();
    }

};
