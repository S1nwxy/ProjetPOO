#include <algorithm>
#include "rawInput.h"
using namespace std;

vector<string> CommandList = 
{
    "fd",
    "turn",
    "repeat",
    "clear"
    // add the rest later
};

vector<string> CommandWithContentList = 
{
    "fd",
    "turn",
    "repeat"
    // add the rest later
};

// Command class with herited classes with or without content

vector<Command> RawInput::parse(string command){
    bool validCommand = ValidBracketing(command);
    string delooped_command = deloop(command);
    vector<string> vectorized_command = vectorize(delooped_command);
    vector<Command> commands;
    for(auto it = vectorized_command.begin(); it != vectorized_command.end(); ++it){
        if(find(CommandWithContentList.begin(), CommandWithContentList.end(), *it) != CommandWithContentList.end()){
            CommandWithContent temp;
            temp.commandAt(*it);
            it++;
            temp.contentAt(*it);
            commands.push_back(temp);
        } else {
            Command temp;
            temp.commandAt(*it);
            commands.push_back(temp);
        }
    }
    return commands;
}

string RawInput::deloop(string command){ // this function removes repeats and puts them in plaintext
    size_t i = 0;
    string temp;
    string delooped;
    while(i < command.length()){ //do the whole string
        if(command[i] != ' '){ // dont add spaces to word commands
            if(command[i] != ']'){temp += command[i];} // bandaid fix
        } else { // if its a space we have a whole word
            if(temp != "repeat"){ // +add debugging for invalid words
                delooped += temp; // add the word
                delooped += ' '; // add a space
                temp.clear();
            } else { // its repeat 
                temp.clear();
                string amount_str; // get the repeat command
                while(i < command.length() && command[i] != '['){ // get the amount of repeats
                    if(command[i] != ' '){ //dont get spaces
                        amount_str += command[i];
                    }
                    i++;
                }
                if(i < command.length()) i++; // start after the first "["
                string repeated_command;
                int bracket_open = 1; 
                while(i < command.length() && bracket_open > 0){ // end after "]"
                    if(command[i] == '['){bracket_open++;}
                    if(command[i] == ']'){bracket_open--;}
                    repeated_command += command[i]; // get the whole bracketed command
                    i++;
                }
                if(i < command.length()) i++; // skip the closing bracket
                if(!amount_str.empty()){ // incase repeat doesnt have an amount
                    int repeat_count = stoi(amount_str);
                    for(int j = 0; j < repeat_count; j++){ // add the command x times
                        delooped.append(deloop(repeated_command)); // recursively add delooped commands
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

vector<string> RawInput::vectorize(string command){ // this command turns a string of instructions without repeat [] into a string vector
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

bool RawInput::ValidBracketing(string command){
    int zeroSum = 0;
    for(int i = 0; i< command.length(); i++){
        if(command[i] == '['){ zeroSum++; }
        if(command[i] == ']'){ zeroSum--; }
        if(zeroSum < 0){ return false; }
    }
    return(zeroSum == 0);  
}