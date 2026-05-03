#pragma once
#include "svgdrawer.h"
#include "pen.h"
#include "commandHistory.h"

class Turtle{
    double x_; //position
    double y_;
    double angle_; // angle

    CommandHistory * hist_;
    SvgDrawer * drawer_; // à initialiser ig
    Pen * pen_;

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

    void step(int amount); // gere la logique de dessin
    void turn(double angle){angle_ = angle_ + angle;};

    void drawTurtle();
};
