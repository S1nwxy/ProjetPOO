#pragma once
#include <vector>
#include "turtle.h"

using std::vector;

struct line{
    double x1;
    double x2;
    double y1;
    double y2;
};

class CommandHistory{
    vector<line> lines_;

    public :

    CommandHistory(vector<line> l = {}){lines_ = l;}
    vector<line>& lines(){return lines_;};
    void addLine(double x1, double y1, double x2, double y2){lines_.push_back({x1,x2,y1,y2});}
};
