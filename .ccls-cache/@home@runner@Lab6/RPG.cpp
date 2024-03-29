#include <iostream>
#include <array>
#include <cstdlib>
#include "RPG.h"
using namespace std;

RPG::RPG()
{
  name = "NPC";
  health = 100;
  strength = 10;
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

void RPG::print_action(string skill, RPG opponent)
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