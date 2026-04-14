#include "turtle.h"
#include "svgdrawer.h"
#include "menu.h"
#include "menuoption.h"
#include "menuaction.h"
#include <string>

int main(){
    SvgDrawer * d = new SvgDrawer("drawing", 1920, 1080);
    Turtle t = Turtle(d);
    return 0;
    delete d; // should delete itself
}