#include "student.h"
using namespace std;


class Course {
	char* name; int nameSize;

	char code[7];

	char location[10];

	Student* studentList; int studentListSize; int numStudents;
public:
	Course();//default constructor
	Course(const char*, const char*, const char*);//parameterized constructor
	~Course();//destructor

	Course& operator=(const Course&);//copy overload
	friend ostream& operator<<(ostream&, const Course&);//print overload

	const char* getName() const;
	const char* getLocation() const;
	const char* getCode() const;
	int getStudentListLength() const;

	void setName(const char*);
	void setLocation(const char*);
	void setCode(const char*);

	Student* findByName(const char*) const;
	Student* findByID(int) const;

	void addStudent(const Student&);
	bool removeStudent(const Student&);

};