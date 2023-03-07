#ifndef MONSTER_PARTY_H
#define MONSTER_PARTY_H

#include "monster.h"
// support for dynamically-sized arrays.
#include <vector>

namespace dungeon_adventure {

// The MonsterParty class acts as a container for a group of Monsters.
class MonsterParty {
public:
  // Construct a MonsterParty with the given number of Monsters.
  MonsterParty(int num_monsters);

  // Get the number of Monsters in the party.
  int size() const;

  // Get the Monster at the given index.
  const Monster& monster(int index) const;

  // Get the x-coordinate of the party's position on the map.
  int x() const;

  // Get the y-coordinate of the party's position on the map.
  int y() const;

  // Set the party's position on the map.
  void set_position(int x, int y);

private:
  std::vector<Monster> monsters_;

  int x_ = 0;
  int y_ = 0;
};

}  

#endif 
