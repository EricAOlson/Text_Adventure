/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation file for the Passenger Car (pass) class, which is derived from the car parent class.
 ********************/

#include "pass.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

/***CONSTRUCTORS***/
pass::pass(string new_name, char letter, short val) : car()
{
  name = new_name;
  contents.first = letter;
  contents.second = val;
}

/***MEMBER FUNCTIONS***/

/**********
 * PRE: Requires bag object and clue count.
 * POST: Displays the contents of the passnger car.  If clue is found updates riddle, if letter is found
 * offers player to add letter to bag (if room) or swap with existing letter (if no room).  If car is empty
 * player can drop a letter and leave it in the room for later.
 **********/
bool pass::action(bag &my_bag, short &clue)
{
  string restart = "";
  pair<char, short> temp;
  
  if (contents.first == '!')  //If compartment is empty offers to drop a letter
  {
    if (my_bag.left() != 22)  //Also checks to makesure bag is not empty.
    {
      do
      {
        cout << "This compartment is empty, would you like to drop one of your letters here? (y/n): ";
        getline(cin,restart);
      }while (!((restart[0] == 'Y') || (restart[0] == 'y') || (restart[0] == 'N') || (restart[0] == 'n')));

      if (restart[0] == 'Y' || restart[0] == 'y')
      {
        cout << endl;
        temp = my_bag.drop();
        contents = temp;
      }
      cout << endl;
    }
    else {cout << "This compartment is empty.\n\n";}
    return false;
  }
  else if (contents.first == '?') //If contents of room is a clue, adds it to the known riddle.
  {
    contents.first = '!';
    contents.second = 0;
    
    cout << "You find a portion of the clue hidden in this compartment.  The new line reads:\n";
    clue++;
    if (clue == 1) {cout << "There was a green house.\n";}
    if (clue == 2) {cout << "Inside the green house was a white house.\n";}
    if (clue == 3) {cout << "Inside the white house was a red house.\n";}
    if (clue == 4) {cout << "Inside the red house were lots and lots of babies.\n";}
    if (clue == 5) {cout << "What exactly is this house?\n";}
    cout << endl;
    
    return false;
  }
  else  //If room is not empty or contains a clue it must contain a letter and letter processing follows.
  {
    cout << "Within this compartment you find a letter " << contents.first << " of size " << contents.second
         << ".\n";
    do
    {
      cout << "Would you like to pick it up and add it to your bag? (y/n): ";
      getline(cin,restart);
    }while (!((restart[0] == 'Y') || (restart[0] == 'y') || (restart[0] == 'N') || (restart[0] == 'n')));

    if (restart[0] == 'Y' || restart[0] == 'y')
    {
      cout << endl;
      temp = my_bag.add(contents);
      contents = temp;
    }
    cout << endl;
  
    return false;
  }
}
