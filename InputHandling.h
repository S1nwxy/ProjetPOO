#pragma once
#include <vector>
#include <string>
#include "command.h"
using namespace std;

class InputHandling{

    string input_;
    string delooped_;
    vector<string> vectorized_;
    vector<Command*> result_;

    vector<string> CommandList_;
    vector<string> CommandWithParamList_;
    public :

    InputHandling(string input = "");

    void update();
    string input(){return input_;};
    void inputAt(string input) {input_ = input;};
    string delooped() {return delooped_;};
    vector<string> vectorized() {return vectorized_;};
    vector<Command*>& result() {return result_;};
    void parse();
    void deloop();
    void vectorize();
    bool ValidBracketing(string command); //check bracketing
    
    ~InputHandling() {
        for(auto it : result_) {
            delete it;
        }
        vectorized_.clear();
        result_.clear();
    }

};
