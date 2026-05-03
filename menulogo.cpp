#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "menuaction.h"
#include "menulogo.h"
#include "svgdrawer.h"
#include "InputHandling.h"

// Explanations & authorship in the header file

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
    turtle_ = new Turtle();

    turtle_->drawer()->beginDraw("logo.html");
    turtle_->drawTurtle();
    turtle_->drawer()->endDraw();

    addOption(new MenuAction<MenuLogo>("Enter new Logo program", &MenuLogo::newProgram));
    addOption(new MenuAction<MenuLogo>("Execute the Logo program", &MenuLogo::executeProgram));
    addOption(new MenuAction<MenuLogo>("Clear the drawing", &MenuLogo::clearDrawing));
    addOption(new MenuAction<MenuLogo>("Exit the application", &MenuLogo::exitMenu));


}

MenuLogo::~MenuLogo() {
    delete program_;
    // delete drawer_;
    delete turtle_;
}

// The first message shown at the beginning of the main menu.
void MenuLogo::print() const {
    cout << " -- Simple Logo programming language interpreter -- " << endl
         << endl;
    Menu::print();
}

void MenuLogo::printHelp(const std::vector<CommandHelp>& commands, int colWidth) const {
    // Header line :
    // Command      Description
    // -----------------------------
    cout << left
         << setw(colWidth) << "Command"
         << "Description" << endl
         << string(colWidth + 30, '-') << endl;

    for (const auto& cmd : commands) {
        for (size_t i = 0; i < cmd.description.size(); ++i) {
            // For the first line of the description, the command name will be displayed, followed by the description (i = 0)
            // For the other lines, a blank column is displayed in order to indent the description and create multi-line description
            if (i == 0)
                cout << setw(colWidth) << cmd.name;
            else
                cout << setw(colWidth) << "";
            cout << cmd.description[i] << endl;
        }
        // Empty lines between every entry
        cout << endl;
    }
}

// store a line of program with getline (until the newline character \n is found)
bool MenuLogo::newProgram(int) {
    printHelp(commands);
    string program;
    cout << "Enter your program : " << endl;
    getline(cin, program);
    program_->inputAt(program);

    return false;
}

// Executes the program.
// It starts by drawing the lines stored in the history so that we don't lose the previous drawings when opening the html file (call to beginDraw() function).
// Then it parse tne input and execute the functions accordingly
// The drawing logic (calls to drawLine) is handled by Turtle's step function and Turtle's drawer_ attribute
// The last part of the program is here to show the coordinates of the Turtle while it's moving during the execution.
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
        } else if(cmd->command() == "cpen"){
            turtle_->pen()->changeState();
        }
    }

    turtle_->drawTurtle();
    turtle_->drawer()->endDraw();
    cout << "Turtle coordinates (x, y) : " << turtle_ -> x() << " " << turtle_ -> y() <<endl;
    cout << "Turle angle (degrees) : " << turtle_ -> angle() * 180 / M_PI << endl << endl;
    return false;
}

// clear the drawing by clearing the history so that we don't draw previous programs again on the next execution
// Then it resets the Turtle origin to the center
// And finally it reopens the html file to clear everything and draw the turle indicator
bool MenuLogo::clearDrawing(int) {
    turtle_->hist()->lines().clear();
    turtle_->xAt(turtle_->drawer()->drawingWidth()/2);
    turtle_->yAt(turtle_->drawer()->drawingHeight()/2);
    turtle_->angleAt(0);
    turtle_->drawer()->beginDraw("logo.html");
    turtle_->drawTurtle();
    turtle_->drawer()->endDraw();
    return false;
}
