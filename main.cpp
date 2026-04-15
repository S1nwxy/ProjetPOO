#include <string>
#include <iostream>
#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include "utils.h"

using namespace std;

int main(){
    SvgDrawer * d = new SvgDrawer("drawing", 1920, 1080);
    Turtle t = Turtle(d);
    string command = "repeat 2 [repeat 2 [fd 100]]";
    std::cout << deloop(command);
    return 0;
    delete d; // should delete itself
}
