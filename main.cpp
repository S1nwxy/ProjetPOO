#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "utils.h"
#include <string>
#include <iostream>

int main(){
    std::string test1 = "fd 10 turn 20 ";
    std::string test2 = "fd 10 repeat 2 [turn 10] clear"; // fd 10 turn 10 turn 10 clear
    std::cout << deloop(test1) << endl;
    std::cout << deloop(test2) << endl;
    return 0;
}