#include <cmath>
#include "turtle.h"
#include "svgdrawer.h"

using namespace std;

#define PI 3.14159265

Turtle::Turtle(){
    drawer_ = new SvgDrawer("logo.html");

    x_ = drawer_->drawingWidth()/2;
    y_ = drawer_->drawingHeight()/2;
    angle_ = 0;

    pen_ = new Pen();
}

void Turtle::step(int amount){
    int newx = x_ + amount * cos(angle_ * PI / 180);
    int newy = y_ + amount * sin(angle_ * PI / 180);
    if(pen_->isActive()){
        drawer_->drawLine(x_, y_, newx, newy);
        // hist->addLine(x_, y_, newx, newy);
    }
    x_ = newx;
    y_ = newy;
}

