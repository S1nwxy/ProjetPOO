#pragma once
#include <string>

class Pen {
    bool isActive_;
    std::string color_;
    //double width_;

    public :
    Pen(bool isActive = true, std::string = "black");
    bool isActive(){return isActive_;};
    std::string color(){return color_;};
    void change_state(){isActive_ = !(isActive_);};
    //void change_color();
    //void change_width();
};