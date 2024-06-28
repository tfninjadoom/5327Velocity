/**
 * @file angle.hpp
 * @date 2024-06-21
 * 
 * @brief
 * Class for maintaining an angle in degrees within range [0,360).
 */
#pragma once
#include <cmath>

/**
 * @brief Wraps a `double` to be in range [0, 360) degrees.
 * 
 */
class Angle {

private:
    double value;

public:
    /**
     * @brief Construct a new `Angle` object at 0.0 degrees.
     * 
     */
    Angle() : value{0.} 
    {}

    /**
     * @brief Construct a new `Angle` object.
     * 
     * @param degrees 
     */
    Angle(double degrees){
        value = clamp(degrees);
    }

    /**
     * @brief Overloads `operator=` to allow `double` assignment. Converts to be within range [0, 360).
     * 
     * @param degrees 
     * @return Angle& 
     */
    Angle& operator=(double degrees) {
        value = clamp(degrees);
        return *this;
    }
 
    /**
     * @brief Returns angle value within range [0, 360).
     * 
     * @return double 
     */
    double get() const { return value; }

    /**
     * @brief Sets the angle. Converts to be within range [0,360).
     * 
     * @param degrees 
     */
    void set(double degrees) { 
        value = clamp(degrees);
    }

    /**
     * @brief Modifies the input angle to be within range [0, 360).
     * 
     * @param deg 
     * @return double 
     */
    static double clamp(double deg) {
        deg -= 360. * std::floor(deg * (1. / 360.));
        return deg;
    }

    /**
     * @brief COMMENTS PENDING
     * 
     */
    static bool withinRange(const Angle& angle, double low, double high) {
        low = clamp(low);
        high = clamp(high);
        if ( (low <= angle.get()) && (angle.get() <= high) )            { return true; } 
        else if ( high <= low ) {
            if      ( (0.  <= angle.get()) && (angle.get() <= high) )   { return true; }
            else if ( (low <= angle.get()) && (angle.get() <  360.) )   { return true; }
        } else                                                          { return false; }
    }

}

/*--------- Operator overloading for assignment to primitive types ----------*/
#ifdef IMPLICIT_DEG_CONVERSION
/**
 * @brief Allows for conversion from type `Angle` to type `double`.
 * 
 * @param var  Variable of type `double` being assigned to.
 * @param angle  Angle object being assigned.
 * @return double 
 */
double operator=(double var, const Angle& angle) {
    var = angle.get();
    return var;
}

/**
 * @brief Allows for conversion from type `Angle` to type `float`.
 * 
 * @param var  Variable of type `float` being assigned to.
 * @param angle  `Angle` object being assigned.
 * @return float 
 */
float operator=(float var, const Angle& angle) {
    var = static_cast<float>(angle.get());
    return var;
}
#endif //IMPLICIT_DEG_CONVERSION

/*--------- Literal for clamping objects ----------*/

/**
 * @brief Literal keeps angle within range [0,360).
 * 
 * @param angle 
 * @return double 
 */
double operator ""_deg(double angle) {
    return Angle::clamp(angle);
}