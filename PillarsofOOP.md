
# 🌟 The Four Pillars of OOP in C++ (with Examples)

Object-Oriented Programming (OOP) is built on four main principles: **Encapsulation, Abstraction, Inheritance, and Polymorphism**. C++ not only supports these pillars but also goes further by allowing **multiple inheritance**—a feature both powerful and tricky.

Let’s walk through each concept with simple C++ examples.

---

## 1️⃣ Encapsulation: Protecting Data

Encapsulation is about **hiding internal details** and only exposing what’s necessary. We keep data private and control access through methods.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // hidden from outside

public:
    BankAccount(double initial) : balance(initial) {}

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient funds\n";
    }
    double getBalance() const { return balance; } // controlled access
};

int main() {
    BankAccount acc(1000);
    acc.deposit(500);
    acc.withdraw(200);
    cout << "Balance: " << acc.getBalance() << endl;
}
```

✅ Here, `balance` is **private**. No one can directly change it except through `deposit` and `withdraw`.

---

## 2️⃣ Abstraction: Hiding Implementation Details

Abstraction means focusing on **what an object does**, not *how* it does it. We can define abstract classes with pure virtual functions.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;   // pure virtual
    virtual double area() = 0; // pure virtual
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override { cout << "Drawing Circle\n"; }
    double area() override { return 3.14 * radius * radius; }
};

int main() {
    //Shape s; // gives an error beacuse Shape is an abstract class
    Shape* s = new Circle(5);
    s->draw();
    cout << "Area: " << s->area() << endl;
    delete s;
}
```

✅ The user only cares about `draw()` and `area()`—the details are hidden inside `Circle`.

---

## 3️⃣ Inheritance: Reusing Code

Inheritance allows a class to acquire properties and methods from another class.

```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() { cout << "Vehicle starting...\n"; }
};

class Car : public Vehicle {
public:
    void honk() { cout << "Car honking...\n"; }
};

int main() {
    Car c;
    c.start();  // inherited
    c.honk();   // own method
}
```

✅ `Car` automatically gets the behavior of `Vehicle`.

---

## 4️⃣ Polymorphism: One Interface, Many Forms

Polymorphism means the same function call can behave differently depending on the object type.

```cpp
#include <iostream>
using namespace std;

class Animal {
protected: string name;
public:
    Animal(string name) : name{ name } {}
    virtual void speak() { cout << "Animal sound\n"; }
    string getname() { return name; }
};

class Dog : public Animal {
public:
    Dog(string name) :Animal(name) {}
    void speak() override { cout << "Woof!\n"; }
    string getname() {
        return "Dog name is "+name;
    }
};

class Cat : public Animal {
public:
    Cat(string name) :Animal(name) {}
    void speak() override { cout << "Meow!\n"; }
    string getname() {
        return "Cat name is " + name;
    }

};

int main() {
   
    Animal* a1 = new Dog("levi");
    Animal* a2 = new Cat("sophie");
    a1->speak(); // Woof!
    a2->speak(); // Meow!

    cout << a1->getname(); //call animal::getname
    Cat c("orange");
    cout << c.getname(); //call cat::getname


    delete a1;
    delete a2;
}
```

✅ Same function call `speak()`, but different behavior depending on the object.

---

## ⭐ Bonus: Multiple Inheritance in C++

C++ allows a class to inherit from **multiple parents**.

```cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void takePhoto() { cout << "Taking a photo\n"; }
};

class Phone {
public:
    void makeCall() { cout << "Making a call\n"; }
};

class Smartphone : public Camera, public Phone {
public:
    void browseInternet() { cout << "Browsing internet\n"; }
};

int main() {
    Smartphone s;
    s.takePhoto();
    s.makeCall();
    s.browseInternet();
}
```

✅ A `Smartphone` can act as both a `Camera` and a `Phone`.

---

## ⚠️ The Diamond Problem (and How to Fix It)

Multiple inheritance can cause the **diamond problem**: when a class inherits the same base through multiple paths, C++ creates *two copies* of the base.

### Without `virtual` inheritance

```
        Person
       /      \
 Student      Teacher
       \      /
          TA
```

👉 `TA` ends up with **two separate Person objects**, leading to ambiguity.

### With `virtual` inheritance

```
        Person
       /  |   \
 Student  |   Teacher
       \  |  /
          TA
```

👉 Only **one shared Person object** exists.

Here’s a working example:

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string n = "Unknown") : name(n) {}
    void show() { cout << "I am " << name << " (a Person)\n"; }
};

class Student : virtual public Person {
public:
    Student(string n = "Student") : Person(n) {}
    void study() { cout << name << " is studying\n"; }
};

class Teacher : virtual public Person {
public:
    Teacher(string n = "Teacher") : Person(n) {}
    void teach() { cout << name << " is teaching\n"; }
};

class TA : public Student, public Teacher {
public:
    TA(string n) : Person(n), Student(n), Teacher(n) {}
    void assist() { cout << name << " is assisting in class\n"; }
};

int main() {
    Teacher t("Dr. Smith");
    t.show();
    t.teach();

    TA ta("Alice");
    ta.show();
    ta.study();
    ta.teach();
    ta.assist();
}
```

✅ Thanks to `virtual` inheritance, both `Student` and `Teacher` share a single `Person` instance.

---

## 🔬 Demo: Seeing the Diamond Problem in Memory

To **see the difference** in action, let’s print out the **memory addresses** of the `Person` sub-objects in a `TA`.

```cpp
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string n = "Unknown") : name(n) {}
};

// ❌ Version 1: Without virtual inheritance
class Student1 : public Person { public: Student1(string n):Person(n){} };
class Teacher1 : public Person { public: Teacher1(string n):Person(n){} };
class TA1 : public Student1, public Teacher1 {
public: TA1(string n):Student1(n),Teacher1(n){} };

// ✅ Version 2: With virtual inheritance
class Student2 : virtual public Person { public: Student2(string n):Person(n){} };
class Teacher2 : virtual public Person { public: Teacher2(string n):Person(n){} };
class TA2 : public Student2, public Teacher2 {
public: TA2(string n):Person(n),Student2(n),Teacher2(n){} };

int main() {
    cout << "---- Without virtual inheritance ----\n";
    TA1 ta1("Alice");
    cout << "Address of Student1::Person part: " << (Person*)(Student1*)&ta1 << endl;
    cout << "Address of Teacher1::Person part: " << (Person*)(Teacher1*)&ta1 << endl;

    cout << "\n---- With virtual inheritance ----\n";
    TA2 ta2("Bob");
    cout << "Address of Student2::Person part: " << (Person*)(Student2*)&ta2 << endl;
    cout << "Address of Teacher2::Person part: " << (Person*)(Teacher2*)&ta2 << endl;
}
```

### 🖥️ Example Output

```
---- Without virtual inheritance ----
Address of Student1::Person part: 0x7ffee87c5f40
Address of Teacher1::Person part: 0x7ffee87c5f60

---- With virtual inheritance ----
Address of Student2::Person part: 0x7ffee87c5f80
Address of Teacher2::Person part: 0x7ffee87c5f80
```

👉 Without `virtual`, two different `Person` objects exist.
👉 With `virtual`, both paths point to the **same address** → only one `Person`.

---

## ✅ Final Thoughts

We’ve explored:

* **Encapsulation** → data hiding
* **Abstraction** → focus on what, not how
* **Inheritance** → reuse and extend
* **Polymorphism** → one interface, many behaviors
* **Multiple inheritance** (and the diamond problem)


---
