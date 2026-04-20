#include "menulogo.h"
#include "menu.h"
#include "menuaction.h"
#include "utils.h"
#include <iomanip>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

std::vector<CommandHelp> commands = {
    { "fd number",   { "Move the turtle forward by the amount specified by number",
                        "Example : fd 100" }},
    { "turn number", { "Turn the turtle by an angle specified by number",
                        "Enter a positive number to turn right and a negative number to turn left",
                        "Example : turn 90, turn -45" }},
    { "repeat number [commands]", { "Repeat a subset of commands a certain number of times",
                                    "Example : repeat 2 [fd 100 turn 15 fd 50]",
                                    "You can chain multiple repeat commands",
                                    "Example : repeat 2 [repeat 2 [fd 100]]" }},
    { "clear", {"Clear the screen of any drawings" }}
};

MenuLogo::MenuLogo() : Menu("Main Menu") {
    program_ = "";
    addOption(new MenuAction<MenuLogo>("Enter new Logo program", &MenuLogo::newProgram));

    addOption(new MenuAction<MenuLogo>("Execute the Logo program", &MenuLogo::executeProgram));
}

void MenuLogo::print() const {
    cout << " -- Simple Logo programming language interpreter -- " << endl
         << endl;
    Menu::print();
}

void MenuLogo::printHelp(const std::vector<CommandHelp>& commands, int colWidth) const {
    cout << left
         << setw(colWidth) << "Command"
         << "Description" << endl
         << string(colWidth + 30, '-') << endl;

    for (const auto& cmd : commands) {
        for (size_t i = 0; i < cmd.description.size(); ++i) {
            if (i == 0)
                cout << setw(colWidth) << cmd.name;
            else
                cout << setw(colWidth) << ""; // colonne gauche vide
            cout << cmd.description[i] << endl;
        }
        cout << endl; // ligne vide entre les commandes
    }
}


bool MenuLogo::newProgram(int) {
    printHelp(commands);
    cout << "Enter your program : " << endl;
    getline(cin, program_);

    return false;
}

bool MenuLogo::executeProgram(int) {
    cout << "Delooped Program" << endl;
    string deloopedProgram = deloop(program_);
    cout << deloopedProgram << endl;

    cout << "Vectorized Program" << endl;
    vector<string> vectorizedProgram = vectorize(deloopedProgram);
    int i = 1;
    for (string str: vectorizedProgram) {
        cout << i << " " + str + " ";
        i++;
    }
    cout << endl;

    return false;
}
