#include <algorithm>
#include "Input.h"
using namespace std;

// Command class with herited classes with or without content

vector<Command> Input::parse(){
    bool validCommand = ValidBracketing(input_);
    Input delooped_command = Input(this->deloop());
    vector<string> vectorized_command = vectorize(delooped_command.input());
    vector<Command> commands;
    for(auto it = vectorized_command.begin(); it != vectorized_command.end(); ++it){
        if(find(CommandWithParamList.begin(), CommandWithParamList.end(), *it) != CommandWithParamList.end()){
            CommandWithParam temp;
            temp.commandAt(*it);
            it++;
            temp.paramAt(*it);
            commands.push_back(temp);
        } else {
            Command temp;
            temp.commandAt(*it);
            commands.push_back(temp);
        }
    }
    return commands;
}

string Input::deloop(){ // this function removes repeats and puts them in plaintext
    size_t i = 0;
    string temp;
    string delooped;
    while(i < input_.length()){ //do the whole string
        if(input_[i] != ' '){ // dont add spaces to word commands
            if(input_[i] != ']'){temp += input_[i];} // bandaid fix
        } else { // if its a space we have a whole word
            if(temp != "repeat"){ // +add debugging for invalid words
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
                }
                if(i < input_.length()) i++; // start after the first "["
                Input repeated_command;
                int bracket_open = 1; 
                while(i < input_.length() && bracket_open > 0){ // end after "]"
                    if(input_[i] == '['){bracket_open++;}
                    if(input_[i] == ']'){bracket_open--;}
                    repeated_command.input_ += input_[i]; // get the whole bracketed command
                    i++;
                }
                if(i < input_.length()) i++; // skip the closing bracket
                if(!amount_str.empty()){ // incase repeat doesnt have an amount
                    int repeat_count = stoi(amount_str);
                    for(int j = 0; j < repeat_count; j++){ // add the command x times
                        delooped.append(repeated_command.deloop()); // recursively add delooped commands
                        delooped += ' '; // may cause bugs,  not sure
                    }
                }
                continue; // skip the i++ at the end of the main loop
            }
        }
        i++;
    }
    delooped += temp;
    return delooped;
}

vector<string> Input::vectorize(string command){ // this command turns a string of instructions without repeat [] into a string vector
    vector<string> vectorized;
    string temp = "";
    for(size_t i = 0; i < command.length(); i++){ // mid-word
        if(command[i] != ' '){
            temp += command[i];
        } else { // end of word
            if(!temp.empty()){
                vectorized.push_back(temp);
                temp.clear();
            }
        }
    }
    if(!temp.empty()){
        vectorized.push_back(temp);
    }
    return vectorized;
}

bool Input::ValidBracketing(string command){
    int zeroSum = 0;
    for(int i = 0; i< command.length(); i++){
        if(command[i] == '['){ zeroSum++; }
        if(command[i] == ']'){ zeroSum--; }
        if(zeroSum < 0){ return false; }
    }
    return(zeroSum == 0);  
}