#ifndef DUNGEON_ADVENTURE_CHARACTER_H_
#define DUNGEON_ADVENTURE_CHARACTER_H_

#include <iostream>

namespace dungeon_adventure {

class MonsterParty;

// The Character class represents a single character in the game.
class Character {
public:
  // Construct a new character with the given health and power.
  explicit Character(int health, int power);

  // Get the current health of the character.
  int health() const;

  // Get the current power of the character.
  int power() const;

  // Take damage.
  void take_damage(int damage);

  // Attack the given party of monsters.
  void attack(MonsterParty* monsters);

private:
  // The current health of the character.
  int health_;

  // The current power of the character.
  int power_;
};

// Overload the insertion operator for the Character class.
std::ostream& operator<<(std::ostream& out, const Character& character);

} 

#endif 
