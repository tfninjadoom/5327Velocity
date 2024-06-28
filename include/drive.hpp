/**
 * @file drive.hpp
 * @date 2023-10-11
 * 
 * @brief
 * This file contains the various drive modes that can be toggled between 
 * during Driver Control, along with related functions like joystick curves.
 */
#pragma once
#include "master.h"

namespace Drive1 {
    int curveJoystick(StickCurve stickCurve, int input, double t);

    void xDrive(StickCurve stickCurve);
    void xFieldCentricDrive(StickCurve stickCurve);
    void arcadeDrive(StickCurve stickCurve);
    void singleStickDrive(StickCurve stickCurve);
    void tankDrive(StickCurve stickCurve);
}

//---------ENUMS---------//

// finite set of drive modes
namespace DriveMode {
    enum DriveMode {
        tank,
        arcade,
        singleStick,
        xDriveMode,
        xFieldCentricMode,

        lastDriveMode
    }; //enum DriveMode
    DriveMode operator++(DriveMode& mode) {
        mode = static_cast<DriveMode>((mode + 1) % (lastDriveMode+1));
        return mode;
    }
} //namespace DriveMode

// finite set of stick curves
enum class StickCurve {
	strong,
	weak,
	slow,
}; //enum StickCurve

