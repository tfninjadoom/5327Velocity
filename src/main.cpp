/**
 * @file main.cpp
 * @date 2023-10-11
 * 
 * @brief 
 * This is the main file of our program, with the initialize(), autonomous(),
 * disabled(), and opcontrol() functions.
 */
#include "master.h"
using namespace Controller;


/**
 * A (boilerplate) callback function for LLEMU's center button.
 *
void on_center_button() {
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	}
} //*/

/**
 * Set up ALL sensors and tasks in this function.
 * Runs as soon as program is started.
 * 
 * @details 
 * Use this for any and all setup/startup code that is global to autonomous 
 * and driver control. All other competition modes are blocked by initialize, 
 * so keep execution time for this mode under a few seconds.
 */


void initialize() {
	// displays stuff on the brain screen
	pros::lcd::initialize();
        pros::lcd::set_text(1, "StickCurve::strong");
        pros::lcd::set_text(2, "DriveMode::arcade");
        // pros::lcd::register_btn1_cb(on_center_button);

	pros::delay(500); // Stop the user from doing anything while legacy ports configure

	//--------Piston Starting States---------//
	Wing::both(false);
    Wing::extendElevation(false);

	//--------Chassis Configuration---------//
	//chassis.set_active_brake(0.1); 	// Sets active brake kP, recommended value 0.1.
			// 

	//moved here from autonomous()
	chassis.reset_pid_targets();				// Resets PID targets to 0.
	chassis.reset_gyro();						// Resets gyro position to 0.
	chassis.reset_drive_sensor();				// Resets drive sensors to 0.
	default_constants();			// 
	exit_condition_defaults();
	chassis.initialize(); 
}

/**
 * Runs while robot is disabled before/during a competition match.
 * 
 * @details 
 * Runs while the robot is in the disabled state of Field Management System or 
 * the VEX Competition Switch, following either autonomous or opcontrol. When 
 * the robot is enabled, this task will exit.
 */
void disabled() {
	//------------Pistons------------//
}

/**
 * Match-specific initialization routines.
 * Runs while robot is disabled at the beginning of a competition match.
 * 
 * @details 
 * Runs after initialize(), and before autonomous when connected to the Field 
 * Management System or the VEX Competition Switch. This is intended for 
 * competition-specific initialization routines, such as an autonomous 
 * selector on the LCD. Followed by autonomous() or opcontrol().
 */
void competition_initialize() {}

/**
 * Sets up, then runs selected autonomous function.
 * Called at the start of the autonomous mode.
 * 
 * @details 
 * This function will be started in its own task with the default priority and 
 * stack size whenever the robot is enabled via the Field Management System or 
 * the VEX Competition Switch in the autonomous mode. Alternatively, this 
 * function may be called in initialize or opcontrol for non-competition 
 * testing purposes.
 */
void autonomous() {
	
	//Autonomous::selection=Autonomous::Select::left;
	Wing::both(false);
    Wing::extendElevation(false);
	
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);	// Set motors to hold. This helps autonomous consistency.
	
	/*if 
	(Autonomous::selection==Autonomous::Select::left) 
	{ Autonomous::left(); } 
	else if 
	(Autonomous::selection==Autonomous::Select::right) 
	{ Autonomous::right(); } 
	else 
	{ Autonomous::skills(); }
	*/

// Robot 2
	//close_awp();
	//far_awp();
	//close_disrupt();
	//slapper_only_skills();
}


//-----------DRIVER CONTROL------------//
/**
 * (Robot is driven by a human.) 
 * Run the robot based on controller and joystick inputs.
 * 
 * @details 
 * This function will be started in its own task with the default priority and 
 * stack size.
 */
void opcontrol() {

	DriveMode driveMode { DriveMode::xDrive };

	StickCurve stickCurve { StickCurve::weak };
	StickCurve defaultStickCurve { stickCurve };

    int intakeMode { 0 };

    Wing::both(false);
    Wing::extendElevation(false);

	//--------Chassis Reconfiguration---------//
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);

	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

        // Drive Mode
		switch (driveMode) {
        case (DriveMode::tank):
            Drive1::tankDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::tank"); 
            break;
        case (DriveMode::arcade):
            Drive1::arcadeDrive(stickCurve);
            pros::lcd::set_text(2, "DriveModepros ::arcade"); 
            break;
        case (DriveMode::singleStick):
            Drive1::singleStickDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::singleStick");
            break;
        case (DriveMode::xDriveMode):
            Drive1::xDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::xDriveMode");
            break;
        case (DriveMode::xFieldCentric):
            Drive1::xFieldCentricDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::xFieldCentric");
            break;
		}
        // Change Drive Modes
        if ( newPress(LEFT) ) {
            driveMode++;
        }

        // Intake
        if ( newPress(R2) ) {
			if (intakeMode != 1) {
				intake.move(110);
				intakeMode = 1;
			} else {
				intake.move(0);
				intakeMode = 0;
			}
		}
        // if ( pros::Controller::get_digital(R2) ) {
        //     intake.move(127);
        //     intakeMode = 1;
        // } else {
        //     intake.move(0);
        //     intakeMode = 0;
        // }

		if ( newPress(A)) {
			if (!(Clamp::closed)) {
				Clamp::close(true);
			} else {
				Clamp::close(false);
			}
		}

		// autonomous
		if ( newPress(DOWN) ) {
			autonomous();
		}

        pros::delay(20);
    }
}
