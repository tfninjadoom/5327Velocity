#ifndef CHASSIS_H
#define CHASSIS_H

#include "vex.h"

enum ManueverType {
    DRIVE,
    TURN,
    SWING,
    ARC
};

class Robot {

private:
    
    vex::inertial imu;
    vex::motor leftBack, leftFront, rightfront, rightback;

public:
    
    Robot(const vex::motor& leftBack, const vex::motor& leftFront, const vex::motor& rightfront, const vex::motor& rightback, const vex::inertial& imu) : rightback(rightback), leftFront(leftFront), rightfront(rightfront), leftBack(leftBack){};
    
    void Manuver(ManueverType manuvertype, float target, float speed, float timeout); 

    void Travel(); 


};



#endif 