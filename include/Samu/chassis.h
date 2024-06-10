#ifndef CHASSIS_H
#define CHASSIS_H

#include "vex.h"
#include "Samu/functions.h"
class Robot {

private:
    MotorFunction &leftBack, &leftFront, &rigthFront, &rigthBack;
    vex::inertial &imu;

public:
    Robot(MotorFunction &leftBack, MotorFunction &leftFront, MotorFunction &rigthFront, MotorFunction &rigthBack, vex::inertial &inertialSensor) : rigthFront(rigthFront), rigthBack(rigthBack), leftBack(leftBack), leftFront(leftFront), imu(inertialSensor){};

};



#endif 