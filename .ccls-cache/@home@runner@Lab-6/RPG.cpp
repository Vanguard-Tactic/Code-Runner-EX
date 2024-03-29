#include <iostream>
#include <array>
#include <cstdlib>
#include "RPG.h"
using namespace std;


RPG::RPG()
{
  name = "NPC";
  health = 100;
  strength = 25;
  defense = 10;
  type = "warrior";
  skills[0] = "slash";
  skills[1] = "slash";
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
  this->name = name;
  this->health = health;
  this->strength = strength;
  this->defense = defense;
  this->type = type;

  set_skills();
}

void RPG::set_skills()
{
  if (type == "mage")
  {
      skills[0] = "fire";
      skills[1] = "thunder";
  }

  else if (type == "thief")
  {
      skills[0] = "pilfer";
      skills[1] = "jab";
  }

  else if (type == "archer")
  {
      skills[0] = "parry";
      skills[1] = "crossbow_attack";
  }

  else
  {
      skills[0] = "slash";
      skills[1] = "parry";
  }
}

void RPG::print_action(string skill,RPG opponent)
{
  printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.get_name().c_str());
}

bool RPG::is_alive() const
{
  return health > 0;
}

int new_health;
void RPG::update_health(int health)
{
  health = new_health;
};



string RPG::get_name() const
{
  return name;
}

int RPG::get_health() const
{
  return health;
}

int RPG::get_defense() const
{
  return defense;
}

int RPG::get_strength() const
{
  return strength;
}

void RPG::attack(RPG * opponent)
{

(*opponent).health = (*opponent).health - (strength - (*opponent).defense);

printf("\n");
cout << get_name() << " deals " << (strength - (*opponent).defense) << " damage to " << (*opponent).get_name() << "!";

  
(*opponent).update_health(new_health); 
}


int chosen_skill_index;

void RPG::use_skill(RPG * opponent)
{ 
  for (int i = 0;i < skill_size;i++)
    {
      printf("Skill %i: %s\n", i, skills[i].c_str());
    }

  printf("\nChoose a skill to use: Enter 0 or 1\nOn the terminal: ");
  cin >> chosen_skill_index;
  
  while (chosen_skill_index != 0 && chosen_skill_index != 1)
    {
      printf("\n(Incorrect Input). Choose a skill to use: Enter 0 or 1\nOn the terminal: ");
    cin >> chosen_skill_index;
    }
  //cin >> chosen_skill_index;

  string chosen_skill = skills[chosen_skill_index];

  cout << chosen_skill << " and " << chosen_skill_index << endl;

print_action(chosen_skill, * opponent);

attack(opponent);  
}


void display_stats(RPG p1, RPG p2)
{
  printf("\n");
 cout << p1.get_name() << " health:" << p1.get_health() << endl;  
 cout << p2.get_name() << " health:" << p2.get_health() << endl;
 printf("\n");
}

void display_end(RPG p1, RPG p2)
{
  if (p1.is_alive() == 0 && p2.is_alive() == 0)
  {
   cout << "There are no surviors ..." << endl; 
  }

  else if (p1.is_alive() == 1 && p2.is_alive() == 0)
  {
  cout << p1.get_name() << " has defeated " << p2.get_name() << endl <<"Player 1 Wins!" << endl; 
  }

  else if (p1.is_alive() == 0 && p2.is_alive() == 1)
  {
  cout << p2.get_name() << " has defeated " << p1.get_name() << endl <<"Player 2 Wins!" << endl; 
  }

  else 
  {
    cout << "works not done yet!" << endl <<p1.is_alive() << " and " << p2.is_alive() << " and " << p1.get_health();
  }
}

void game_loop(RPG p1, RPG p2)
{
  //while (p1.is_alive() == 1 && p2.is_alive() == 1)
  while (p1.get_health() > 0 && p2.get_health() > 0)
    {
      display_stats(p1, p2);
      cout << "Player 1's turn!" << endl;
      p1.use_skill(&p2);
      printf("\n---------------------------------\n");
     
      
      display_stats(p1, p2);
      printf("\n");
      cout << "Player 2's turn!" <<endl;
      p2.use_skill(&p1);
      printf("\n---------------------------------\n");
      
    }
  display_end(p1, p2);
}

//void RPG::print_action(string chosen_skill,RPG * opponent)
//{
  
//}