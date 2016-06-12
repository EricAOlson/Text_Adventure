/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the passenger car (pass) class, which is derived from the car parent abstract class.
 ********************/

#ifndef OLSON_PASS_HPP
#define OLSON_PASS_HPP

#include <iostream>
#include <utility>
#include <string>
#include "car.hpp"
#include "bag.hpp"

class pass : public car
{
  public:
    
    /***CONSTRUCTORS***/
    pass(std::string new_name, char letter, short val = 0);
    
    /***MEMBER FUNCTIONS***/
    bool action(bag &my_bag, short &clue);

  protected:

    /***DATA ELEMENTS***/
    std::pair<char, short> contents;
};

#endif
