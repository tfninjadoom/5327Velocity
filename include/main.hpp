/**
 * @file main.hpp
 * @date 2023-10-11
 *
 * @brief
 * This is the header for the main file of our program.
 */

#pragma once
#include "master.h"


//---------ENUMS---------//

// finite set of drive modes
enum class DriveMode {
	tank,
	arcade,
	singleStick,
}; //enum DriveMode

// finite set of stick curves
enum class StickCurve {
	strong,
	weak,
	slow,
}; //enum StickCurve

