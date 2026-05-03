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
    double turtlePosition_[2];
    double turtleAngle_;
    vector<line> coordinates_;

    public :

    CommandHistory(double pos[2], double angle, vector<line> c = {}){turtlePosition_[0] = pos[0]; turtlePosition_[1] = pos[1]; turtleAngle_ = angle; coordinates_ = c;}
    double *turtlePosition(){return turtlePosition_;};
    double turtleAngle(){return turtleAngle_;};
    vector<line> coordinates(){return coordinates_;};
};