#include "monster_party.h"
///help with debug
#include <cassert>

namespace dungeon_adventure {

MonsterParty::MonsterParty(int num_monsters) {
  for (int i = 0; i < num_monsters; ++i) {
    // Generate a random monster.
    monsters_.emplace_back(std::rand() % 20 + 15, std::rand() % 5 + 1);
  }
}

int MonsterParty::size() const {
  return monsters_.size();
}

const Monster& MonsterParty::monster(int index) const {
  assert(index >= 0 && index < size());
  return monsters_[index];
}

int MonsterParty::x() const {
  return x_;
}

int MonsterParty::y() const {
  return y_;
}

void MonsterParty::set_position(int x, int y) {
  x_ = x;
  y_ = y;
}

} 
