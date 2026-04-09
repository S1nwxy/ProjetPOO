#pragma once

class Turtle{
    int x_; //position
    int y_;
    int angle_; // angle
    bool active_; // whether the turtle is drawing or not

    public:
    Turtle(int x = 0, int y = 0, int angle = 0); //origin is 0,0 for now but it will change in the future
    int x(){return x_;};
    int y(){return y_;};
    int angle(){return angle_;}; 
    bool active(){return active_;};

    void step(int amount);
    void turn(int angle){angle_ += angle;};
    void change_state(){active_ = !(active_);};
};