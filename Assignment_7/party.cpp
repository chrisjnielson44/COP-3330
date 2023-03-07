#include "party.h"

namespace dungeon_adventure {

void Party::add(Character* character) {
  characters_.push_back(character);
}

void Party::remove(Character* character) {
  for (auto it = characters_.begin(); it != characters_.end(); ++it) {
    if (*it == character) {
      // Deallocate the character.
      delete character;

      // Remove the character from the party.
      characters_.erase(it);

      // Stop searching for the character.
      break;
    }
  }
}

Character* Party::current() {
  return characters_[current_];
}

void Party::next() {
  current_ = (current_ + 1) % characters_.size();
}

int Party::treasure() const {
  return treasure_;
}

void Party::add_treasure(int amount) {
  treasure_ += amount;
}

}  // namespace dungeon_adventure
