/**
 * @file globals.hpp
 * @date 2023-10-11
 * 
 * @brief
 * This is the header file for the initializations of the different electronic components on the robot and the assignment of ports.
 */
#pragma once
#include "master.h"


// Motors
extern const int LEFT_DRIVE_PORTS[3];
extern const int RIGHT_DRIVE_PORTS[3];
extern const double DRIVE_GEAR_RATIO;
extern const int IMU_PORT;

extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor leftMid;
extern pros::Motor rightFront;
extern pros::Motor rightBack;
extern pros::Motor rightMid;

extern pros::Motor intake;
extern pros::Motor intake2;

// V5 Sensors

extern pros::IMU imu;
extern pros::Vision vision;
extern pros::Distance distance;
extern pros::Optical optical;
extern pros::Rotation rotationP; 
extern pros::Rotation rotationI; 
extern pros::Rotation rotationD; 
extern pros::GPS gps;

namespace Clamp {
    extern bool closed;

    void close(bool closeOrNot);
}