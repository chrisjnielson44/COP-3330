
#include "iostream"
#include "course.h"
using namespace std;

void printMenu();
char getUserSelection();
istream& getDynamicStringInput(istream&, char*&, char = '\n');
void listCourses(Course*, int);

void growCourseList(Course*&, int&);

int findByName(Course*, int, const char*);
int findByLocation(Course*, int, const char*);
int findByCode(Course*, int, const char*);


int main() {
	//initalize course list
	int courseListSize = 2, numCourses = 0;
	Course* courseList = new Course[courseListSize];
	//main loop
	bool quit = false;
	while (!quit) {
		printMenu();
		char choice = getUserSelection();
		switch (choice) {
		case 'a'://add a course to the list
		{
			cout << "Enter the course name:" << endl;
			char* name; getDynamicStringInput(cin, name);
			cout << "Enter the location:" << std::endl;
			char location[10]; cin.getline(location, 10);
			cout << "Enter the course code:" << endl;
			char code[7]; cin.getline(code, 7);
			Course c(name, location, code);
			if (numCourses == courseListSize) growCourseList(courseList, courseListSize);
			courseList[numCourses] = c;
			numCourses++;
			delete[] name;
		}
		break;
		case 'b'://add students to a course
		{
			cout << "Choose a course to add a student to:" << endl;
			listCourses(courseList, numCourses);
			cout << "Choose a course:" << std::endl;
			int choice; cin >> choice;
			while (cin.fail() || choice<1 || choice >numCourses) {
				if (cin.fail()) {
					cin.clear(); cin.ignore();
				}
				cout << "Invalid selection" << endl;
				cin >> choice;
			}
			//get addition
			cout << "Enter the students name:" << endl;
			char* name; getDynamicStringInput(cin, name);
			cout << "Enter the students major:" << endl;
			char* major; getDynamicStringInput(cin, major);
			cout << "Enter the students classification:" << endl;
			char classification; cin >> classification;
			cout << "Enter the students id:" << endl;
			int id; cin >> id;
			while (cin.fail()) {
				cin.clear(); cin.ignore();
				cout << "invalid input" << endl;
				cin >> id;
			}
			Student s(name, major, classification, id);
			courseList[choice - 1].addStudent(s);
			cout << "added student to course" << endl;
		}
		break;
		case 'c'://update a course
		{
			cout << "Choose a course to modify:" << endl;
			listCourses(courseList, numCourses);
			cout << "Choose a course:" << std::endl;
			int choice; cin >> choice;
			while (cin.fail() || choice<1 || choice >numCourses) {
				if (cin.fail()) {
					cin.clear(); cin.ignore();
				}
				cout << "Invalid selection" << endl;
				cin >> choice;
			}
			cout << "Chosen Course:" << endl << courseList[choice - 1] << endl;
			cout << "Choose what attribute to modify:" << endl
				<< "a - name" << endl
				<< "b - location" << endl
				<< "c - code" << endl
				<< "d - a student" << endl;
			char selection; cin >> selection;
			while (selection < 'a' || selection > 'd') {
				cout << "invalid selection" << endl;
				cin >> selection;
			}
			switch (selection) {
			case 'a'://change name
			{
				cout << "Enter the new name for the course:" << endl;
				char* name; getDynamicStringInput(cin, name);
				courseList[choice - 1].setName(name);
				delete[] name;
			}
			break;
			case 'b'://change location
			{
				cout << "Enter the new location of the course:" << endl;
				char location[10]; cin.ignore();  cin.getline(location, 10);
				courseList[choice - 1].setLocation(location);
			}
			break;
			case 'c'://change code
			{
				cout << "Enter the new course code:" << endl;
				char code[7]; cin.ignore();  cin.getline(code, 7);
				courseList[choice - 1].setCode(code);
			}
			break;
			case 'd'://change student
			{
				cout << "choose which student to modify (enter id of desired student)" << endl;
				int id; cin >> id;
				while (cin.fail()) {
					cin.clear(); cin.ignore();
					cout << "Invalid selection" << endl;
					cin >> id;
				}
				Student* chosenStudent = courseList[choice - 1].findByID(id);
				if (chosenStudent == nullptr) cout << "could not find student" << endl;
				else {//modify student
					cout << "Choosen student:" << endl << *chosenStudent << endl;
					cout << "Choose what attribute to modify:" << endl
						<< "a - name" << endl
						<< "b - major" << endl
						<< "c - classification" << endl
						<< "d - id" << endl
						<< "e - remove student" << endl;
					cin >> selection;
					while (selection < 'a' || selection > 'e') {
						cout << "invalid selection" << endl;
						cin >> selection;
					}
					switch (selection) {
					case'a'://name
					{
						cout << "Enter the new name for the student:" << endl;
						char* name; getDynamicStringInput(cin, name);
						chosenStudent->setName(name);
						delete[] name;
					}
					break;
					case 'b'://major
					{
						cout << "Enter the new major for the student:" << endl;
						char* major; getDynamicStringInput(cin, major);
						chosenStudent->setMajor(major);
						delete[] major;
					}
					break;
					case 'c'://classification
					{
						cout << "Enter the new classification for the student:" << endl;
						char classification; cin >> classification;
						chosenStudent->setClassification(classification);
					}
					break;
					case 'd'://id
					{
						cout << "Enter the new id for the student:" << endl;
						int id; cin >> id;
						while (cin.fail()) {
							cin.clear(); cin.ignore();
							cout << "invalid input" << endl;
						}
						chosenStudent->setID(id);
					}
					case 'e':
					{
						courseList[choice - 1].removeStudent(*chosenStudent);
						cout << "Removed student from course" << endl;
					}
					break;
					}

				}
			}
			break;
			}
		}
		break;
		case 'd'://list courses
		{
			listCourses(courseList, numCourses);
		}
		break;
		case 'e'://find a student
		{
			cout << "Select search criteria:" << endl
				<< "a - student name" << endl
				<< "b - student id" << endl;
			char choice; cin >> choice; int course = 0; Student* s = nullptr;
			if (choice == 'a') {//search ny name
				cout << "enter name to search for:" << endl;
				char* name; getDynamicStringInput(cin, name);
				for (course = 0; course < numCourses && s == nullptr; course++)
					s = courseList[course].findByName(name);
			}
			else {//search by id
				cout << "enter id to search for:" << endl;
				int id; cin >> id;
				while (cin.fail()) {
					cin.clear(); cin.ignore();
					cout << "invalid input" << endl;
				}
				for(course = 0; course<numCourses && s==nullptr; course++)
					s = courseList[course].findByID(id);
			}
			if (s == nullptr) cout << "Could not find student" << endl;
			else {
				cout << "Found a match in class #" << course + 1 << endl << "Student:" << endl;
				cout << *s;
			}
		}
		break;
		case 'f'://find a course
		{
			cout << "Select search criteria:" << endl
				<< "a - course name" << endl
				<< "b - location" << endl
				<< "c - course code" << endl;
			char choice; cin >> choice; int course;
			if (choice == 'a') {//search by name
				cout << "Enter name to search for" << endl;
				char* name; getDynamicStringInput(cin, name);
				course = findByName(courseList, numCourses, name);
				delete[] name;
			}
			else if (choice == 'b') { //search by location
				cout << "enter location to search for" << endl;
				char location[10]; cin.ignore();  cin.getline(location, 10);
				course = findByLocation(courseList, numCourses, location);
			}
			else { //search by code
				cout << "enter code to search for" << endl;
				char code[7]; cin.ignore(); cin.getline(code, 7);
				course = findByCode(courseList, numCourses, code);
			}
			if (course == -1) cout << "Could not find course" << endl;
			else {
				cout << "found course:" << endl << courseList[course] << endl;
			}
		}
		break;
		case 'g'://remove a course
		{
			cout << "Choose a course to remove:" << endl;
			listCourses(courseList, numCourses);
			int choice; cin >> choice;
			while (cin.fail() || choice<1 || choice >numCourses) {
				if (cin.fail()) {
					cin.clear(); cin.ignore();
				}
				cout << "Invalid selection" << endl;
				cin >> choice;
			}
			for (int i = choice - 1; i < numCourses-1; i++)
				courseList[i] = courseList[i + 1];
			numCourses--;
			cout << "removed the course" << endl;
		}
		break;
		case 'q'://quit
		{
			quit = true;
		}
		break;
		default:
			while (cin.fail()) {
				cin.clear(); cin.ignore();
			}
			cout << "Invalid selection" << endl;
		}
	}





	//delete course list
	delete[] courseList;
	return 0;
}




void growCourseList(Course*& courseList, int& courseListSize) {
	Course* newPtr = new Course[courseListSize + 1];
	for (int i = 0; i < courseListSize; i++)
		newPtr[i] = courseList[i];
	delete[] courseList;
	courseList = newPtr;
	courseListSize++;
}



istream& getDynamicStringInput(istream& in, char*& destination, char delim) {
	int destinationSize = 4; destination = new char[destinationSize];
	int index = 0; char currentLetter; bool done = false;
	in.get(currentLetter); 
	while (currentLetter == delim) in.get(currentLetter);//clears all unwanted characters from stream
	while (!done) {
		while (index < destinationSize && currentLetter != delim) {//attempts to fill cstring
			destination[index] = currentLetter;
			index++;
			in.get(currentLetter);
		}
		if (index != destinationSize) {//finish the string if there was enough room
			done = true;
			destination[index] = '\0';
		}
		else {//grow string if theres not enough room
			char* newStr = new char[destinationSize * 2];
			for (int i = 0; i < destinationSize; i++)
				newStr[i] = destination[i];
			destinationSize *= 2;
			delete[] destination;
			destination = newStr;
		}
	}
	return in;
}

void listCourses(Course* courseList, int numCourses) {
	for (int i = 0; i < numCourses; i++)
		cout << "----Course " << i + 1 << "----" << endl << courseList[i] << endl;
}
char getUserSelection() {
	char selection; std::cin >> selection;
	return selection;
}

void printMenu() {
	cout << "--Course Database--" << endl
		<< "a - add a course to the list" << endl
		<< "b - add students to a course" << endl
		<< "c - update a course" << endl
		<< "d - list courses" << endl
		<< "e - find a student" << endl
		<< "f - find a course" << endl
		<< "g - remove a course" << endl
		<< "q - quit" << endl;
}



int findByName(Course* c, int size, const char* name) {
	int found = -1;
	for (int i = 0; i < size && found == -1; i++)
		if (strcmp(name, c[i].getName()) == 0) found = i;
	return found;
}
int findByLocation(Course* c, int size, const char* location) {
	int found = -1;
	for (int i = 0; i < size && found == -1; i++)
		if (strcmp(location, c[i].getLocation()) == 0) found = i;
	return found;
}
int findByCode(Course* c, int size, const char* code) {
	int found = -1;
	for (int i = 0; i < size && found == -1; i++)
		if (strcmp(code, c[i].getCode()) == 0) found = i;
	return found;
}