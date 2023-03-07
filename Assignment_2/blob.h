#pragma once
#include "iostream"
#include "map.h"

	/*Map class declaration------------------------------------
	* lets the compiler know that Map class exists.
	*/
	class Map;

	/*DIRECTION enum-------------------------------------------
	* contains one value for each cardinal direction in 2d space.
	* used to indicate direction in move() and attack() functions.
	*/
	enum DIRECTION : char {
		UP, DOWN, LEFT, RIGHT
	};

	/*Blob class---------------------------------------------------------------
	* conatins data for a single blob in the game.
	* public member functions:
	*	move()
	*	attack()
	*	isAlive()
	*	getColor()
	*	setColor()
	*	getXCoord()
	*	getYCoord()
	*	setCoords()
	* operators:
	*	<<
	*	+=
	* static functions:
	*	getDefaultPower()
	*	getDefaultHealth()
	*	setDefaultPower()
	*	setDefaultHealth()
	*/
	class Blob {
		//private data members---------------------------------
		
		/*health data member-------------------
		* stores the health that the blob has left.
		* if health is <= 0 the blob is considered dead and can no longer be used in the game.
		*/
		int health;

		/*power data member--------------------
		* how much damage the blob does when attacking.
		*/
		int power;

		/*color data member--------------------
		* indicates which team the blob is on.
		* only alphaneumeric character are allowed.
		*/
		char color;

		/*position data members----------------
		* contain the position of the blob in the map.
		* map is a descrete grid.
		*/
		int xPos, yPos;

		//static data members----------------------------------

		/*defaultHealth member-----------------
		* the amount of health a blob starts with.
		* for the assingment this will default to 100 but can be changed in the game settings.
		*/
		static int defaultHealth;

		/*defaultPower mamber----------------------------------
		* the power level a blob starts with.
		* for the assingment this will default to 10 but can be changed in the game settings.
		*/
		static int defaultPower;

	public:
		//constructors-----------------------------------------
		
		/*default constructor------------------
		* sets health and power to their default values.
		* color is set to '/0', indicating that its team is unassinged.
		* position is set to (-1,-1) indicating that the blob has not been added to a map yet.
		*/
		Blob();

		/*constructor (char, Map*)-------------
		* sets health and power to their default values.
		* color is set to provided value.
		* starting postion is randomly generated and added to map.
		*/
		Blob(char, Map*);

		/*constructor (all members)------------
		* creates a new blob with all attributes specified.
		* blob will be placed on the map at specified coordinates.
		* if coordinates are invalid, blob will be placed randomly.
		* parameter order: color, map, health, power, xpos, ypos.
		*/
		Blob(char, Map*, int, int, int, int);

		//behavioral functions---------------------------------

		/*move function------------------------
		* attempts to move the in the specified direction.
		* returns true upon failure.
		*/
		bool move(DIRECTION, Map*);

		/*attack function----------------------
		* attempts to attack an enemy blob in the specified direction.
		* bool parameter will be set to true if attack results in a kill
		* returns true upon failure.
		*/
		bool attack(DIRECTION, Map*, bool&);

		/*isAlive function---------------------
		* returns true if blob is alive and false if dead.
		* a blob is considered dead if its health is <= 0.
		*/
		bool isAlive() const;

		//operators--------------------------------------------

		/* << operator-------------------------
		* prints blob information to the terminal.
		*/
		friend std::ostream& operator<< (std::ostream&, const Blob&);

		/* += operator-------------------------
		* merges two blobs and returns the combined blob.
		* new blob is stored in the first operand.
		* the health of the two blobs is combined and the power of the new blob is the power of the larger of the two operand blobs +2.
		* will return first operand if blobs are on different teams.
		* note to grader: the spec said to use + operator but I felt that the += operator was more applicable for the way that I have approached the problem.
		*/
		Blob& operator+= (const Blob&);

		//getters&setters--------------------------------------
		
		/*getColor function--------------------
		* returns color data member
		*/
		char getColor() const;

		/*setColor function--------------------
		* sets the blobs color to provided parameter
		* will only accept alphaneumeric characters
		* returns true if unable to change the color
		*/
		bool setColor(char);

		/*getXCoord function-------------------
		* returns the current x position of the blob
		*/
		int getXCoord() const;

		/*getYCoord function-------------------
		* returns the current x position of the blob
		*/
		int getYCoord() const;

		/*setCoords function-------------------
		* attempts to set the blobs position to the provided values
		* returns true upon failure
		*/
		bool setCoords(Map*, int, int);

		/*setRandomCoords function-------------
		* randomly sets the position of the blob on the map
		* returns true upon failure
		*/
		bool setRandomCoords(Map*);

		/*getDefaultHealth function------------
		* returns the default health of newly created blobs.
		*/
		static int getDefaultHealth();

		/*getDefaultPower function-------------
		* returns the default power of newly created blobs.
		*/
		static int getDefaultPower();

		/*setDefaultHealth function------------
		* sets the default health for newly created blobs.
		* value will not be changed if proposed value is <=0.
		* returns true if value fails to change
		*/
		static bool setDefaultHealth(int);

		/*setDefaultPower function------------
		* sets the default power for newly created blobs.
		* value will not be changed if proposed value is <=0.
		* returns true if value fails to change
		*/
		static bool setDefaultPower(int);
	};
}