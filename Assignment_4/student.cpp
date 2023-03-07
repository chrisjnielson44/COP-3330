#include "student.h"
#include "cstring"

Student::Student() {
	nameSize = 1;
	name = new char[nameSize];
	name[0] = '\0';

	majorSize = 1;
	major = new char[majorSize];
	major[0] = '\0';

	classification = '\0';
	id = 0;
}
Student::Student(const char* name, const char* major, char classification, int id) {
	nameSize = strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy(this->name, name);
	
	majorSize = strlen(major) + 1;
	this->major = new char[majorSize];
	strcpy(this->major, major);

	this->classification = classification;
	this->id = id;
}
Student::~Student() {
	delete[] name;
	delete[] major;
}

Student& Student::operator=(const Student& s) {
	nameSize = s.nameSize;
	majorSize = s.majorSize;
	classification = s.classification;
	id = s.id;
	delete[] name;
	name = new char[nameSize];
	strcpy(name, s.name);
	delete[] major;
	major = new char[majorSize];
	strcpy(major, s.major);
	return *this;
}

bool Student::operator==(const Student& s) const{
	return strcmp(name, s.name) == 0 && strcmp(major, s.major) == 0 && id == s.id && classification == s.classification;
}

ostream& operator<<(ostream& out, const Student& s) {
	cout << "Name: " << s.name << endl
		<< "Major: " << s.major << endl
		<< "Classification: " << s.classification << endl
		<< "ID: " << s.id << endl;
	return out;
}

const char* Student::getName() const{
	return name;
}
int Student::getID() const {
	return id;
}

void Student::setName(const char* name) {
	delete[] this->name;
	nameSize = strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy(this->name, name);
}
void Student::setMajor(const char* major) {
	delete[] this->major;
	majorSize = strlen(major);
	this->major = new char[majorSize];
	strcpy(this->major, major);
}
void Student::setClassification(char classification) {
	this->classification = classification;
}
void Student::setID(int id) {
	this->id = id;
}