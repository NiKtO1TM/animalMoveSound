#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}
    virtual void makeSound() const {
        cout << name << " makes an unknown sound" << endl;
    }
    virtual void move() const {
        cout << name << " moves in an unknown way" << endl;
    }
    virtual ~Animal() {
        cout << "Object destroyed!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void makeSound() const override {
        cout << name << " says: Meow!" << endl;
    }
    void move() const {
        cout << name << " is moving silently." << endl;
    }
};

class Dog : public Animal {
private:
    string breed;
public:
    Dog(string n, string b) : Animal(n), breed(b) {}
    void makeSound() const override {
        cout << name << " breed:" << breed << " says: Woof!" << endl;
    }
    void move() const {
        cout << name << " runs after the ball." << endl;
    }
};

class Bird : public Animal {
private:
    bool canFly;
public:
    Bird(string n, bool fly) : Animal(n), canFly(fly) {}
    void makeSound() const override {
        cout << name << " says: Chirp!" << endl;
    }
    void move() const override {
        if (canFly) {
            cout << name << " flies in the sky." << endl;
        }
        else {
            cout << name << " jumps on the ground." << endl;
        }
    }
};

void animalShow(Animal* animal) {
    animal->makeSound();
    animal->move();
    cout << "-----------------------------" << endl;
}

int main() {
    Animal* a1 = new Cat("Gaston");
    Animal* a2 = new Dog("Aziz", "das Hund");
    Animal* a3 = new Bird("Tweety", true);
    Animal* a4 = new Bird("Wylsacom", false);
    animalShow(a1);
    animalShow(a2);
    animalShow(a3);
    animalShow(a4);
	delete a1;
    delete a2;
    delete a3;
    delete a4;
    return 0;
}