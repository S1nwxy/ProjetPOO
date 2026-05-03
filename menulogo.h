#pragma once

#include <string>
#include <vector>
#include "menu.h"
#include "svgdrawer.h"
#include "InputHandling.h"
#include "turtle.h"
#include "commandHistory.h"

struct CommandHelp {
    std::string name;
    std::vector<std::string> description;
};

class MenuLogo : public Menu {
    InputHandling* program_;
    Turtle* turtle_;
    //CommandHistory *hist_;
    //SvgDrawer * drawer_;

public:
    MenuLogo();

    void print() const;
    void printHelp(const std::vector<CommandHelp>& commands, int colWidth = 26) const;

    bool newProgram(int);
    bool executeProgram(int);

    ~MenuLogo();
};
