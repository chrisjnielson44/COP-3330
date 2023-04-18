#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstring"
using namespace std;

class Student {
	char* name; int nameSize; //dynamic cstring

	char* major; int majorSize; //dynamic cstring

	char classification;

	int id;
public:
	Student();//default constructor
	Student(const char*, const char*, char, int);//parameterized constructor
	~Student();//destructor

	Student& operator=(const Student&);//copy overload
	bool operator==(const Student&) const;//comparison
	friend ostream& operator<<(ostream&, const Student&);//print overload

	const char* getName() const;//getters
	int getID() const;

	void setName(const char*);//setters
	void setMajor(const char*);
	void setClassification(char);
	void setID(int);
};