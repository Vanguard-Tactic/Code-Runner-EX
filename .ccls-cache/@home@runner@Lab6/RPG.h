#include <iostream>
#include <cstdlib>
#define RPG_h
using namespace std;

const int skill_size = 2;

class RPG
{
public:
  RPG();
  RPG(string name, int health, int strength, int defense, string type);

  void set_skills();
  void print_action(string,RPG);
  void update_health(int);
  void attack(RPG);
  void use_skill(RPG);

  bool is_alive() const;
  string get_name() const;
  int get_health() const;
  int get_strength() const;
  int get_defense() const;

private:
  string name;
  int health;
  int strength;
  int defense;
  string type;
  string skills [skill_size];

};
