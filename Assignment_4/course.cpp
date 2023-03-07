#include "course.h"

Course::Course() {
	nameSize = 1;
	name = new char[nameSize];
	name[0] = '\0';

	studentListSize = 2; numStudents = 0;
	studentList = new Student[studentListSize];

	location[0] = '\0';
	code[0] = '\0';
}
Course::Course(const char* name, const char* location, const char* code) {
	nameSize = strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy(this->name, name);

	strcpy(this->location, location);
	strcpy(this->code, code);

	studentListSize = 2; numStudents = 0;
	studentList = new Student[studentListSize];
}
Course::~Course() {
	delete[] name;
	delete[] studentList;
}

Course& Course::operator=(const Course& c) {
	delete[] name;
	nameSize = c.nameSize;
	name = new char[nameSize];
	strcpy(name, c.name);

	strcpy(location, c.location);
	strcpy(code, c.code);

	delete[] studentList;
	studentListSize = c.studentListSize; numStudents = c.numStudents;
	studentList = new Student[studentListSize];
	for (int i = 0; i < studentListSize; i++)
		studentList[i] = c.studentList[i];
	return *this;
}
ostream& operator<<(ostream& out, const Course& c) {
	out << "Course name: " << c.name << endl
		<< "Location: " << c.location << endl
		<< "Code: " << c.code << endl
		<< "Student list:" << endl << endl;
	for (int i = 0; i < c.numStudents; i++)
		out << "Student " << i+1 << ":\n" << c.studentList[i] << endl;
	return out;
}

const char* Course::getName() const{
	return name;
}
const char* Course::getLocation() const{
	return location;
}
const char* Course::getCode() const {
	return code;
}
int Course::getStudentListLength() const{
	return numStudents;
}

void Course::setName(const char* name) {
	delete[] this->name;
	nameSize = strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy(this->name, name);
}
void Course::setLocation(const char* location) {
	strcpy(this->location, location);
}
void Course::setCode(const char* code) {
	strcpy(this->code, code);
}

Student* Course::findByID(int id) const {
	int index;
	for (index = 0; index < studentListSize && studentList[index].getID() != id; index++);
	if (index == studentListSize) return nullptr;
	else return &studentList[index];
}
Student* Course::findByName(const char* name) const {
	int index;
	for (index = 0; index < studentListSize && strcmp(studentList[index].getName(), name) != 0; index++);
	if (index == studentListSize) return nullptr;
	else return &studentList[index];
}

void Course::addStudent(const Student& student) {
	if (numStudents == studentListSize) {
		Student* newPtr = new Student[studentListSize + 10];
		for (int i = 0; i < studentListSize; i++)
			newPtr[i] = studentList[i];
		delete[] studentList;
		studentList = newPtr;
		studentListSize += 10;
	}
	studentList[numStudents] = student;
	numStudents++;
}
bool Course::removeStudent(const Student& student) {
	bool found = false;
	for (int i = 0; i < numStudents; i++) {
		if (studentList[i] == student) found = true;
		if (found && i<numStudents-1) studentList[i] = studentList[i + 1]; 
	}
	if (found) numStudents--;
	return !found;
}