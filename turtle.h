#pragma once
#include <cmath>
#include "svgdrawer.h"
#include "pen.h"
#include "commandHistory.h"
#include <cmath>

// Author : Axel
// Modifications : Johann

// this file holds the Turtle class, which is the main class.
// it has the location and state of the turtle,
// but also has CommandHistory, SvgDrawer and Pen components.

class Turtle{
    double x_; //position
    double y_;
    double angle_; // angle in radians

    CommandHistory * hist_; // to access every line already traced
    SvgDrawer * drawer_; // to draw (duh)
    Pen * pen_; // to know whether to draw or not

    public:
    Turtle();
    ~Turtle() {
        delete drawer_;
        delete pen_;
        delete hist_;
    };
    double x(){return x_;};
    double y(){return y_;};
    double angle(){return angle_;};
    void xAt(double x) { x_ = x; };
    void yAt(double y) { y_ = y; };
    void angleAt(double angle) { angle_ = angle; };

    SvgDrawer* drawer() {return drawer_;};
    CommandHistory* hist() {return hist_;};
    Pen* pen() {return pen_;};

    void step(int amount); // handles drawing logic
    void turn(double angle){angle_ = angle_ + angle * M_PI / 180;};
    void drawTurtle(); // draws a small triangle that represents the turtle at its angle and position
};
