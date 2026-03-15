```python
class Animal:
    def __init__(self, name="", order=0):
        self.name = name
        self.order = order

    def set_order(self, order):
        self.order = order

    def get_order(self):
        return self.order

    def is_order_than(self, other):
        return self.order < other.order


class Dog(Animal):
    def __init__(self, name):
        super().__init__(name)


class Cat(Animal):
    def __init__(self, name):
        super().__init__(name)


class Node:
    def __init__(self, animal):
        self.animal = animal
        self.next = None


class AnimalQueue:
    def __init__(self):
        self.dogs = None
        self.cats = None
        self.order = 0

    def enqueue(self, animal):
        animal.set_order(self.order)
        self.order += 1
        if isinstance(animal, Dog):
            node = Node(animal)
            node.next = self.dogs
            self.dogs = node
        elif isinstance(animal, Cat):
            node = Node(animal)
            node.next = self.cats
            self.cats = node

    def dequeue(self):
        if not self.dogs and not self.cats:
            return None
        if self.dogs and not self.cats:
            node = self.dogs
            self.dogs = self.dogs.next
            return node.animal
        if self.cats and not self.dogs:
            node = self.cats
            self.cats = self.cats.next
            return node.animal
        if self.dogs.animal.get_order() < self.cats.animal.get_order():
            node = self.dogs
            self.dogs = self.dogs.next
            return node.animal
        else:
            node = self.cats
            self.cats = self.cats.next
            return node.animal


def main():
    shelter = AnimalQueue()
    shelter.enqueue(Dog("Rex"))
    shelter.enqueue(Cat("Whiskers"))


if __name__ == "__main__":
    main()
```