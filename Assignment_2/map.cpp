#include "map.h"
#include "time.h"
#include "stdlib.h"
using namespace blob;
//initialization of static variables---------------------------
unsigned int Map::defaultXSize = 10;
unsigned int Map::defaultYSize = 10;

//implementation of constructors-------------------------------
Map::Map() : xBound(defaultXSize), yBound(defaultYSize), OUT_OF_BOUNDS_POLL(0), OCCUPIED_SPACE_INTRUSION(0) {
	grid = new Blob * *[xBound];
	for (int i = 0; i < xBound; i++)
		grid[i] = new Blob * [yBound];
	
	for (int i = 0; i < xBound; i++)//set all positions on the grid to nullptr
		for (int j = 0; j < yBound; j++)
			grid[i][j] = nullptr;
}
Map::Map(unsigned int x, unsigned int y) : xBound(x), yBound(y), OUT_OF_BOUNDS_POLL(0), OCCUPIED_SPACE_INTRUSION(0) {
	grid = new Blob * *[xBound];
	for (int i = 0; i < xBound; i++)
		grid[i] = new Blob * [yBound];

	for (int i = 0; i < xBound; i++)//set all positions on the grid to nullptr
		for (int j = 0; j < yBound; j++)
			grid[i][j] = nullptr;
}
Map::~Map() {
	if (grid != nullptr) {
		for (int i = 0; i < xBound; i++)
			if (grid[i] != nullptr) delete[] grid[i];
		delete[] grid;
	}
}

//implementation of behavior functions-------------------------
Blob* Map::pollSpace(unsigned int x, unsigned int y) {
	clearFlags();
	if ((x < xBound && y < yBound)) {//bounds checking
		return grid[x][y];
	}
	OUT_OF_BOUNDS_POLL = 1;//set bounds flag
	return nullptr;
}
bool Map::clearSpace(unsigned int x, unsigned int y) {
	clearFlags();
	if ((x < xBound && y < yBound)) {//bounds checking
		grid[x][y] = nullptr;
		return false;
	}
	OUT_OF_BOUNDS_POLL = 1;//set bounds flag
	return true;
}
bool Map::setSpace(Blob* blob, unsigned int x, unsigned int y) {
	clearFlags();
	if ((x < xBound && y < yBound)) {//bounds checking
		if (grid[x][y] == nullptr) {//checking for empty space
			grid[x][y] = blob;
			return false;
		}
		OCCUPIED_SPACE_INTRUSION = 1;//set intrusion flag
		return true;
	}
	OUT_OF_BOUNDS_POLL = 1;//set bounds flag
	return true;
}
bool Map::placeRandomly(Blob* blob, int &x, int &y, unsigned int maxAttempts) {
	srand(time(NULL));//initalize the RNG
	int randX = rand() % xBound, randY = rand() % yBound, attempts = 0;
	while (setSpace(blob, randX, randY) && attempts < maxAttempts) {//attempts to set chosen space
		randX = rand() % xBound;
		randY = rand() % yBound;//generates new space
		attempts++;
	}
	if (attempts == maxAttempts) return true;
	x = randX;
	y = randY;
	return false;
}

//implementation of error checking functions-------------------
char Map::getFlags() const{
	char bitmask = 0;
	bitmask |= OUT_OF_BOUNDS_POLL * OUT_OF_BOUNDS_POLL_MASK;
	bitmask |= OCCUPIED_SPACE_INTRUSION * OCCUPIED_SPACE_INTRUSION_MASK;
	return bitmask;
}
void Map::clearFlags() {
	OCCUPIED_SPACE_INTRUSION = 0;
	OUT_OF_BOUNDS_POLL = 0;
}

//implementation of operator overloads-------------------------
std::ostream& blob::operator<<(std::ostream &out, const Map &map) {
	out << std::endl;
	std::cout << "  ";
	for (int i = 0; i < map.xBound; i++)//print x-coordinates
		std::cout << i << ' ';
	std::cout << std::endl << ' ';
	for (int i = 0; i < map.xBound + 1; i++)//print upper wall
		out << "--";
	std::cout << std::endl;
	for (int y = 0; y < map.yBound; y++) {
		out << y << '|';
		for (int x = 0; x < map.xBound; x++) {
			if (map.grid[x][y] != nullptr && map.grid[x][y]->isAlive())  out << map.grid[x][y]->getColor() << ' ';//print blob color
			else out << "  ";
		}
		out << '|' << std::endl;
	}
	std::cout << ' ';
	for (int i = 0; i < map.xBound + 1; i++)//print lower wall
		out << "--";
	return out;
}

//implementation of getters&setters----------------------------
unsigned int Map::getDefaultX() {
	return defaultXSize;
}
unsigned int Map::getDefaultY() {
	return defaultYSize;
}
bool Map::setDefaultX(unsigned int x) {
	if ((x > 64) || (x < 3)) return true;
	defaultXSize = x;
	return false;
}
bool Map::setDefaultY(unsigned int y) {
	if ((y > 64) || (y < 3)) return true;
	defaultYSize = y;
	return false;
}
unsigned int Map::getXSize() const{
	return xBound;
}
unsigned int Map::getYSize() const{
	return yBound;
}