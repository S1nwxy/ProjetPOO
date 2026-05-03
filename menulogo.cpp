#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "menuaction.h"
#include "menulogo.h"
#include "svgdrawer.h"
#include "InputHandling.h"

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
    { "cpen", {"Changes the state of the pen (up/down)" }}
};

MenuLogo::MenuLogo() : Menu("Main Menu") {
    program_ = new InputHandling();
    // drawer_ = new SvgDrawer("logo.html");
    turtle_ = new Turtle();

    addOption(new MenuAction<MenuLogo>("Enter new Logo program", &MenuLogo::newProgram));
    addOption(new MenuAction<MenuLogo>("Execute the Logo program", &MenuLogo::executeProgram));
    addOption(new MenuAction<MenuLogo>("Exit the application", &MenuLogo::exitMenu));
}

MenuLogo::~MenuLogo() {
    delete program_;
    // delete drawer_;
    delete turtle_;
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
    string program;
    cout << "Enter your program : " << endl;
    getline(cin, program);
    program_->inputAt(program);

    return false;
}

bool MenuLogo::executeProgram(int) {
    turtle_->drawer()->beginDraw("logo.html");
    
    for(auto line : turtle_ -> hist() -> lines()){
        turtle_-> drawer() -> drawLine(line.x1, line.y1, line.x2, line.y2);
    }
    
    program_->parse();
    cout << program_->input() << endl;
    for(const auto& cmd : program_->result()) {
        if(cmd->command() == "fd") {
            turtle_->step(stoi(cmd->param()));
        } else if(cmd->command() == "turn") {
            turtle_->turn(stod(cmd->param()));
        } else if(cmd->command() == "clear") {
            turtle_->xAt(turtle_->drawer()->drawingWidth()/2);
            turtle_->yAt(turtle_->drawer()->drawingHeight()/2);
            turtle_->angleAt(0);
        } else if(cmd->command() == "cpen"){
            turtle_->pen()->changeState();
        }
    }

    turtle_->drawTurtle();
    turtle_->drawer()->endDraw();
    return false;
}
