#include "turtle.h"
#include <cmath>
using namespace std;

#define PI 3.14159265

Turtle::Turtle(SvgDrawer * drawer, Pen * pen, double x, double y, double angle){
    x_ = x;
    y_ = y;
    angle_ = angle;
    drawer_ = drawer;
    pen_ = pen;
}

void Turtle::step(int amount){
    int newx = x_ + amount * cos(angle_ * PI / 180);
    int newy = y_ + amount * sin(angle_ * PI / 180);
    if(pen_->isActive()){
        drawer_->drawLine(x_, y_, newx, newy);
    }
    x_ = newx;
    y_ = newy;
}

