#include "blob.h"
using namespace blob;
//initialization of of static variables------------------------
int Blob::defaultHealth = 100;
int Blob::defaultPower = 10;

//implemantation of constructors-------------------------------
Blob::Blob() : health(defaultHealth), power(defaultPower), color('\0'), xPos(-1), yPos(-1) {};
Blob::Blob(char team, Map* map) : health(defaultHealth), power(defaultPower), color('\0') {
	if (map->placeRandomly(this, xPos, yPos)) xPos = -1, yPos = -1;
	setColor(team);
}
Blob::Blob(char team, Map* map, int h, int p, int x, int y) : health(h), power(p), color('\0'), xPos(x), yPos(y) {
	if (map->setSpace(this, xPos, yPos))
		if(map->placeRandomly(this, xPos, yPos)) xPos = -1, yPos = -1;
	setColor(team);
}

//implementation of behavior functions-------------------------
bool Blob::move(DIRECTION d, Map* map) {
	if (!isAlive()) return true;
	unsigned int intendedX = ((d == LEFT) ? xPos-1 : ((d == RIGHT) ? xPos+1 : xPos));
	unsigned int intendedY = ((d == UP) ? yPos-1 : ((d == DOWN) ? yPos+1 : yPos));
	map->pollSpace(xPos, yPos); if (map->getFlags() & OUT_OF_BOUNDS_POLL_MASK) return true; //return error if blob is in invalid location 
	if (map->setSpace(this, intendedX, intendedY)) { //attempt to move blob
		if (map->getFlags() & OUT_OF_BOUNDS_POLL_MASK) return true; //return error if attempting to move out of bounds 
		Blob* target = map->pollSpace(intendedX, intendedY);
		if (target==nullptr || target->color != color) return true; //return error if attempting to move onto enemy blob
		*this += *target; //combine blobs using += operator
		map->clearSpace(intendedX, intendedY);
		target->health = -1; //clear target blob from the map and kill it
		map->setSpace(this, intendedX, intendedY); // move combined blob to proper location in the map
	}
	map->clearSpace(xPos, yPos); 
	xPos = intendedX; yPos = intendedY; //move blob to new coords and remove it from old coords
	return false;
}
bool Blob::attack(DIRECTION d, Map* map, bool& kill) {
	kill = false;
	if (!isAlive()) return true;
	unsigned int intendedX = ((d == LEFT) ? xPos - 1 : ((d == RIGHT) ? xPos + 1 : xPos));
	unsigned int intendedY = ((d == UP) ? yPos - 1 : ((d == DOWN) ? yPos + 1 : yPos));
	map->pollSpace(xPos, yPos); if (map->getFlags() & OUT_OF_BOUNDS_POLL_MASK) return true; //return error if blob is in invalid location
	Blob* target = map->pollSpace(intendedX, intendedY);
	if (target == nullptr || target->color == color) return true;//return error if no blob is found or blob is a teammate
	if (target->xPos != intendedX || target->yPos != intendedY) {
		map->clearSpace(intendedX, intendedY);
		return true; //clear space and return error if target coordinates disagree with map
	}
	target->health -= power; //damage enemy blob
	if (!target->isAlive()) {
		map->clearSpace(target->xPos, target->yPos);
		kill = true;
	}
	return false;
}
bool Blob::isAlive() const{
	return !(health < 1) && xPos!=-1 && yPos!=-1 && color!='\0';
}

//implememntation of operator overloads------------------------
Blob& Blob::operator+= (const Blob& blob2) {
	if (color != blob2.color) return *this;
	health += blob2.health;
	power = 2 + std::max(power, blob2.power);
	return *this;
}

std::ostream& blob::operator<< (std::ostream& out, const Blob& b) {
	out << ":Team - " << b.color << std::endl;
	out << ":Health - " << b.health << std::endl;
	out << ":Power - " << b.power << std::endl;
	out << ":Position - (" << b.xPos << ", " << b.yPos << ")" << std::endl;
	out << ":Status - " << ((b.isAlive()) ? "Alive" : "Dead") << std::endl;
	return out;
}
//implementation of getters & setters--------------------------
char Blob::getColor() const {
	return color;
}
bool Blob::setColor(char c) {
	if (!std::isalnum(c)) return true;
	color = c;
	return false;
}
int Blob::getDefaultHealth() {
	return defaultHealth;
}
int Blob::getDefaultPower() {
	return defaultPower;
}
bool Blob::setDefaultHealth(int h) {
	if (!(h > 0)) return true;
	defaultHealth = h;
	return false;
}
bool Blob::setDefaultPower(int p) {
	if (!(p > 0)) return true;
	defaultPower = p;
	return false;
}
int Blob::getXCoord() const{
	return xPos;
}
int Blob::getYCoord() const{
	return yPos;
}
bool Blob::setCoords(Map* map, int x, int y) {
	if (map->setSpace(this, x, y))  return true;
	xPos = x; yPos = y;
	return true;
}
bool Blob::setRandomCoords(Map* map) {
	if (map->placeRandomly(this, xPos, yPos)) return true;
	return false;
}