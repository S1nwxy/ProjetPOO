#include <algorithm>
#include <iostream>
#include "InputHandling.h"
using namespace std;

// Command class with herited classes with or without content
InputHandling::InputHandling(string input) {
    input_ = input;
    CommandList_ = {"fd", "turn", "repeat", "clear"};
    CommandWithParamList_ = {"fd", "turn", "repeat"};
}

void InputHandling::update(){
    deloop();
    vectorize();
}

void InputHandling::parse(){
    bool validCommand = ValidBracketing(input_);
    if(!validCommand){
        cout << "invalid command" << endl;
        return;
    }

    update();

    for(auto it = vectorized_.begin(); it != vectorized_.end(); ++it){
        if(find(CommandWithParamList_.begin(), CommandWithParamList_.end(), *it) != CommandWithParamList_.end()){
            CommandWithParam temp;
            temp.commandAt(*it);
            it++;
            temp.paramAt(*it);
            result_.push_back(temp);
        } else {
            Command temp;
            temp.commandAt(*it);
            result_.push_back(temp);
        }
    }
}

// this function removes repeats and puts them in plaintext
void InputHandling::deloop(){
    size_t i = 0;
    string temp;
    string delooped;
    while(i < input_.length()){ //do the whole string
        if(input_[i] != ' '){ // dont add spaces to word commands
            if(input_[i] != ']'){temp += input_[i];} // bandaid fix for too much ]
        } else { // if its a space we have a whole word
            if(temp != "repeat"){ // TODO : +add debugging for invalid words
                delooped += temp; // add the word
                delooped += ' '; // add a space
                temp.clear();
            } else { // its repeat
                temp.clear();
                string amount_str; // get the repeat command
                while(i < input_.length() && input_[i] != '['){ // get the amount of repeats
                    if(input_[i] != ' '){ //dont get spaces
                        amount_str += input_[i];
                    }
                    i++;
                } // TODO : check if valid POSITIVE number
                if(i < input_.length()) i++; // start after the first "["
                InputHandling repeated;
                int bracket_open = 1; 
                while(i < input_.length() && bracket_open > 0){ // end after "]"
                    if(input_[i] == '['){bracket_open++;}
                    if(input_[i] == ']'){bracket_open--;}
                    repeated.input_ += input_[i]; // get the whole bracketed command
                    i++;
                }
                if(i < input_.length()) i++; // skip the closing bracket
                if(!amount_str.empty()){ // incase repeat doesnt have an amount
                    int repeat_count = stoi(amount_str);
                    for(int j = 0; j < repeat_count; j++){ // add the command x times
                        repeated.deloop();
                        delooped.append(repeated.delooped()); // recursively add delooped commands
                        delooped += ' '; // may cause bugs,  not sure
                    }
                }
                continue; // skip the i++ at the end of the main loop
            }
        }
        i++;
    }
    delooped += temp;
    delooped_ = delooped;
}

// this command turns a string of instructions without repeat [] into a string vector
void InputHandling::vectorize(){
    string temp = "";
    for(size_t i = 0; i < delooped_.length(); i++){ // mid-word
        if(delooped_[i] != ' '){
            temp += delooped_[i];
        } else { // end of word
            if(!temp.empty()){
                vectorized_.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        vectorized_.push_back(temp);
    }
}

bool InputHandling::ValidBracketing(string command){
    int zeroSum = 0;
    for(int i = 0; i< command.length(); i++){
        if(command[i] == '['){ zeroSum++; }
        if(command[i] == ']'){ zeroSum--; }
        if(zeroSum < 0){ return false; }
    }
    return(zeroSum == 0);  
}
