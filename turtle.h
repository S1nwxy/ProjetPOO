#pragma once
#include "svgdrawer.h"

class Turtle{
    double x_; //position
    double y_;
    double angle_; // angle
    SvgDrawer * drawer_; // à initialiser ig
    bool active_;



    public:
    Turtle(SvgDrawer * drawer, double x = 0, double y = 0, double angle = 0, bool active = true); //origin is 0,0 for now but it will change in the future
    ~Turtle(){delete drawer_;};
    double x(){return x_;};
    double y(){return y_;};
    double angle(){return angle_;};
    bool active(){return active_;};

    void step(int amount);
    void turn(double angle){angle_ = angle_ + angle;};
    void change_state(){active_ = !(active_);};
};