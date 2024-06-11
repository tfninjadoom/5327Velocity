#ifndef ODOM_H
#define ODOM_H

#include "vex.h"

#include <iostream> 
#include <vector> 

class Odom{

private:

    std::vector<double> position{0, 0, 0};
    vex::rotation horizontal, leftVertical, rightVertical; 
    double horizontalOffset {0};
    double leftVerticalOffset {0};
    double rv {0};

public:

    Odom(const vex::rotation& horizontal, const vex::rotation& leftVertical, const vex::rotation& rightVertical, const double& horizontalOffset, const double& leftVerticalOffset, const double& rv) : 
         horizontal(horizontal), rv(rv), leftVertical(leftVertical), rightVertical(rightVertical), horizontalOffset(horizontalOffset), leftVerticalOffset(leftVerticalOffset){};

    void update();
    void setPosition();

};



#endif