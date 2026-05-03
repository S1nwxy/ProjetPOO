#include <cmath>
#include "turtle.h"
#include "svgdrawer.h"

using namespace std;

#define PI 3.14159265

Turtle::Turtle(){
    drawer_ = new SvgDrawer("logo.html");
    hist_ = new CommandHistory;

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
        hist_->addLine(x_, y_, newx, newy);
    }
    x_ = newx;
    y_ = newy;
}

void Turtle::drawTurtle(){
    double x1,x2,x3,y1,y2,y3;
    x1 = x_ + 8 * cos(angle_);
    y1 = y_ + 8 * sin(angle_);

    x2 = x_ + 8 * cos(angle_ + 5 * PI / 6);
    y2 = y_ + 8 * sin(angle_ + 5 * PI / 6); 

    x3 = x_ + 8 * cos(angle_ - 5 * PI / 6);
    y3 = y_ +8 * sin(angle_ - 5 * PI / 6); 

    drawer_ -> setStrokeColor("red");
    drawer_ -> setStrokeWidth(1);
    drawer_-> drawLine(x1,y1,x2,y2);
    drawer_-> drawLine(x2,y2,x3,y3);
    drawer_-> drawLine(x1,y1,x3,y3);
    drawer_ -> setStrokeColor("navy");
    drawer_ -> setStrokeWidth(3);
}