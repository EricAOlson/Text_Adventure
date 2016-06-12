/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the car abstract parent class.
 ********************/

#ifndef OLSON_CAR_HPP
#define OLSON_CAR_HPP

#include <string>
#include "bag.hpp"

class car
{
  public:
    
    /***CONSTRUCTORS***/
    car();
    
    /***ACCESSORS***/
    std::string get_name();
    car* get_front();
    car* get_right();
    car* get_back();
    car* get_left();

    /***MUTATORS***/
    
    /***MEMBER FUNCTIONS***/
    virtual bool action(bag &my_bag, short &clue) = 0;
    
    /***FRIEND FUNCTIONS***/
    friend void move(car *&player);
    friend void setup(car *&player);
    
  protected: 
    
    /***DATA ELEMENTS***/
    std::string name;
    car *front, *right, *back, *left;
};

#endif
