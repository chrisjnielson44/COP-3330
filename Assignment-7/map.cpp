#include "map.h"

#include "monster_party.h"
#include "party.h"

#include <algorithm>

//debug
#include <cassert>
#include <cstdlib>

namespace dungeon_adventure {

Map::Map(int size) : size_(size) {
  // Initialize the tiles.
  tiles_.resize(size_, std::vector<TileType>(size_, TileType::BLANK));

  // Generate random tiles.
  const int num_monsters = std::rand() % 6 + 5;
  const int num_treasure = std::rand() % 6 + 5;

  for (int i = 0; i < num_monsters; ++i) {
    int x, y;
    do {
      x = std::rand() % size_;
      y = std::rand() % size_;
    } while (tile_at(x, y) != TileType::BLANK);

    // Place a monster tile on the map.
    tiles_[x][y] = TileType::MONSTER;

    // Generate a random monster party.
    party_.add(new MonsterParty(std::rand() % 5 + 1));
  }

  for (int i = 0; i < num_treasure; ++i) {
    int x, y;
    do {
      x = std::rand() % size_;
      y = std::rand() % size_;
    } while (tile_at(x, y) != TileType::BLANK);

    // Place a treasure tile on the map.
    tiles_[x][y] = TileType::TREASURE;
  }

  // Place the party on the map.
  tiles_[0][0] = TileType::BLANK;
  party_.set_position(0, 0);
}

int Map::size() const {
  return size_;
}

Map::TileType Map::tile_at(int x, int y) const {
  assert(x >= 0 && x < size_);
  assert(y >= 0 && y < size_);
  return tiles_[x][y];
}

const Party& Map::party() const {
  return party_;
}

void Map::move_party(Direction direction) {
  int x = party_.x();
  int y = party_.y();

  switch (direction) {
    case Direction::UP:
      --y;
      break;
    case Direction::DOWN:
      ++y;
      break;
    case Direction::LEFT:
      --x;
      break;
    case Direction::RIGHT:
      ++x;
      break;
  }

  // Check if the move is valid.
  if (x < 0 || x >= size_ || y < 0 || y >= size_) {
    // The move is invalid.
    return;
  }

  // Check if the party encounters a monster.
  const TileType tile = tile_at(x, y);
  if (tile == TileType::MONSTER) {
    // Start combat.
    party_.fight(monster_party_at(x, y));
  }

  // Update the position of the party.
  tiles_[x][y] = TileType::BLANK;
  party_.set_position(x, y);

  // Check if the party picks up treasure.
  if (tile == TileType::TREASURE) {
    // Pick up treasure.
    party_.add_treasure(std::rand() % 10 + 1);
  }
}

const MonsterParty& Map::monster_party_at(int x, int y) const {
  // Find the monster party at the given coordinates.
  for (const auto& monster_party : party_.monsters()) {
    if (monster_party.x() == x && monster_party.y() == y) {
      return monster_party;
    }
  }

  // This line should never be reached.
  assert(false);
}
} 

