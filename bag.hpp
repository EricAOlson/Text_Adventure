/*******************
 * Author: Eric Olson
 * Assignment: CS 162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Header file for the bag object used to collect letters in the overall project.
 *******************/

#ifndef OLSON_BAG_HPP
#define OLSON_BAG_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <climits>

class bag
{
  public:
    
    /***ACCESSORS***/
    std::vector<std::pair<char, short> > get_letters();  //Returns contents
    void show(bool val = false);  //Displays contents to screen
    
    /***MEMBER FUNCTIONS***/ 
    short left();  //Counts the available space left in bag.
    std::pair<char, short> add(std::pair<char, short> a);  //Adds a value to the bag.
    std::pair<char, short> drop();  //Removes a value from the bag.

  private:
    
    /***DATA ELEMENTS***/
    std::vector<std::pair<char, short> > letters;
};

#endif
