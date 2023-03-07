#ifndef DUNGEON_ADVENTURE_MAP_H_
#define DUNGEON_ADVENTURE_MAP_H_

#include <iostream>
#include <vector>

namespace dungeon_adventure {

// The Map class represents the game board.
class Map {
public:
  // The type of a tile on the map.
  enum class TileType {
    BLANK,
    MONSTER,
    TREASURE,
  };

  // The possible directions that the party can move.
  enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

  // Construct a new map with the given size.
  explicit Map(int size);

  // Get the size of the map.
  int size() const;

  // Get the tile at the given coordinates.
  TileType tile_at(int x, int y) const;

  // Get the party.
  const Party& party() const;

  // Move the party in the given direction.
  void move_party(Direction direction);

  // Check if the player has won.
  bool has_won() const;

  // Check if the player has lost.
  bool has_lost() const;

private:
  // The size of the map.
  int size_;

  // The tiles on the map.
  std::vector<std::vector<TileType>> tiles_;

  // The player's party.
  Party party_;
};

// Overload the insertion operator for the Map class.
std::ostream& operator<<(std::ostream& out, const Map& map);

}  /

#endif  
