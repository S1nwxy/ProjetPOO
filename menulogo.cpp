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
    addOption(new MenuAction<MenuLogo>("Enter new Logo program",
                                       &MenuLogo::newProgram));
}

void MenuLogo::print() const {
    cout << " -- Simple Logo programming language interpreter -- " << endl
         << endl;
    Menu::print();
}

void MenuLogo::printHelp(const std::vector<CommandHelp>& commands, int colWidth) const {
    std::cout << std::left
              << std::setw(colWidth) << "Command"
              << "Description\n"
              << std::string(colWidth + 30, '-') << "\n";

    for (const auto& cmd : commands) {
        for (size_t i = 0; i < cmd.description.size(); ++i) {
            if (i == 0)
                std::cout << std::setw(colWidth) << cmd.name;
            else
                std::cout << std::setw(colWidth) << ""; // colonne gauche vide
            std::cout << cmd.description[i] << "\n";
        }
        std::cout << "\n"; // ligne vide entre les commandes
    }
}


bool MenuLogo::newProgram(int) {
    string program;
    printHelp(commands);
    cout << "Enter your program : " << endl;
    getline(cin, program);

#ifdef test
    cout << deloop(program);
    cout << endl;
    pauseConsole();
#endif

    return false;
}
