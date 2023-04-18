#include "map.h"
#include "character.h"
#include "party.h"
#include "monster_party.h"

#include <iostream>
#include <string>

using namespace dungeon_adventure;
using namespace std;

int main() {
  Map map;
  Party party;
  MonsterParty monster_party;

  // Add characters to the party.
  for (int i = 0; i < Party::kMaxSize; ++i) {
    party.add(new Character(80 + std::rand() % 20, 4 + std::rand() % 7));
  }

  // Add monsters to the monster party.
  monster_party.add(new Monster(15 + std::rand() % 20, 1 + std::rand() % 5));

  // Print the initial state of the map.
  cout << map << endl;

  string input;
  while (true) {
    // Get input from the player.
    cout << "Enter a direction to move (WASD): ";
    cin >> input;

    if (input.empty()) {
      // Do nothing.
    } else if (input[0] == 'W' || input[0] == 'w') {
      // Move the party up.
      party.current()->set_position(party.current()->x() - 1, party.current()->y());
    } else if (input[0] == 'A' || input[0] == 'a') {
      // Move the party left.
      party.current()->set_position(party.current()->x(), party.current()->y() - 1);
    } else if (input[0] == 'S' || input[0] == 's') {
      // Move the party down.
      party.current()->set_position(party.current()->x() + 1, party.current()->y());
    } else if (input[0] == 'D' || input[0] == 'd') {
      // Move the party right.
      party.current()->set_position(party.current()->x(), party.current()->y() + 1);
    }

    // Print the updated state of the map.
    cout << map << endl;
  }

  return 0;
}
