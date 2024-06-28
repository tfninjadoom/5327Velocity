/**
 * @file autons.cpp
 * @date 2023-10-11
 * 
 * @brief
 * Unused file with a custom autonomous selector.
 */
#include "master.h"
#include <iostream>

namespace Autonomous {

    // forward declaration of selection
    Select selection;

    //------AUTONOMOUS FUNCTIONS-------//

    void close() {
        return;
    }

    void far() {
        return;
    }


    //--------SKILLS FUNCTIONS--------//

    void skills1() {
        return;
    }
    void skills2() {
        return;
    }
    void skills3() {
        return;
    }


    //---------SKILLS SELECTION--------//

    // call selected skills path
    void skills() { 
        if 
        (selection==Select::skills1) { skills1(); }
        else if 
        (selection==Select::skills2) { skills2(); }
        else if 
        (selection==Select::skills3) { skills3(); }
    }

} //namespace Autonomous


// autonumous sections: 

const int DRIVE_SPEED = 100;
int INTAKE_DURATION{5000}; // duration of intake before stopping
int INTAKE_SPEED{150}; // for the speed of the intake


void moveForward(double inches,int speed, bool wait=true, int time=500) {
	chassis.set_drive_pid(inches, speed);
  
	if (wait) { chassis.wait_drive(); }
	else { pros::delay(time); }

}
	

void moveBackward(double inches, int speed, bool wait=true, int time=500) {
	chassis.set_drive_pid(-inches, speed);
  
	if (wait) { chassis.wait_drive(); }

	else{
	pros::delay(time);
}
}

// the move parameter is if moveing forward would help grab the ball for example if the ball if against a barrier, the same for realeing the ball
void grabBall(int speed, int duration, bool move, int dis) {
  intake.move(speed);
  intake2.move(-speed);
  if(move){
    moveForward(dis,DRIVE_SPEED, true);
  }
  pros::delay(duration);
  intake.move(0);
  intake2.move(0);
}

void releaseBall(int speed, int duration,bool move, int dis) {
	intake.move(-speed);
	if(move){
		moveForward(dis,DRIVE_SPEED, true);
	}
	pros::delay(duration);
	intake.move(0);
}

void intakeOn(int speed){
	intake.move(-speed);
}	

void outtakeOn(int speed){
	intake.move(speed);
}

void intakeOff(){
	intake.move(0);
}

void outtakeOff(){
	intakeOff();
}


void turn(int speed, int degrees, bool right, bool wait=true, int delay=300) {
  
  if(right){
  	chassis.set_turn_pid(degrees, speed);
  }
  else{
	chassis.set_turn_pid(-degrees, speed);
  }

  if (wait) { chassis.wait_drive();
   }
else{
	pros::delay(delay);

   }
}

void swing(int speed, int degrees, bool left, bool wait=true) {
  
  if(left){
  	chassis.set_swing_pid(ez::RIGHT_SWING, degrees, speed);
  }
  else{
	chassis.set_swing_pid(ez::LEFT_SWING, degrees, speed);
  }

  if (wait) { chassis.wait_drive(); };
}


// ---------------------- OLD AUTONS -------------------//

void fiveBallAuton(){
	// grab triball under elevation bar
	intakeOn(100);
	moveForward(5, 100, false, 200);
	//pros::delay(100);
	intakeOff();

	// move to goal
	moveBackward(45, 100);
	turn(100, 180, true);
	swing(100, 135, true);
	Wing::both(true);
	moveForward(18, 127);
	swing(100, 90, true);
	
	// push
	outtakeOn(127);
	moveForward(25, 127, false);
	//pros::delay(500);
	moveBackward(15, 100, false);
	//pros::delay(500);
	moveForward(20, 127, false);
	//pros::delay(500);
	intakeOff();
	pros::delay(100);

	// turn toward middle ball 1
	moveBackward(15, 100);
	Wing::both(false);
	chassis.set_angle(90);
	turn(100, 19, true);
	
	// move toward middle ball 1
	moveForward(75, 100);
	//pros::delay(100);
	intakeOn(100);
	moveForward(5, 100, false );
	//pros::delay(500);
	intakeOff();
	
	// clockwise swing scoop to score 3 triballs
	moveBackward(10, 100);
	Wing::both(true);
	swing(100, 180, false);
	outtakeOn(100);
	moveForward(100, 127, false);
	//pros::delay(500);
	moveBackward(100, 10);
}
void awp_far(){
	moveBackward(35, 100);
	turn(100, 80, true);
	Wing::both(true);
	moveBackward(20, 127);
	Wing::both(false);
	moveForward(20, 100);
	turn(100, 80, false);
	Wing::extendElevation(true);
	moveForward(40, 100);
}

void unused_fiveBallAuton(){
  intakeOn(127);
  moveForward(7,100);
  //pros::delay(200);
  intakeOff();
  moveBackward(35, 100);
  turn(100, 180, true);
  //Wing::both(true);
  moveForward(30, 100);
  turn(100, 155, true);
  outtakeOn(INTAKE_SPEED);
  moveForward(20, 100);
  turn(100, 10, true);
  moveForward(40, 120);
  moveBackward(20, 100);
  turn(100, 60, false);

  //Wing::both(false);
  moveForward(40, 75);
  turn(100, 60, true);
  intakeOn(100);
  moveForward(30, 100);
  intakeOff();
  
  moveBackward(10, 75);
}

void fiveballautonv2(){
	intakeOn(100);
	moveForward(5, 100, false, 200);
	//pros::delay(100);
	intakeOff();

	// move to goal
	moveBackward(55, 100);
	turn(100, 180, true);
	swing(100, 135, true);
	Wing::both(true);
	moveForward(18, 127);
	swing(100, 90, true);
	
	// push
	outtakeOn(127);
	moveForward(25, 127, false);
	//pros::delay(500);
	//moveBackward(15, 100, false);
	//pros::delay(500);
	//turn(100, 180, true);

	moveBackward(20, 127, false);
	moveForward(20, 100);
	//turn(100, 180, true);
	//pros::delay(500);
	intakeOff();
	pros::delay(100);

	// turn toward middle ball 1
	moveBackward(15, 100);
	Wing::both(false);
	chassis.set_angle(90);
	turn(100, 19, true);
	
	// move toward middle ball 1
	moveForward(75, 100);
	//pros::delay(100);
	intakeOn(100);
	moveForward(5, 100, false );
	//pros::delay(500);
	intakeOff();
	
	// clockwise swing scoop to score 3 triballs
	moveBackward(10, 100);
	Wing::both(true);
	swing(100, 180, false);
	outtakeOn(100);
	moveForward(100, 127, false);
	//pros::delay(500);
	moveBackward(100, 10);
}


// ----------------------- AUTONS -------------------------//

void slapper_only_skills(){
	Slapper::run(true);
}

void prog_skills(){
	// Use LemLib branch
}


void close_awp() {
	// Descore match load zone
	//moveForward(2, 50, true);
	Wing::left(true);
	pros::delay(400);
	turn(60, 60, false);
	Wing::left(false);
	moveBackward(14, 100, true);
	turn(70, 90, false);
	// Move through alley
	Wing::right(true);
	moveBackward(5, 70, false, 500);
	Wing::right(false);
	moveBackward(25, -80, true);
	// Touch pole
	Wing::right(true);
	turn(15, -80, true);
}

void close_disrupt() {

	moveBackward(43, 120, false, 1000);
	
	turn(100, 45, true, false);
	//pros::delay(300);
	Wing::right(true);
	turn(100, 80, true, false);
	outtakeOn(100);
	moveBackward(20, 100);
	outtakeOff();
	turn(100, 360, true);
}

void far_push() {
	// Bring preload to goal
	turn(100, 45, true, true);
	moveForward(31, 80, true, 500);
	turn(100, 0, true, true);
	// Score preload
	outtakeOn(127);
	moveForward(12, 100, false, 500);
	moveBackward(14, 125, false, 500);
	turn(100, 180, false);
	//Wing::right(true);
	moveBackward(23, 120, true);
	moveForward(8, 90, true);
	outtakeOff();
	Wing::right(false);
}

void far_awp() {
	// Push preload into goal
	far_push();
	// Turn and touch pole
	turn(100, -90, true);
	moveForward(46, 110, true);
	turn(100, 90, true, true);
	moveBackward(6, 70);
	Wing::right(true);
	//turn(70, 115, true, true);
	
}