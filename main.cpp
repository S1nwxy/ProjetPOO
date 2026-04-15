#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "utils.h"
#include <string>
#include <iostream>

int main(){
    std::string test = "fd 10 repeat 2 [turn 10 repeat 2 [turn -15]] clear";
    std::cout << deloop(test);
    return 0;
}