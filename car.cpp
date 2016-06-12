/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation file for the car abstract parent class.
 ********************/

#include "car.hpp"

using std::string;

/***CONSTRUCTORS***/
car::car()
{
  name = "";
  front = NULL;
  right = NULL;
  back = NULL;
  left = NULL;
}

/***ACCESSORS***/
string car::get_name() {return name;}
car* car::get_front() {return front;}
car* car::get_right() {return right;}
car* car::get_back() {return back;}
car* car::get_left() {return left;}
