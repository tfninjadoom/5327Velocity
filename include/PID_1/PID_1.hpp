/**
 * @file PID_1.hpp
 * @date 2023-MM-DD
 * 
 * @brief 
 * PID_1.cpp is a file created for Amir to write a PID loop along with pid_func.cpp.
 */
#ifndef PID2_HPP
#define PID2_HPP

#include "master.h" 

class PID2 {
public:
    PID2(double kP, double kI, double kD);
    void setTarget(double target);
    void setConstants(double kP, double kI, double kD);
    double compute(double currentValue);

private:
    double kP, kI, kD;
    double target;
    double integral;
    double previousError;
};

#endif // PID2_HPP