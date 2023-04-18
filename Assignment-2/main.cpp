#include "blob.h"

/*notes for grader---------------------------------------------
* This program will compile in c++ versions >=11.
* The spec didnt specify a settings menu but for the purposes of testing I had already created 90% of the functionality 
* for one so I figured I might as well include it in the final build.
* If the game is imideately played from the main menu the settings from the spec will be used.
* the map class was also not mentioned in the spec but creating a map class seemed like an interesting approach to the problem so I made one.
* With this said, the blob class still has all functionality required in the spec except for the fact that I 
* used += operator instead of + because it made more sense in the comtext of my program.
* There is also an option to print the map in game which I originaly added for testing purposes and left for 
* convinence (its really hard to play the game with just the coordinates).
*/





using namespace blob;
 //global function declarations--------------------------------

/*mainMenu function----------------------------
* displays the game menu.
* allows the player to play the game, edit the settings and quit the game.
*/
void mainMenu();

/*settingsMenu function------------------------
* displays the game settings and allows the user to change them.
* settings default to those specified in the assingment but can be changed here.
*/
void settingsMenu();

/*playGame function----------------------------
* driver for the game itself
*/
void playGame();

/*hasAliveBlobs function-----------------------
* checks if a team of blobs has at least one member still alive
* assumes that passed pointer points to array of size numBlobs
*/
bool hasAliveBlobs(Blob*);

/*hasWinner function---------------------------
* checks to see if only one team has living blobs
* assumes that passed pointer points to 2d array of size numTeams X numBlobs
*/
bool hasWinner(Blob**);

/*getDirection function------------------------
* prompt the user to choose a direction (up,down,left,right)
* ensures that provided direction is valid and returns it
*/
DIRECTION getDirection();


/*choseBlob function---------------------------
* prompts the user to select one of their blobs
* ensures that the selection is the number of a blob and that said blob is alive
*/
int choseBlob(Blob**, int);

/*preferences class--------------------------------------------
* contains settings data for the blob game that dosent fit into Map or Blob class
* intsances of this class have no functionality
* intended to only be used as an interface to acess and change settings for the blob game
*/

class Preferences {
	//static data members--------------------------------------
	
	/*numPlayers member------------------------
	* the number of players on each team
	* this will default to 4 for the assingment but can be changed in the settings menu
	* maximum of 16 players & minimum of 1 players allowed per team 
	*/
	static unsigned int numBlobs;

	/*numTeams member--------------------------
	* the number of teams
	* this will default to two for the assingment but cna be changed in the settings menu
	* maximum of 8 & minimum of 2 teams allowed
	*/
	static unsigned int numTeams;
public:
	//getter&setter functions----------------------------------
	static unsigned int getNumBlobs() {
		return numBlobs;
	}
	static unsigned int getNumTeams() {
		return numTeams;
	}
	static bool setNumTeams(unsigned int n) {
		if (n < 2 || n>8) return true;
		numTeams = n;
		return false;
	}
	static bool setNumBlobs(unsigned int n) {
		if (n < 1 || n>16) return true;
		numBlobs = n;
		return false;
	}
};
unsigned int Preferences::numBlobs = 4;
unsigned int Preferences::numTeams = 2;

int main() {
	mainMenu();
	std::cout << "Thanks for playing the blob game" << std::endl;
	return 0;
}

void mainMenu() {
	bool quitFlag = false;
	while (!quitFlag) {
		std::cout << "----Welcome To The Blob Game!----\n\nPlease make a selection:" << std::endl
			<< "a: play game" << std::endl
			<< "b: settings menu" << std::endl
			<< "q: quit" << std::endl;
		char selection; std::cin >> selection;
		while (selection != 'a' && selection != 'b' && selection != 'q') {
			std::cout << "Invalid selection, try again" << std::endl;
			std::cin >> selection;
		}
		switch (selection) {
		case 'a':
			playGame();
			break;
		case 'b':
			settingsMenu();
			break;
		case 'q':
			quitFlag = true;
		}
	}
}
void settingsMenu() {
	bool quitFlag = false;
	while (!quitFlag) {
		std::cout << "---Blob Game Settings---\n\nPleasemake a selection:" << std::endl
			<< "a: blob health - " << Blob::getDefaultHealth() << std::endl
			<< "b: blob power - " << Blob::getDefaultPower() << std::endl
			<< "c: map x size - " << Map::getDefaultX() << std::endl
			<< "d: map y size - " << Map::getDefaultY() << std::endl
			<< "e: number of teams - " << Preferences::getNumTeams() << std::endl
			<< "f: number of blobs per team - " << Preferences::getNumBlobs() << std::endl
			<< "q: quit" << std::endl;
		char selection; std::cin >> selection;
		while (selection < 'a' && selection > 'f' && selection != 'q') {
			std::cout << "Invalid selection, try again" << std::endl;
			std::cin >> selection;
		}
		switch (selection) {
		case 'a'://change default health
			std::cout << "Enter new value for default blob health:" << std::endl;
			int h; std::cin >> h;
			while (Blob::setDefaultHealth(h)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> h;
			}
			break;
		case 'b'://change default power
			std::cout << "Enter new value for default blob power:" << std::endl;
			int p; std::cin >> p;
			while (Blob::setDefaultPower(p)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> p;
			}
			break;
		case 'c'://change map size x
			std::cout << "Enter new value for default x size of the map:" << std::endl;
			unsigned int x; std::cin >> x;
			while (Map::setDefaultX(x)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> x;
			}
			break;
		case 'd'://change map size y
			std::cout << "Enter new value for default y size of the map:" << std::endl;
			unsigned int y; std::cin >> y;
			while (Map::setDefaultY(y)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> y;
			}
			break;
		case 'e'://change number of temas
			std::cout << "Enter new value for the number of teams:" << std::endl;
			unsigned int n; std::cin >> n;
			while (Preferences::setNumTeams(n)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> n;
			}
			break;
		case 'f'://change team size
			std::cout << "Enter new value for team size:" << std::endl;
			unsigned int t; std::cin >> t;
			while (Preferences::setNumBlobs(t)) {
				if (std::cin.fail()) {
					std::cin.clear(); std::cin.ignore();
				}
				std::cout << "Invalid value, try again" << std::endl;
				std::cin >> t;
			}
			break;
		case 'q':
			if (Preferences::getNumBlobs() * Preferences::getNumTeams() > Map::getDefaultX() * Map::getDefaultY()) std::cout << "Invalid settings. too many blobs for current map size" << std::endl;
			else quitFlag = true;
		}
	}
}
	

void playGame() {
	//setup team names and create blobs------------------------
	std::cout << "---Team Setup---" << std::endl;
	Map* map = new Map;
	Blob** teams = new Blob * [Preferences::getNumTeams()];
	for (int i = 0; i < Preferences::getNumTeams(); i++) {
		teams[i] = new Blob[Preferences::getNumBlobs()];
		std::cout << "Enter the symbol for player " << i + 1 << ':' << std::endl;
		char c; std::cin >> c;
		while (teams[i][0].setColor(c)) {
			std::cout << "Invalid symbol. must be alphaneumeric" << std::endl;
			std::cin >> c;
		}
		for (int j = 0; j < Preferences::getNumBlobs(); j++) {
			teams[i][j].setRandomCoords(map);
			teams[i][j].setColor(c);
		}
	}
	//game loop------------------------------------------------
	unsigned int round = 0;
	bool quitFlag = false;
	while (!hasWinner(teams) && !quitFlag) {
		round++; std::cout << "\n--Round " << round << "--\n" << std::endl;
		for (int team = 0; team < Preferences::getNumTeams(); team++) {
			bool turnIsOver = !hasAliveBlobs(teams[team]);
			while (!turnIsOver) {
				std::cout << "\n--Player " << team + 1 << "'s turn (" << teams[team][0].getColor() << " team)--" << std::endl
					<< "Make a selection:" << std::endl
					<< "a: see blob stats" << std::endl
					<< "b: see map" << std::endl
					<< "c: move a blob" << std::endl
					<< "d: attack a blob" << std::endl;
				char selection; std::cin >> selection;
				while (selection < 'a' || selection > 'd') {
					std::cout << "Invalid selection, try again" << std::endl;
					std::cin >> selection;
				}
				const char A = 'a';
				switch (selection) {
				case 'a'://see blob stats----------------------
					std::cout << "Select a team of blobs:" << std::endl;
					for (int i = 0; i < Preferences::getNumTeams(); i++)
						std::cout << (char)(A + i) << ": Player " << i + 1 << "(" << teams[i][0].getColor() << " team)" << std::endl;
					char selection; std::cin >> selection;
					while (selection < A || selection > A + Preferences::getNumTeams()) {
						std::cout << "Invalid selection, try again" << std::endl;
						std::cin >> selection;
					}
					std::cout << "---Player " << (selection - A + 1) << "'s blobs (" << teams[selection - A][0].getColor() << " team)---" << std::endl;
					for (int i = 0; i < Preferences::getNumBlobs(); i++)
						std::cout << "\nBlob " << i+1 << ":" << std::endl << teams[selection - A][i];
					break;
				case 'b'://view the map------------------------
					std::cout << *map;
					break;
				case 'c'://move a blob-------------------------
				{
					int chosenBlob = choseBlob(teams, team);
					DIRECTION d = getDirection();
					if (teams[team][chosenBlob].move(d, map)) {
						std::cout << "failed to move";
						if (map->getFlags() & OUT_OF_BOUNDS_POLL_MASK) std::cout << " - tried to move out of bounds" << std::endl;
						else if (map->getFlags() & OCCUPIED_SPACE_INTRUSION_MASK) std::cout << " - tried to move to a space occupied by enemy blob" << std::endl;
						else std::cout << " - invalid target" << std::endl;
					}
					else {
						std::cout << "Moved sucessfuly" << std::endl;
						turnIsOver = true;
					}
				}
					break;
				case 'd'://attack------------------------------
				{
					int chosenBlob = choseBlob(teams, team);
					DIRECTION d = getDirection();
					bool gotKill;
					if (teams[team][chosenBlob].attack(d, map, gotKill)) {
						std::cout << "failed to attack";
						if (map->getFlags() & OUT_OF_BOUNDS_POLL_MASK) std::cout << " - tried to attack out of bounds" << std::endl;
						else if (map->getFlags() & OCCUPIED_SPACE_INTRUSION_MASK) std::cout << " - tried to attack a space occupied by friendly blob" << std::endl;
						else std::cout << " - invalid target" << std::endl;
					}
					else {
						std::cout << "Attack completed sucessfully";
						if (gotKill) std::cout << " and killed an enemy blob";
						std::cout << std::endl;
						if (!gotKill || hasWinner(teams)) turnIsOver = true;
					}
				}
				break;
				}
			}
			std::cout << "---End of Player " << team + 1 << "'s turn (" << teams[team][0].getColor() << " team)---" << std::endl;
		}
		std::cout << "\n---End of round"<< round << "---" <<  std::endl;
		if (!hasWinner(teams)) {
			std::cout << "Continue playing?(y/n)" << std::endl;
			char selection; std::cin >> selection;
			if (selection == 'n') quitFlag = true;
		}
	}
	std::cout << "End of game!";
	if (!quitFlag) {
		int winner;
		for (winner = 0; winner < Preferences::getNumTeams(); winner++)
			if (hasAliveBlobs(teams[winner])) break;
		std::cout << " the winner is player " << winner + 1 << "(" << teams[winner][0].getColor() << " team)" << std::endl;
	}
	std::cout << std::endl;
	//free dynamic memory--------------------------------------
	delete map;
	if (teams != nullptr) {
		for (int i = 0; i < Preferences::getNumTeams(); i++)
			if(teams[i]!=nullptr) delete[] teams[i];
		delete[] teams;
	}
}
bool hasAliveBlobs(Blob* team) {
	if (team == nullptr) return false;
	for (int i = 0; i < Preferences::getNumBlobs(); i++)
		if (team[i].isAlive()) return true;
	return false;
}
bool hasWinner(Blob** teams) {
	if (teams == nullptr) return true;
	int numAliveTeams = 0;
	for (int i = 0; i < Preferences::getNumTeams(); i++)
		if (hasAliveBlobs(teams[i])) numAliveTeams++;
	return !(numAliveTeams > 1);
}
DIRECTION getDirection() {
	std::cout << "Choose a direction:" << std::endl
		<< "a: Up" << std::endl
		<< "b: Down" << std::endl
		<< "c: Left" << std::endl
		<< "d: Right" << std::endl;
	char direction; std::cin >> direction;
	while (direction < 'a' || direction>'d') {
		std::cout << "Invalid selection, try again" << std::endl;
		std::cin >> direction;
	}
	DIRECTION d = UP;
	switch (direction) {
	case 'a':
		d = UP;
		break;
	case 'b':
		d = DOWN;
		break;
	case 'c':
		d = LEFT;
		break;
	case 'd':
		d = RIGHT;
		break;
	}
	return d;
}
int choseBlob(Blob** teams, int team) {
	bool sure = false;
	int chosenBlob;
	while (!sure) {
		std::cout << "Choose a blob:" << std::endl;
		std::cin >> chosenBlob; chosenBlob--;
		while (chosenBlob < 0 || !(chosenBlob < Preferences::getNumBlobs())) {
			if (std::cin.fail()) {
				std::cin.clear(); std::cin.ignore();
			}
			std::cout << "Invalid selection, try again" << std::endl;
			std::cin >> chosenBlob; chosenBlob--;
		}
		std::cout << "Selected Blob:" << std::endl << teams[team][chosenBlob] << "Is this the correct blob? (y/n)" << std::endl;
		char confirmation; std::cin >> confirmation;
		sure = teams[team][chosenBlob].isAlive() && confirmation == 'y';
		if (!teams[team][chosenBlob].isAlive()) std::cout << "Blob is dead" << std::endl;
	}
	return chosenBlob;
}