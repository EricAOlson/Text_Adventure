/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/7/14
 * Design: Implmentation file for support functions.  These functions support the programs used in the
 * final project program.
 ********************/

#include "support.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/**********
 * PRE: Requires a string to use as a prompt to the user.  If min/max values (inclusive) are desired, 
 * they can be passed as shorts, otherwise SHRT_MIN & SHRT_MAX will be used as default.  Min must be <= Max.
 * POST:  Request user input and utilize error checking to ensure a valid short (between min/max if passed) 
 * is returned.
 **********/
int get_short(string ask, short min, short max)
{
  bool again = false;
  short result = 0;

  do
  {
    again = false;  
    cout << ask;
    if (!(cin >> result)) 
    {
      cout << "I did not understand your entry, please try again.\n";
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      again = true;
    }   
    else if(result < min)  
    {
      cout << "Your entry must be " << min << " or higher.\n"
	   << "Please try a larger number.\n";
      cin.sync();
      cin.ignore(INT_MAX, '\n');
      again = true;
    }
    else if(result > max)
    {
      cout << "Your entry must be " << max << " or lower.\n"
	   << "Please try a smaller number.\n";
      cin.sync();
      cin.ignore(INT_MAX, '\n');
      again = true;
    }
    else
    {
      cin.sync();
      cin.ignore(INT_MAX, '\n');
    }
  }while(again);

  return (result);
}


/**********
 * PRE: No pre-conditions.
 * POST: Clears the screen via 100X endl.
 **********/
void clear_screen()
{
  for (short i = 0; i < 100; i++) {cout << endl;}
}
