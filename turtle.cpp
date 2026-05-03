#include <cmath>
#include "turtle.h"
#include "svgdrawer.h"

using namespace std;

// Explanations & authorship in the header file

Turtle::Turtle(){
    drawer_ = new SvgDrawer("logo.html");
    hist_ = new CommandHistory;
    pen_ = new Pen();

    drawer_ -> setStrokeWidth(2); // hardcoded, maybe something to change in the future
    x_ = drawer_->drawingWidth()/2; // center turtle
    y_ = drawer_->drawingHeight()/2;
    angle_ = 0;
}

void Turtle::step(int amount){
    int newx = x_ + amount * cos(angle_);
    int newy = y_ + amount * sin(angle_);
    if(pen_->isActive()){ // handles logic ; if pen is down, draw and send to the command history
        drawer_->drawLine(x_, y_, newx, newy);
        hist_->addLine(x_, y_, newx, newy);
    }
    x_ = newx; // move the turtle in all cases
    y_ = newy;
}

void Turtle::drawTurtle(){ // draws the turtle
    double x1,x2,x3,y1,y2,y3;
    double angleRad = angle_;
    x1 = x_ + 8 * cos(angleRad);
    y1 = y_ + 8 * sin(angleRad);

    x2 = x_ + 8 * cos(angleRad + 5 * M_PI / 6);
    y2 = y_ + 8 * sin(angleRad + 5 * M_PI / 6); 

    x3 = x_ + 8 * cos(angleRad - 5 * M_PI / 6);
    y3 = y_ + 8 * sin(angleRad - 5 * M_PI / 6); 

    drawer_ -> setStrokeColor("red"); // to be able to see it correctly
    drawer_ -> setStrokeWidth(1); // arbitrary choice
    drawer_-> drawLine(x1,y1,x2,y2);
    drawer_-> drawLine(x2,y2,x3,y3);
    drawer_-> drawLine(x1,y1,x3,y3);
    drawer_ -> setStrokeColor("navy"); // set it back to default
    drawer_ -> setStrokeWidth(2); // same
}