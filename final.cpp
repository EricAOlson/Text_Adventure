/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Main program file for the final project program.
 ********************/

#include <iostream>  
#include <climits>
#include "car.hpp"
#include "pass.hpp"
#include "security.hpp"
#include "dining.hpp"
#include "caboose.hpp"
#include "friend.hpp"
#include "bag.hpp"
#include "support.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  car *player = NULL;
  bag my_bag;
  short clue = 0;
  bool finished = false;

  setup(player);

  clear_screen();  //Intro to game
  cout << "The train jolts you back awake, you really shouldn't be this tired, given it's your first\n"
       << "day at your new job, the job you've been applying to for years.  You have about 30 minutes left\n"
       << "on your commute and consider going back to sleep when a loud and somewhat sinister voice comes\n"
       << "over the train loudspeaker.\n\n"
       
       << "\"I am Captain Nuisance, and I have HIJACKED this train.\" This puts a sudden sense of dread into\n"
       << "your fellow passengers, and to be honest yourself.  The captain continues \"You all have until\n"
       << "the next stop to answer my riddle.  My assistant has already hidden clues all over this train.\n"
       << "You will find the riddle & letters that make up the answer, as well as some additional letters\n"
       << "that are not in the answer there to confuse you.  Bring me the answer and I will leave you be.\n"
       << "If you are unable to answer my riddle then you will be unable to avoid my wrath\".\n\n"
       
       << "At this point your fellow passengers are quite worried, or were at least until Captain Nuisance\n"
       << "finished his sentence with, \"my wrath of making this train 15 minutes late!!!\" followed by an\n"
       << "evil laugh that lasted a little too long.  Nobody really feels that a riddle search is worth the\n"
       << "effort, and they nominate you to try and solve the puzzle.  You after all have your new job to\n"
       << "get to, you don't want to be late on the first day.\n\n"
       
       << "You're task is to search the train, uncover enough riddle components to solve the riddle,\n"
       << "You will also find letters hidden throughout the train, some will be in the riddle's answer some\n"
       << "not, you must make sure to collect the right ones.  Each letter has a 'size' and you've been\n"
       << "given a bag that holds a maximum combined 'size', if you pick up the wrong letters you may need\n"
       << "later drop them to make room for the correct letters.  When you've solved the riddle head to the\n"
       << "front of the train to confront Captain Nuisance.  Good luck!!\n\n"
       << "Press <ENTER> to begin your search.. ";    
  cin.ignore(INT_MAX, '\n');

  while (!finished)  //Basic game loop, repeats until game is exited, or completed.
  {
    clear_screen();
    cout << "You are now in the " << player->get_name() << "." << endl << endl
         << "Here is where your search stands:\n"
	 << "-------------------\n"
         << "RIDDLE: \n";
    if (clue >= 1) {cout << "There was a green house.\n";}
    if (clue >= 2) {cout << "Inside the green house there was a white house.\n";}
    if (clue >= 3) {cout << "Inside the white house there was a red house.\n";}
    if (clue >= 4) {cout << "Inside the red house were lots and lots of babies.\n";}
    if (clue >= 5) {cout << "What exactly is this house?\n";}    
    cout << "-------------------\n";
    my_bag.show();    
    cout << "-------------------\n";
    cout << endl;
    finished = player->action(my_bag, clue);
    if (!finished) {move(player);}
  }

  clear_screen();  //Win scenario.
  cout << "Captain Nuisance is a little bit perplexed, you didn't seem the type to solve his riddle\n"
       << "but true to his word he unlocks the door and lets you in.  Before you can confront him, he\n"
       << "leaps through the open window, and in true action hero style grabs hold of a ladder hanging\n"
       << "from a nearby hovering helicoptor, he says something inaudible yet menacing as his helicoptor\n"
       << "flies away.\n\n"
     
       << "Just then the train conductor returns and explains you've solved the riddle in time to easily\n"
       << "make up the lost time, and moves the speed lever to 11.  Somewhat confused by the whole ordeal\n"
       << "you return to your seat, noting the disgusting lack of fanfare one would expect from the fellow\n"
       << "passengers you just saved from a slighty late arrival at their destinations.\n\n"

       << "You do decide to continue that nap Captain Nuisance interrupted, but have a new found confidence\n"
       << "that next time a non-life threatening, bizzare, and purpose lacking villain crosses your path\n"
       << "there is a decent chance you can thwart them.  Well done, enjoy your nap!!\n\n"; 
    
  return 0;
}
