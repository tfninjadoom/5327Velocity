/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sammy                                                     */
/*    Created:      6/8/2024, 3:02:41 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "Samu/chassis.h"
using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// MOTORS
motor leftFront(0);
motor leftBack(0);
motor rightFront(0);
motor rightBack(0);
inertial imu(0);

// PID

PID drive(1,1,1,1);
PID heading(1,1,1,1);
PID turn(1,1,1,1);
PID swing(1,1,1,1);
PID arc(1,1,1,1);

// ODOM
rotation horizontal(0);
rotation leftVertical(0);
rotation rightVertical(0);

Odom odom(horizontal, leftVertical, rightVertical, 0, 0, 0);

// ROBOT
Robot robot(leftBack, leftFront, rightFront, rightBack, imu, drive, heading, turn, swing, arc, odom);


int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
   
    while(1) {
        
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }

    // int a = 3;
    // int a {4}; 
}
