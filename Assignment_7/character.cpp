#include "character.h"

#include "monster_party.h"

#include <cassert>
#include <cstdlib>

namespace dungeon_adventure {

Character::Character(int health, int power) : health_(health), power_(power) {}

int Character::health() const { return health_; }

int Character::power() const { return power_; }

void Character::take_damage(int damage) {
  assert(damage >= 0);
  health_ = std::max(0, health_ - damage);
}

void Character::attack(MonsterParty* monsters) {
  assert(monsters != nullptr);

  // Roll for hit.
  if (std::rand() % 100 >= 15) {
    // Hit! Attack a random monster in the party.
    monsters->take_damage(power_, std::rand() % monsters->size());
  }
}

std::ostream& operator<<(std::ostream& out, const Character& character) {
  return out << "Character (health=" << character.health()
             << ", power=" << character.power() << ")";
}

}  // namespace dungeon_adventure
