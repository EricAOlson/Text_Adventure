/********************
 * Author: Eric Olson
 * Assignment: CS 161 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation design for the caboose class.  This is a basic room with little functionality
 * simply a place to begin the search.
 *******************/

#include "caboose.hpp"

using std::cout;

/***CONSTRUCTORS***/
caboose::caboose() : car()
{
  name = "Caboose";
}

/***MEMBER FUNCTIONS***/

/**********
 * PRE: Requires current bag and uncovered clue count to be passed by reference.
 * POST: Takes no action, outputs a simple status to user, and returns false.
 **********/
bool caboose::action(bag &my_bag, short &clue)
{
  cout << "Nothing much to do here, time to get to searching!!\n\n";
  
  return false;
}
