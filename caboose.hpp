/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the Caboose class, derived from the car parent class.
 ********************/

#ifndef OLSON_CABOOSE_HPP
#define OLSON_CABOOSE_HPP

#include <iostream>
#include "car.hpp"
#include "bag.hpp"

class caboose : public car
{
  public:
    caboose();
    bool action(bag &my_bag, short &clue);
};

#endif
