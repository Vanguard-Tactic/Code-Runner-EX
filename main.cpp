#include <iostream>
#include <cstdlib>
#include "RPG.h" 
using namespace std;
//git init;

void display_stats(RPG p1, RPG p2);
void display_end(RPG p1, RPG p2);
void game_loop(RPG p1, RPG p2);

void use_skill(RPG * opponent);

int main()
{

  RPG p1 = RPG("Rogue",60,35,15,"thief");
  RPG p2 = RPG();

  //game_loop(&p1, &p2);
  //void display_end(RPG p1, RPG p2);
  
    
  
/*
  @param player1
  @param player2
*/


  printf("\n%s: Current Stats\n", p1.get_name().c_str());
  printf("Health: %i\t  Strength: %i\t Defense: %i\n", 
  p1.get_health(), p1.get_strength(), p1.get_defense());

  printf("\n%s: Current Stats\n", p2.get_name().c_str());
  printf("Health: %i\t  Strength: %i\t Defense: %i\n", 
  p2.get_health(), p2.get_strength(), p2.get_defense());



  printf("\n");

  //p1.update_health(0);
  //p2.update_health(0);

  /*if(p1.is_alive() == true)
  {
  cout << "Player 1's status: Alive." << " (" << p1.is_alive() << ")" 
  << endl;
  }
  else
  {
  cout << "Player 1's status: Dead." << " (" << p1.is_alive() << ")"     
  << endl;
  }

  if(p2.is_alive() == true)
  {
  cout << "Player 2's status: Alive." << " (" << p2.is_alive() << ")"    
  << endl;
  }
  else
  {
  cout << "Player 2's status: Dead." << " (" << p2.is_alive() << ")"     
  << endl;
  }*/


  game_loop(p1,p2);
  //display_stats(p1,p2);
  //display_end(p1,p2);

  //use_skill(&p1);
  //use_skill(&p2);
  
  

  return 0; 
};