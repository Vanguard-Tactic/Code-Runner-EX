#include <iostream>
#include <cstdlib>
#include "RPG.h" 
using namespace std;

int main()
{
  RPG p1 = RPG();
  RPG p2 = RPG("Rogue",60,35,15,"thief");

  printf("\n%s: Current Stats\n", p1.get_name().c_str());
  printf("Health: %i\t  Strength: %i\t Defense: %i\n", 
  p1.get_health(), p1.get_strength(), p1.get_defense());

  printf("\n%s: Current Stats\n", p2.get_name().c_str());
  printf("Health: %i\t  Strength: %i\t Defense: %i\n", 
  p2.get_health(), p2.get_strength(), p2.get_defense());



  printf("\n");

  p1.update_health(0);
  p2.update_health(0);

  if(p1.is_alive() == true)
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
  }


  return 0; 
};