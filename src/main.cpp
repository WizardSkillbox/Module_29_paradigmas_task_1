#include <iostream>
#include <string>
#include <utility>
#include <cassert>

using namespace std;

class Animal {

protected:
    Animal() = default;

public:
    virtual void Greet(const Animal *animal) = 0;

    virtual void GreetDog() const = 0;

    virtual void GreetCat() const = 0;
};

class Dog : public Animal {

protected:
    void GreetCat() const override {
        cout << "Bark ";
    }

    void GreetDog() const override {
        cout << "Woof ";
    }

public:
    void Greet(const Animal *animal) override {
        assert(nullptr != animal);
        animal->GreetDog();
    }
};

class Cat : public Animal {

protected:
    void GreetCat() const override {
        cout << "Purr ";
    }

    void GreetDog() const override {
        cout << "Meow ";
    }

public:
    void Greet(const Animal *animal) override {
        assert(nullptr != animal);
        animal->GreetCat();
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
