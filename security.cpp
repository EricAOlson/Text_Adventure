/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation file for the security car class, derived from the car class.  Redefines the virtual
 * function 'action()' with security car specific activity.
 ********************/

#include "security.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::string;
using std::vector;
using std::pair;

/***CONSTURCTORS***/
security::security() : car()
{
  name = "Security Car";
}


/***MEMBER FUNCTIONS***/

/**********
 * PRE: Requires current bag and known clue info.
 * POST:  Checks to see if user has correct letters in bag, and either gives them a hint if not, or lets
 * them solve riddle if so.  Returns false if riddle not solved, true if solved.
 **********/
bool security::action(bag &my_bag, short &clue)
{
  short count = 0;
  char solution[] = {'W', 'A', 'T', 'E', 'R', 'M', 'L', 'O', 'N'}, bad = ' ', *f;
  vector<pair<char, short> > temp = my_bag.get_letters();
  string guess = "";
  bool again = true;
  
  cout << "You've arrived at the front of the train, but a solid metal door with a small sliding\n"
       << "speakeasy hatch stands in you way.  The hatch opens and Captain Nuisance asks to see your bag.\n";
  my_bag.show();
  cout << endl;
  
  //Checks to see if contents are correct or not.  
  for (vector<pair<char, short> >::iterator i = temp.begin(); i != temp.end(); i++)
  {
    f = find(solution, solution+9, i->first);
    if (f != solution+9) 
    {
      count++;
    }
    else {bad = i->first;}
  }
  
  if (count == 10) //If contents are 100% correct, lets user attempt to solve puzzle.
  {
    cout << "Well well, I may have underestimated you indeed.  You seem to have all the correct letters\n"
         << "But can you answer my riddle, me thinks not, but I'll enjoy watching you try:\n";

    do
    {
      cout << "Let's hear all your pathetic guesses: ";
      getline(cin,guess);
      for (short i = 0; i < guess.length(); i++) {guess[i] = toupper(guess[i]);}
      if (guess != "WATERMELON") {cout << "You must be embarassed you're so so wrong, try again...\n";}
    }while (guess != "WATERMELON");
    cout << endl;
  
    return true;
  }
  else if (bad != ' ')  //If incorrect letters are in bag, points out 1 to user.
  {
    cout << "Capt. Nuisance laugh's and says, you're not there yet.  Can't believe you\n"
         << "thought " << bad << " was in the answer, go get rid of that garbage pronto!\n"
         << "You've wasted my time, goodbye.\n\n";
    
    return false;
  }
  else  //If all letters are correct, but not missing some correct letters.
  {
    cout << "You may best me yet, you don't have any incorrect letters, but you don't have enough correct\n"
         << "letters yet, return when you do.  My search for a worthy adversary continues, goodbye.\n\n";
    
    return false;
  }
}
