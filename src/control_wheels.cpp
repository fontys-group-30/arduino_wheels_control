//
// Created by reno on 19-9-24.
//

#include <Arduino.h>
#include <header/pins.h>
#include <header/control_wheels.h>  // Ensure you have only one definition for each function

/**
 * @brief Controls the front right wheel.
 *
 * This function takes an integer velocity value as input and adjusts this
 * of the front right wheel accordingly.
 *
 * @param vel The velocity of the front right wheel.
 */
void fr_control_wheel(const int vel)
{
    analogWrite(motorPins[0][0], vel);
}

/**
 * @brief Controls the front left wheel.
 *
 * This function takes an integer velocity value as input and adjusts this
 * of the front left wheel accordingly.
 *
 * @param vel The velocity of the front left wheel.
 */
void fl_control_wheel(const int vel)
{
    analogWrite(motorPins[1][0], vel);
}

/**
 * @brief High-level function to control all wheels.
 *
 * This function sends commands to all the wheels (front left, front right, etc.)
 * based on the given command input. It is responsible for coordinating the wheels'
 * movements for overall robot motion.
 *
* @param vel The velocity of all the wheels.
 */
void controlWheels(const int vel)
{
    fr_control_wheel(vel);
    fl_control_wheel(vel);
}

