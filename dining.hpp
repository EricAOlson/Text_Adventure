/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the dining car class, derived from the car parent class.
 ********************/

#ifndef OLSON_DINING_HPP
#define OLSON_DINING_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include "car.hpp"
#include "bag.hpp"

class dining : public car
{
  public:
    
    /***CONSTRUCTORS***/
    dining();

    /***MEMBER FUNCTIONS***/
    bool action(bag &my_bag, short &clue);  //Outputs a count of letters held that are correct.
};

#endif
