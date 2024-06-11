#ifndef PID_H
#define PID_H

class PID {

private:

    double kP {0};
    double kI {0};
    double kD {0};
    double kiWindUp {0};
    double kiRunning {0};
    double previousError {0};
    double previousmtrPower {0};
    double accuracy {0};
    
public:

    PID(const double kP, const double kI, const double kD, const double accuracy) : 
        kP(kP), kI(kI), kD(kD), accuracy(accuracy) {};

    double update();
    void reset();

};


#endif