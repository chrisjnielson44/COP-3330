#pragma once
#include "blob.h"
namespace blob {
	/*blob class declaration-----------------------------------
	* lets the compiler know that Blob class exists.
	*/
	class Blob;
	
	/*constants------------------------------------------------
	* OUT_OF_BOUNDS_POLL_MASK - used to test for out of bounds upon failed function call.
	* OCCUPIED_SPACE_INTRUSION_MASK - used to check for a blocked space upon failed function call.
	*/
	const char OUT_OF_BOUNDS_POLL_MASK = 1 << 0, OCCUPIED_SPACE_INTRUSION_MASK = 1 << 1;

	/*Map class----------------------------------------------------------------
	* contains a map of the positions of the blobs in the game.
	* each point on the grid contains a pointer to a Blob object.
	* public member functions:
	*	pollSpace()
	*	setSpace()
	*	clearSpace()
	*	placeRandomly()
	*	getFlags()
	*	clearFlags()
	*	getXSize()
	*	getYSize()
	* operators:
	*	<<
	* static functions:
	*	getDefaultX()
	*	getDefaultY()
	*	setDefaultX()
	*	setDefaultY()
	*/
	class Map {
		//private data members---------------------------------

		/*grid member--------------------------
		* 2d array of pointers to Blob objects.
		* a nullptr indicates that the position does not contain a blob, a non-nullptr points to the blob at that point.
		*/
		Blob*** grid;

		/*bounds members-----------------------
		* tell the size of the grid that the game will be played on.
		* minimum size is 3x3 and maximum size is 64x64.
		*/
		unsigned int xBound, yBound;

		/*flags------------------------------------------------
		* OUT_OF_BOUNDS_POLL		- is set if an out of bounds position is polled.
		* OCCUPIED_SPACE_INTRUSION	- is set if a there is an attempt to set a space that is already occupied.
		*/
		bool OUT_OF_BOUNDS_POLL, OCCUPIED_SPACE_INTRUSION;

		//static data members----------------------------------

		/*default grid size members------------
		* the size of a new map with with an unspecified size.
		* for the assingment this will default to 10x10 but in can be changed in settings.
		*/
		static unsigned int defaultXSize, defaultYSize;

	public:
		//constructors-----------------------------------------
		
		/*default constructor------------------
		* creates a map with the default size.
		*/
		Map();

		/*constructor (inr, int)---------------
		* creates a map with the specified dimensions.
		*/
		Map(unsigned int, unsigned int);

		/*destructor---------------------------
		* frees dynamic memory in grid member.
		*/
		~Map();

		//behavior functions-----------------------------------

		/*pollSpace function-------------------
		* returns pointer to the blob in the specified position.
		* returns nullptr if no blob is present.
		* an out of bounds check will return nullptr but will set OUT_OF_BOUNDS_POLL flag (this should be checked for).
		*/
		Blob* pollSpace(unsigned int, unsigned int);

		/*clearSpace function------------------
		* removes any blob that may be present in the specified space.
		* an out of bounds call will set OUT_OF_BOUNDS_POLL flag (this should be checked for).
		* returns true upon failure
		*/
		bool clearSpace(unsigned int, unsigned int);

		/*setSpace function--------------------
		* sets the specified space to the provided blob.
		* will fail if the specified space is out of bounds or occupied by another blob.
		* failure may set OUT_OF_BOUNDS_POLL flag or OCCUPIED_SPACE_INTRUSION flag (this should be checked for).
		* returns true upon failure.
		*/
		bool setSpace(Blob*, unsigned int, unsigned int);

		/*placeRandomly function---------------
		* places the specified blob object in a random location on the grid.
		* blobs will only be placed on empty spaces.
		* stores selected location in int perameters x, y.
		* attempts parameter tells how many times to attempt to place the blob before failure.
		*/
		bool placeRandomly(Blob*, int&, int&, unsigned int = 8*defaultXSize*defaultYSize);
		
		//error checking---------------------------------------

		/*getFlags function--------------------
		* returns bitmask of flags.
		* 1-bit: OUT_OF_BOUNDS_POLL
		* 2-bit: OCCUPIED_SPACE_INTRUSION
		*/
		char getFlags() const;

		/*clearFlags function------------------
		* resets all flags.
		*/
		void clearFlags();

		//operator overloads-----------------------------------

		/*<< operator--------------------------
		* prints the grid to the console.
		* blobs are represented by ther as their color and empty spaces are left blank.
		*/
		friend std::ostream& operator<<(std::ostream&, const Map&);

		//getters&setters--------------------------------------

		/*getDefaultX function-----------------
		* returns the default value for xBound.
		*/
		static unsigned int getDefaultX();

		/*getDefaultY function-----------------
		* returns the default value for yBound.
		*/
		static unsigned int getDefaultY();

		/*setDefaultX function-----------------
		* sets a new value for defaultXBound.
		* maximum allowed value is 64.
		* returns true if value fails to change
		*/
		static bool setDefaultX(unsigned int);

		/*setDefaultY function-----------------
		* sets a new value for defaultyBound.
		* maximum allowed value is 64.
		* returns true if value fails to change
		*/
		static bool setDefaultY(unsigned int);

		/*getXSize function-------------------
		* returns the size of the grid in the x direction
		*/
		unsigned int getXSize() const;

		/*getYSize function-------------------
		* returns the size of the grid in the y direction
		*/
		unsigned int getYSize() const;
	};
}