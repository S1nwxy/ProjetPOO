#pragma once
#include <vector>
#include "turtle.h"

// this file is for the CommandHistory class that is used to be able to "modify" a drawing
// when executing any command that results in a line being drawn, this line is memorized here
// when executing every command after the first, every memorized line is re-drawn,
// allowing the user to see what he's doing inbetween commands

using std::vector;

struct line{ // this represents one line (begin and end coordinates)
    double x1;
    double x2;
    double y1;
    double y2;
};

class CommandHistory{
    vector<line> lines_;

    public :

    CommandHistory(vector<line> l = {}){lines_ = l;}
    vector<line> lines(){return lines_;};
    void addLine(double x1, double y1, double x2, double y2){lines_.push_back({x1,x2,y1,y2});}
};