/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation file for the dining car child class, derived from the car parent class.
 ********************/

#include "dining.hpp"

using std::cout;
using std::find;
using std::vector;
using std::pair;

/***CONSTRUCTORS***/
dining::dining() : car()
{
  name = "Dining Car";
}

/***MEMBER FUNCTIONS***/

/**********
 * PRE: Requires current bag and clue count.
 * POST: Checks how many of the collected letters are correct, and reports number to user.  Returns false.
 **********/
bool dining::action(bag &my_bag, short &clue)
{
  short count = 0;
  char solution[] = {'W', 'A', 'T', 'E', 'R', 'M', 'L', 'O', 'N'};  //Second E intentionally omitted.
  char *f;
  vector<pair<char, short> > temp = my_bag.get_letters();
 
  cout << "Here in the dining car, your fellow passengers have captured Captain Nuisance's\n"
       << "assistant.  He's willing to tell you how many letter's you've collected are used\n"
       << "in the answer.  He won't tell you which letters are correct, just how many.\n\n";
  my_bag.show();
    
  for (vector<pair<char, short> >::iterator i = temp.begin(); i != temp.end(); i++)
  {
    f = find(solution, solution+9, i->first);
    if (f != solution+9) {count++;}
  }
  cout << "The assistant reports you have " << count << " letter(s) correct.\n\n";
}
