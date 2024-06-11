#ifndef CHASSIS_H
#define CHASSIS_H

#include "vex.h"
#include "Samu/pid.h"
#include "Samu/odom.h"

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
    PID drive, heading, turn, swing, arc;
    Odom odom;

public:
    
    Robot(const vex::motor& leftBack, const vex::motor& leftFront, const vex::motor& rightfront, const vex::motor& rightback, 
          const vex::inertial& imu, const PID drive, const PID heading, const PID turn, const PID swing, const PID arc, const Odom odom) : 
          rightback(rightback), leftFront(leftFront), rightfront(rightfront), leftBack(leftBack), imu(imu), drive(drive), heading(heading), turn(turn), swing(swing), arc(arc), odom(odom){};
    
    void Manuver(ManueverType manuvertype, float target, float speed, float timeout); 

    void Travel(); 


};



#endif 