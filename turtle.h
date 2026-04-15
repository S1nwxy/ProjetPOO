#pragma once
#include "svgdrawer.h"
#include "pen.h"

class Turtle{
    double x_; //position
    double y_;
    double angle_; // angle
    SvgDrawer * drawer_; // à initialiser ig
    Pen * pen_;



    public:
    Turtle(SvgDrawer * drawer, Pen * pen, double x = 0, double y = 0, double angle = 0); //origin is 0,0 for now but it will change in the future
    ~Turtle(){delete drawer_;};
    double x(){return x_;};
    double y(){return y_;};
    double angle(){return angle_;};

    void step(int amount); // gere la logique de dessin
    void turn(double angle){angle_ = angle_ + angle;};
};