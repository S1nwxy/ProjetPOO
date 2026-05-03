#pragma once
#include <string>
#include <vector>
#include <cmath>
#include "menu.h"
#include "svgdrawer.h"
#include "InputHandling.h"
#include "turtle.h"
#include "commandHistory.h"

// Author : Johann

// When entering a new program, a litle help message is displayed to inform the user about the different commands available and their usage.
// To simplify the process, a vector of CommandHelp holds all the commands with their associated dexcription. It also allows o have a multi-line description of commands.
// And then the function printHelp loops trough it to display everything. It avoids the burden of displaying everything by hand by allowing to use a for loop.
struct CommandHelp {
    std::string name;
    std::vector<std::string> description;
};

// The main menu class
// Allows to enter a new program, execute it (or execute the last program entered if it didn't change), clear the drawing and exit (of course).
class MenuLogo : public Menu {
    InputHandling* program_;
    Turtle* turtle_;

public:
    MenuLogo();

    void print() const;
    void printHelp(const std::vector<CommandHelp>& commands, int colWidth = 26) const;

    bool newProgram(int);
    bool executeProgram(int);
    bool clearDrawing(int);

    ~MenuLogo();
};
