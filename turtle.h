#pragma once

class Turtle{
    double x_; //position
    double y_;
    double angle_; // angle
    bool active_; // whether the turtle is drawing or not

    public:
    Turtle(double x = 0, double y = 0, double angle = 0, bool active = true); //origin is 0,0 for now but it will change in the future
    double x(){return x_;};
    double y(){return y_;};
    double angle(){return angle_;}; 
    bool active(){return active_;};

    void step(int amount);
    void turn(double angle){angle_ = angle_ + angle;};
    void change_state(){active_ = !(active_);};
};