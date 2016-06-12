/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for support functions.  These functions are required for general purpose support for
 * the final project program.
 ********************/

#ifndef OLSON_SUPPORT_HPP
#define OLSON_SUPPORT_HPP

#include <iostream>
#include <string>
#include <climits>

int get_short(std::string ask, short min = SHRT_MIN, short max = SHRT_MAX); //User entry with error handling
void clear_screen(); //Clears the screen.

#endif
