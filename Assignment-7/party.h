#ifndef PARTY_H
#define PARTY_H

#include "character.h"

#include <vector>

namespace dungeon_adventure {

// The Party class acts as a container for objects of type Character.
class Party {
public:
  // Add a character to the party.
  void add(Character* character);

  // Remove a character from the party.
  void remove(Character* character);

  // Get the current character.
  Character* current();

  // Move to the next character in the party.
  void next();

  // Get the total amount of treasure that the party has collected.
  int treasure() const;

  // Add the given amount of treasure to the party's total.
  void add_treasure(int amount);

private:
  static constexpr int kMaxSize = 5;

  std::vector<Character*> characters_;

  int current_ = 0;

  int treasure_ = 0;
};

}  

#endif
