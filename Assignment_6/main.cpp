#include "Animal.h"
using namespace std; 

int main(){

    Animal** List = new Animal*[1];
    int size;
    bool quit = false;

    while(!quit) {
        cout << "[A] - Play Animal Sound \n";
        cout << "[B] - Add a Dog to ist \n";
        cout << "[C] - Add a Cat to list \n";
        cout << "[D] - Add a Pig to list \n";
        cout << "[E] - Add a Cow to list \n";
        cout << "[Q] - Quit \n";
        cout << "Please make a slection from the menu \n";

        char userInput; 
        cin >> userInput; 

        switch(userInput) {
            case 'a':
            case 'A':
                for(int i= 0; i < size; i++) {
                    List[i] -> makeSound();
                    cout << "\n";
                }
                break;
            case 'b':
            case 'B':
                {
                   Animal** newList = new Animal*[size + 1];
                    for(int i= 0; i < size; i++) {
                        newList[i] = List[i];
                    }
                    newList[size] = new Dog;
                    delete [] List; 
                    List = newList;
                    size++; 
                }
                cout << "Added a Dog to list\n";
                break;
            case 'c':
            case 'C':
                {
                   Animal** newList = new Animal*[size + 1];
                    for(int i= 0; i < size; i++) {
                        newList[i] = List[i];
                    }
                    newList[size] = new Cat;
                    delete [] List; 
                    List = newList;
                    size++; 
                }
                cout << "Added a Cat to list\n";
                break;
            case 'd':
            case 'D':
                {
                   Animal** newList = new Animal*[size + 1];
                    for(int i= 0; i < size; i++) {
                        newList[i] = List[i];
                    }
                    newList[size] = new Pig;
                    delete [] List; 
                    List = newList;
                    size++; 
                }
                cout << "Added a Pig to list\n";
                break;
            case 'e':
            case 'E':
                {
                   Animal** newList = new Animal*[size + 1];
                    for(int i= 0; i < size; i++) {
                        newList[i] = List[i];
                    }
                    newList[size] = new Cow;
                    delete [] List; 
                    List = newList;
                    size++; 
                }
                cout << "Added a Cow to list\n";
                break;
            case 'q':
            case 'Q':
                quit = true;
                cout << "Quitting program...";
                break;
            default:
                cout << "Invalid Selection\n Please select a valid option from the menu\n";
        }
    }
for(int i = 0; i < size; i++) {
    delete List[i]; 
}
delete [] List; 

}