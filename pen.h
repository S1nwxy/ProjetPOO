#pragma once
#include <string>

// Author : Axel

// this file contains the Pen class, that represents the state of the pen (active or not, size, color...)
// right now only the state is implemented

class Pen {
    bool state_;

    public:
    Pen(bool state = true) {state_ = state;}
    bool isActive() { return state_; };
    void changeState() { state_ = !(state_); };
};
