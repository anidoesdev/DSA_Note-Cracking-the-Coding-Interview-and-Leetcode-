//Have to practice these type of questions


#include<iostream>
using namespace std;

class Animal {
protected:
    string name;
    int order;
public:
    Animal() : name(""), order(0) {}
    Animal(string n) : name(n), order(0) {}
    void setOrder(int o) { order = o; }
    int getOrder() { return order; }
    bool isOrderThan(Animal* a) {
        return order < a->getOrder();
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
};

struct LinkedList {
    Animal* animal;
    LinkedList* next;
    LinkedList(Animal* a) : animal(a), next(nullptr) {}
};

class animalQueue {
    LinkedList* dogs = nullptr;
    LinkedList* cats = nullptr;
    int order = 0;
public:
    void enqueue(Animal* a) {
        a->setOrder(order++);
        if (dynamic_cast<Dog*>(a)) {
            // Add to dogs list
            LinkedList* node = new LinkedList(a);
            node->next = dogs;
            dogs = node;
        } else if (dynamic_cast<Cat*>(a)) {
            // Add to cats list
            LinkedList* node = new LinkedList(a);
            node->next = cats;
            cats = node;
        }
    }
    Animal* dequeue() {
        // If both lists are empty
        if (!dogs && !cats) return nullptr;
        // If only dogs are present
        if (dogs && !cats) {
            LinkedList* node = dogs;
            dogs = dogs->next;
            Animal* a = node->animal;
            delete node;
            return a;
        }
        // If only cats are present
        if (cats && !dogs) {
            LinkedList* node = cats;
            cats = cats->next;
            Animal* a = node->animal;
            delete node;
            return a;
        }
        // Both lists have animals, compare order
        if (dogs->animal->getOrder() < cats->animal->getOrder()) {
            LinkedList* node = dogs;
            dogs = dogs->next;
            Animal* a = node->animal;
            delete node;
            return a;
        } else {
            LinkedList* node = cats;
            cats = cats->next;
            Animal* a = node->animal;
            delete node;
            return a;
        }
    }
};

int main() {
    animalQueue shelter;
    shelter.enqueue(new Dog("Rex"));
    shelter.enqueue(new Cat("Whiskers"));
    return 0;
}