#pragma once
#include <string>

class Pen {
    bool state_;

    public:
    Pen(bool state = true);
    bool isActive() { return state_; };
    void changeState() { state_ = !(state_); };
};
