#pragma once
#include <iostream>
using namespace std; 


class Animal{
    public:
        virtual void makeSound()=0; 

};

class Dog : public Animal {
    public:
        void makeSound();
};

class Cat : public Animal { 
    public:
        void makeSound();
};

class Pig : public Animal {
    public:
        void makeSound();
};

class Cow : public Animal {
    public:
        void makeSound();
}; 