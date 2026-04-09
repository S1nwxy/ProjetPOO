#include "turtle.h"
#include <cmath>
using namespace std;

#define PI 3.14159265

Turtle::Turtle(double x, double y, double angle, bool active){
    x_ = x;
    y_ = y;
    angle_ = angle;
    active_ = active;
}

void Turtle::step(int amount){
    int newx = x_ + amount * cos(angle_ * PI / 180);
    int newy = y_ + amount * sin(angle_ * PI / 180);
    if(!active_){
        x_ = newx;
        y_ = newy;
    } else {

    }
}