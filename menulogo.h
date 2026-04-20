#pragma once

#include "menu.h"
#include <vector>

struct CommandHelp {
    std::string name;
    std::vector<std::string> description;
};

class MenuLogo : public Menu {
    // bool isSubMenu;
public:
    MenuLogo();

    void print() const;
    void printHelp(const std::vector<CommandHelp>& commands, int colWidth = 26) const;

    bool newProgram(int);
};
