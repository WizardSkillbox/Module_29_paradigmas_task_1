#include <iostream>
#include <string>
#include <utility>
#include <cassert>

using namespace std;

class Animal {
    string name;

protected:
    explicit Animal(string inName) : name(move(inName)) {
    }

public:
    virtual void Greet(const Animal *animal) = 0;

    const string &GetName() const {
        return name;
    }
};

class Dog : public Animal {

public:
    Dog() : Animal("Dog") {
    }

    void Greet(const Animal *animal) override {
        assert(nullptr != animal);
        const string nameAnimal = animal->GetName();
        if (nameAnimal == this->GetName()) {
            cout << "Woof ";
        } else if (nameAnimal == "Cat") {
            cout << "Bark ";
        }
    }
};

class Cat : public Animal {

public:
    Cat() : Animal("Cat") {
    }

    void Greet(const Animal *animal) override {
        assert(nullptr != animal);
        const string nameAnimal = animal->GetName();
        if (nameAnimal == this->GetName()) {
            cout << "Purr ";
        } else if (nameAnimal == "Dog") {
            cout << "Meow ";
        }
    }
};

void Meeting(Animal *a, Animal *b) {
    assert(nullptr != a);
    assert(nullptr != b);

    a->Greet(b);
    b->Greet(a);
    cout << endl;
}

int main() {
    Animal *dog1 = new Dog();
    Animal *dog2 = new Dog();
    Animal *cat1 = new Cat();
    Animal *cat2 = new Cat();

    cout << "-= Cat + Dog: =- " << endl;
    Meeting(cat1, dog1);
    cout << "-= Dog + Cat: =-" << endl;
    Meeting(dog1, cat1);
    cout << "-= Cat + Cat: =-" << endl;
    Meeting(cat1, cat2);
    cout << "-= Dog + Dog: =-" << endl;
    Meeting(dog1, dog2);

    delete dog1;
    delete dog2;
    delete cat1;
    delete cat2;

    return 0;
}
