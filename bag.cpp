/********************
 * Author: Eric Olson
 * Assignment: CS 161 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design:  This is the implementation file for the bag object.  This object is intended to simulate
 * the bag used to collect and sort letters for the overall project.
 ********************/

#include "bag.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::vector;

/***ACCESSORS***/
vector<pair<char, short> > bag::get_letters() {return letters;}  //Returns bags contents

void bag::show(bool val)  //Displays bag contents (and sizes if passed true)
{
  cout << "BAG: ";
  for (vector<pair<char, short> >::iterator i = letters.begin(); i != letters.end(); i++)
  {
    cout << i->first;
    if (val) {cout << "(" << i->second << ")";}
    cout << " ";
  }
  cout << " -- " << 22 - left() << "/22 Space Used.\n";
}


/***MEMBER FUNCTIONS***/

/**********
 * PRE: Must be called by a created and initalized bag object.
 * POST: Returns the value of open space left in the bag object.
 **********/
short bag::left()
{
  short sum = 0;
  
  for (vector<pair<char, short> >::iterator i = letters.begin(); i != letters.end(); i++)
  {
    sum += i->second;
  }

  return (22 - sum);
}


/**********
 * PRE: Requires a pair of char/short to be passed to be added to the vector
 * POST: Adds the passed pair if room, otherwise offers to swap the passed pair with a pair already
 * contained in the bag if not enough room.  Returns a pair if dropped or !/0 if nothing is dropped.
 **********/
pair<char, short> bag::add(pair<char, short> a)
{
  bool again = true;
  pair<char, short> temp('!', 0);
  string input = "", restart = "";
  short space = left(), count = -1, location = 0;
  
  if (a.second <= space)  //Simply adds the pair if room in bag. 
  {
    letters.push_back(a);
    cout << "Letter " << a.first << " has been added to your bag.\n";
    return temp;
  }
  else  //Otherwise attempts to swap the letter for one in the bag, leaving the second behind.
  {
    cout << "Letter " << a.first << " is too large to fit in your bag.  It is of size " << a.second
         << "and you only have " << space << "/22 room in your bag.\n";
    show(true);
    do
    {
      cout << "\nWould you like to try and swap with a letter from your bag? (y/n):";
      getline(cin,restart);
    }while (!((restart[0] == 'Y') || (restart[0] == 'y') || (restart[0] == 'N') || (restart[0] == 'n')));
    cout << endl;
    if((restart[0] == 'Y') || (restart[0] == 'y'))
    {
      while (again)
      {
        cout << "Which letter would you like to replace?  (letter will be left in this car): ";
        getline(cin, input);
      
        count = -1;
        for (vector<pair<char, short> >::iterator i = letters.begin(); i != letters.end(); i++)
        {
	  count ++;
	  if ((char)toupper(input[0]) == i->first) 
	  {
	    temp = *i;
	    location = count;
	  }
        }
      
      if (temp.first == '!') {cout << (char)toupper(input[0]) << " is not in your bag, try again!\n\n";}
      else {again = false;}
      }
    
      if (temp.second + space >= a.second)
      {
        cout << "You swapped letters, picking up the " << a.first << " and leaving behind the " << temp.first
	     << ".\n";
	letters.erase(letters.begin() + location);
        letters.push_back(a);
        return temp;
      }
      else
      {  
        cout << "Sorry even after dropping the " << temp.first << " there still won't be room for the "
	     << a.first << endl
	     << "You'll have to visit an empty car and drop off a letter first (or drop off a few).\n"
	     << "Come back and try again once you have more room\n\n";
        temp.first = '!';
        return a;
      }
    }
    return a;  //If user decides not to swap, returns original letter to remain in the room.
  }
} 


/**********
 * PRE:  Bag must contain at least one letter.
 * POST: Drops one letter from bag, and returns the letter dropped.
 **********/ 
pair<char, short> bag::drop()
{
  short count = -1, location = 0;
  pair<char, short> temp('!', 0);
  string input = "";
  bool again = true;

  show(true);

  while (again)
    {
      cout << "Which letter would you like to drop?  (letter will be left in this car): ";
      getline(cin, input);
      
      count = -1;
      for (vector<pair<char, short> >::iterator i = letters.begin(); i != letters.end(); i++)
      {
	count ++;
	if ((char)toupper(input[0]) == i->first) 
	{
	  temp = *i;
	  location = count;
	}
      }
      
      if (temp.first == '!') {cout << (char)toupper(input[0]) << " is not in your bag, try again!\n";}
      else {again = false;}
    }

  cout << "\nThe Letter " << temp.first << " has been left behind, giving you an additional " << temp.second
       << " space in your bag.\n";
  letters.erase(letters.begin() + location);

  return temp;
}
