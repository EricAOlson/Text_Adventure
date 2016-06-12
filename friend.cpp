/********************
 * Author: Eric Olson
 * Assignment: CS162 - Final Project: Train Riddle
 * Last Updated: 12/8/14
 * Design: Implementation file for friend functions of the car class hierarchy.
 ********************/

#include "friend.hpp"

using std::cout;
using std::endl;
using std::string;

/**********
 * PRE: Requires a pointer to a car object.
 * POST: Setups the train layout with adjoining rooms, and contents.
 **********/
void setup(car *&player)
{
  car *build = NULL, *mid = NULL, *nose = NULL;

  player = new caboose;
  mid = new dining;
  nose = new security;
  
  build = new pass("Passenger Car 10 (Left)", 'T', 2);
  build->back = player;
  player->front = build;

  build = new pass("Passenger Car 10 (Right)", 'A', 1);
  build->back = player;
  build->left = player->front;
  player->front->right = build;

  build = new pass("Passenger Car 9 (Left)", 'P', 4);
  build->back = player->front;
  player->front->front = build;

  build = new pass("Passenger Car 9 (Right)", '?');
  build->back = player->front->right;
  build->left = player->front->front;
  player->front->front->right = build;
  player->front->right->front = build;

  build = new pass("Passenger Car 8 (Left)", '?');
  build->back = player->front->front;
  player->front->front->front = build;

  build = new pass("Passenger Car 8 (Right)", 'E', 1);
  build->back = player->front->right->front;
  build->left = player->front->front->front;
  player->front->right->front->front = build;
  player->front->front->front->right = build;

  build = new pass("Passenger Car 6 (Left)", '?');
  build->front = mid;
  mid->back = build;

  build = new pass("Passenger Car 6 (Right)", 'M', 3);
  build->front = mid;
  build->left = mid->back;
  mid->back->right = build;

  build = new pass("Passenger Car 7 (Left)", 'R', 2);
  build->front = mid->back;
  build->back = player->front->front->front;
  mid->back->back = build;
  player->front->front->front->front = build;

  build = new pass("Passenger Car 7 (Right)", 'C', 3);
  build->front = mid->back->right;
  build->back = player->front->right->front->front;
  build->left = mid->back->back;
  mid->back->right->back = build;
  player->front->right->front->front->front = build;
  mid->back->back->right = build;

  build = new pass("Passenger Car 5 (Left)", 'I', 1);
  build->back = mid;
  mid->front = build;

  build = new pass("Passenger Car 5 (Right)", 'N', 2);
  build->back = mid;
  build->left = mid->front;
  mid->front->right = build;

  build = new pass("Passenger Car 4 (Left)", 'W', 5);
  build->back = mid->front;
  mid->front->front = build;

  build = new pass("Passenger Car 4 (Right)", '?');
  build->back = mid->front->right;
  build->left = mid->front->front;
  mid->front->front->right = build;
  mid->front->right->front = build;

  build = new pass("Passenger Car 3 (Left)", 'Y', 5);
  build->back = mid->front->front;
  mid->front->front->front = build;

  build = new pass("Passenger Car 3 (Right)", 'U', 1);
  build->back = mid->front->right->front;
  build->left = mid->front->front->front;
  mid->front->right->front->front = build;
  mid->front->front->front->right = build;

  build = new pass("Passenger Car 1 (Left)", '?');
  build->front = nose;
  nose->back = build;

  build = new pass("Passenger Car 1 (Right)", 'O', 1);
  build->front = nose;
  build->left = nose->back;
  nose->back->right = build;

  build = new pass("Passenger Car 2 (Left)", 'L', 4);
  build->front = nose->back;
  build->back = mid->front->front->front;
  nose->back->back = build;
  mid->front->front->front->front = build;

  build = new pass("Passenger Car 2 (Right)", 'E', 1);
  build->front = nose->back->right;
  build->back = mid->front->right->front->front;
  build->left = nose->back->back;
  nose->back->right->back = build;
  mid->front->right->front->front->front = build;
  nose->back->back->right = build;
} 


/**********
 * PRE: Requires pointer to current nose location.
 * POST: Shows user current travel options, accepts user input selection, and moves nose pointer to
 * new car, once a valid direction is selected.  Also allows user to exit game.
 **********/
void move(car *&nose)
{
  bool again = true;
  int way = 9;
  string ask = "Which direction would you like to go? (1-Forward, 2-Right, 3-Back, 4-Left, 5-Exit Game) ";

  cout << "From the " << nose->name << ", you can move in the following direction(s):  ";
  if (nose->front != NULL) {cout << "Forward  ";}
  if (nose->right != NULL) {cout << "Right  ";}
  if (nose->back != NULL) {cout << "Back  ";}
  if (nose->left != NULL) {cout << "Left  ";}
  cout << endl;
     
  while (again)
  {
    way = get_short(ask,1,5);
    
    if ((way == 1 && nose->front == NULL) || (way == 2 && nose->right == NULL) ||
        (way == 3 && nose->back == NULL) || (way == 4 && nose->left == NULL))
    {
      cout << "You can not move in that direction!\n";
    }
    else {again = false;}
  }
  
  //Moves pointer to new car object.
  if (way == 1) {nose = nose->front;}
  else if (way == 2) {nose = nose->right;}
  else if (way == 3) {nose = nose->back;}
  else if (way == 4) {nose = nose->left;}
  else //exits the game if chosen.
  {
    cout << "\nThank you for playing!\n\n";
    exit (0);
  }
}
