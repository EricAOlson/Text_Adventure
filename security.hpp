/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the security car class, derived from the car class.
 ********************/

#ifndef OLSON_SECURITY_HPP
#define OLSON_SECURITY_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "car.hpp"
#include "bag.hpp"

class security : public car
{
  public:
    
    /***CONSTRUCTORS***/
    security();
    
    /***MEMBER FUNCTIONS***/
    bool action(bag &my_bag, short &clue);
};

#endif
