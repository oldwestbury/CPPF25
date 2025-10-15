# Pointers and Memory Management


###  Pointers in C

---



## 1. What is a Pointer?

A **pointer** is a variable that stores the memory address of another variable. Instead of holding a value directly, a pointer "points" to the location in memory where the value is stored.

- **Memory Address**: Every variable in C++ is stored in a specific location in memory, and each location has a unique address.
- **Pointer**: A pointer holds this address, allowing you to indirectly access or modify the value stored at that location.

---

## 2. Pointer Declaration and Initialization

### Syntax
```cpp
data_type *pointer_name;
```

- `data_type`: The type of data the pointer will point to (e.g., `int`, `float`, `char`).
- `*`: Indicates that the variable is a pointer.
- `pointer_name`: The name of the pointer variable.

### Example
```cpp
int x = 10;       // An integer variable
int *ptr;         // A pointer to an integer
ptr = &x;         // Assign the address of x to ptr
```

Here:
- `x` is an integer variable with a value of `10`.
- `ptr` is a pointer that stores the address of `x`.

---

## 3. Pointer Operators

### Address-of Operator (`&`)
The `&` operator is used to get the memory address of a variable.

```cpp
int x = 10;
int *ptr = &x;  // ptr now holds the address of x
```

### Dereference Operator (`*`)
The `*` operator is used to access the value stored at the memory address held by the pointer.

```cpp
int x = 10;
int *ptr = &x;
cout << *ptr << endl;  // Output: 10
```

Here, `*ptr` gives the value stored at the address held by `ptr`, which is `10`.

---

## 4. Pointer Arithmetic

Pointer arithmetic allows you to perform arithmetic operations on pointers. The operations are based on the size of the data type the pointer points to.

### Example
```cpp
int arr[] = {10, 20, 30};
int *ptr = arr;  // ptr points to the first element of arr

cout << *ptr << endl;  // Output: 10
ptr++;                 // Move to the next integer
cout << *ptr << endl;  // Output: 20
```

- When you increment a pointer (`ptr++`), it moves to the next element in the array.
- The amount by which the pointer moves depends on the size of the data type (e.g., `int` is typically 4 bytes).

---

## 5. Pointers and Arrays

Arrays and pointers are closely related in C++. The name of an array is essentially a pointer to its first element.

### Example
```cpp
int arr[] = {10, 20, 30};
int *ptr = arr;  // ptr points to the first element of arr

cout << *(ptr + 1) << endl;  // Output: 20 (second element)
cout << arr[1] << endl;      // Output: 20 (same as above)
```

- `arr[i]` is equivalent to `*(arr + i)`.

---

## 6. Strings in C/C++

In C/C++, a **string** is an array of characters terminated by a null character (`'\0'`). Strings are not a built-in data type in C but are represented using arrays of `char` and manipulated using pointers.

### Declaring and Initializing Strings
```cpp
char str1[] = "Hello";  // Automatically adds '\0' at the end
char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // Manual null termination
```

- `str1` and `str2` are both strings containing the word "Hello".
- The null character (`'\0'`) marks the end of the string.

### Accessing Strings Using Pointers
Since strings are arrays, you can use pointers to manipulate them.

```cpp
char *ptr = str1;  // ptr points to the first character of str1
cout << *ptr << endl;  // Output: H
cout << ptr << endl;   // Output: Hello
```

- `ptr` points to the first character of the string.
- You can use `*ptr` to access individual characters or `ptr` to access the entire string.

### Common String Functions in C++
C++ provides a set of standard library functions for working with strings, declared in `<cstring>`.

- `strlen`: Returns the length of a string.
- `strcpy`: Copies one string to another.
- `strcat`: Concatenates two strings.
- `strcmp`: Compares two strings.

Example:
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "Hello";
    char str2[20];

    strcpy(str2, str1);  // Copy str1 to str2
    strcat(str2, " World");  // Concatenate " World" to str2

    cout << str2 << endl;  // Output: Hello World
    cout << "Length: " << strlen(str2) << endl;  // Output: 11
    return 0;
}
```

   Write down an implementation for `strlen`. </br>
   **Solution** [soln](../codesnippets/length.cpp)

---

## 7. Pointers to Pointers

A pointer can also point to another pointer. This is called a pointer to a pointer.

### Syntax
```cpp
data_type **pointer_name;
```

### Example
```cpp
int x = 10;
int *ptr = &x;   // ptr points to x
int **pptr = &ptr;  // pptr points to ptr

cout << **pptr << endl;  // Output: 10
```

- `pptr` is a pointer to a pointer. It holds the address of `ptr`, which in turn holds the address of `x`.

---

## 8. Pointers and Functions

### Passing Pointers to Functions
Passing pointers to functions allows you to modify the original variable directly.

```cpp
void increment(int *ptr) {
    (*ptr)++;  // Increment the value at the address held by ptr
}

int main() {
    int x = 10;
    increment(&x);  // Pass the address of x
    cout << x << endl;  // Output: 11
    return 0;
}
```

### by value vs by reference
```c++

void increment_byreference(int *ptr) {
    (*ptr)++;  
}
void increment_byvalue(int x) {
    (x)++; 
}

void increment_byreference2(int &x) {
    (x)++;  
}

int main() {
    int x = 10;
    increment_byreference(&x);   // incremented to 11
    increment_byvalue(x);  //stay 11
   increment_byreference2(x); // incremented to 12
    return 0;
}

```


### Returning Pointers from Functions
Functions can also return pointers. Be careful to avoid returning pointers to local variables, as they go out of scope after the function returns.

```cpp
int* createArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    return arr;
}
```

---

## 9. Dynamic Memory Allocation

Dynamic memory allocation allows you to allocate memory at runtime using functions like `malloc`, `calloc`, `realloc`, and `free`.

### `malloc`
Allocates a block of memory of a specified size.

```cpp
int *ptr = (int *)malloc(5 * sizeof(int));  // Allocate memory for 5 integers
```

### `calloc`
Allocates memory and initializes it to zero.

```cpp
int *ptr = (int *)calloc(5, sizeof(int));  // Allocate and initialize to 0
```

### `realloc`
Resizes a previously allocated block of memory.

```cpp
ptr = (int *)realloc(ptr, 10 * sizeof(int));  // Resize to 10 integers
```

### `free`
Deallocates memory to avoid memory leaks.

```cpp
free(ptr);  // Free the allocated memory
```

---

## 10. `void *` (Generic Pointers)

A `void *` is a **generic pointer** that can point to any data type. It is often used in functions that need to handle different types of data.

This section is from https://www.geeksforgeeks.org/void-pointer-c-cpp/

## Example of Void Pointer in C  

```c
// C Program to demonstrate that a void pointer
// can hold the address of any type-castable type

#include <stdio.h>
int main()
{
    int a = 10;
    char b = 'x';

    // void pointer holds address of int 'a'
    void* p = &a;
    // void pointer holds address of char 'b'
    p = &b;
}
```

## Properties of Void Pointers  

### 1. Void pointers cannot be dereferenced.  

#### Example  

The following program doesn’t compile:  

```c
// C Program to demonstrate that a void pointer
// cannot be dereferenced

#include <stdio.h>
int main()
{
    int a = 10;
    void* ptr = &a;
    printf("%d", *ptr);

    return 0;
}
```

**Output**  

```
Compiler Error: 'void*' is not a pointer-to-object type
```

The below program demonstrates the usage of a void pointer to store the address of an integer variable. The void pointer is typecasted to an integer pointer and then dereferenced to access the value. The following program compiles and runs fine.  

```c
// C program to dereference the void
// pointer to access the value

#include <stdio.h>

int main()
{
    int a = 10;
    void* ptr = &a;
    // The void pointer 'ptr' is cast to an integer pointer
    // using '(int*)ptr' Then, the value is dereferenced
    // with `*(int*)ptr` to get the value at that memory
    // location
    printf("%d", *(int*)ptr);
    return 0;
}
```

**Output**  

```
10
```



### 2. The C standard doesn’t allow pointer arithmetic with void pointers.  
However, in GNU C, it is allowed by considering the size of the void as 1.  

#### Example  

The below C program demonstrates the usage of a void pointer to perform pointer arithmetic and access a specific memory location. The following program compiles and runs fine in `gcc`.  

```c
// C program to demonstrate the usage
// of a void pointer to perform pointer
// arithmetic and access a specific memory location

#include <stdio.h>

int main()
{
    // Declare and initialize an integer array 'a' with two elements
    int a[2] = { 1, 2 };
    
    // Declare a void pointer and assign the address of array 'a' to it
    void* ptr = &a;

    // Increment the pointer by the size of an integer
    ptr = ptr + sizeof(int);

    // The void pointer 'ptr' is cast to an integer pointer
    // using '(int*)ptr'. Then, the value is dereferenced
    // with `*(int*)ptr` to get the value at that memory location
    printf("%d", *(int*)ptr);

    return 0;
}
```
```
**Output**  
2
```

---

## 11. `NULL` Pointer

A `NULL` pointer is a pointer that does not point to any valid memory location. It is often used to indicate that a pointer is not initialized or to mark the end of a data structure (e.g., a linked list).

### Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int *ptr = NULL;

    if (ptr == NULL) {
        cout << "Pointer is NULL" << endl;  // Output: Pointer is NULL
    } else {
        cout << "Pointer is not NULL" << endl;
    }

    return 0;
}
```

- Always initialize pointers to `NULL` if they are not assigned a valid address.
- Dereferencing a `NULL` pointer will result in a runtime error (segmentation fault).

---


## 12. Accessing Members of Structs and Classes Using `->` Operator

When working with **pointers to structs or classes**, you use the `->` operator to access their members.

### Why Use `->`?

The dot operator (`.`) is used with objects (or variables) directly. But if you have a pointer to an object, you cannot use the dot operator directly—you must dereference the pointer first. The `->` operator is shorthand for dereferencing and accessing a member.

---

### Syntax:

```cpp
pointer->member
```

Equivalent to:

```cpp
(*pointer).member
```

---

### Example with Struct:

```cpp
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p = {"Alice", 30};
    Person* ptr = &p;

    cout << ptr->name << endl;  // Output: Alice
    cout << ptr->age << endl;   // Output: 30

    // Equivalent to:
    cout << (*ptr).name << endl;
    cout << (*ptr).age << endl;

    return 0;
}
```

---

### Example with Class:

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    void honk() {
        cout << "Beep!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";

    Car* ptr = &myCar;
    cout << ptr->brand << endl;  // Output: Toyota
    ptr->honk();                 // Output: Beep!

    return 0;
}
```

---

### When to Use:

* Use `.` when you have an **object**.
* Use `->` when you have a **pointer to an object**.

---

## 13. Common Pitfalls and Best Practices

- **Dangling Pointers**: Avoid using pointers that point to deallocated memory.
- **Memory Leaks**: Always free dynamically allocated memory when it is no longer needed.
- **Null Pointers**: Initialize pointers to `NULL` and check for `NULL` before dereferencing.
- **Pointer Arithmetic**: Be careful when performing arithmetic on pointers to avoid out-of-bounds errors.

# Differences Between C and C++ in Pointers 

While C and C++ share many similarities, there are some key differences in how pointers are used and managed between the two languages. This tutorial highlights these differences, excluding function pointers, to help you understand how pointers behave in C++ compared to C.


## 1. Introduction

C++ builds on the foundation of C, adding new features and improvements. While the basic concept of pointers remains the same, C++ introduces additional mechanisms like **references**, **smart pointers**, and **type-safe memory management** that make working with pointers safer and more efficient.

---

## 2. Pointer Declaration and Initialization

### C
In C, pointers are declared and initialized as follows:
```c
int x = 10;
int *ptr = &x;  // ptr holds the address of x
```

### C++
In C++, the syntax is the same, but C++ encourages the use of `nullptr` instead of `NULL` for null pointers:
```cpp
int x = 10;
int *ptr = &x;  // ptr holds the address of x
int *nullPtr = nullptr;  // C++ style null pointer
```

#### Key Difference:
- C++ introduces `nullptr` as a type-safe alternative to `NULL`. `nullptr` is of type `std::nullptr_t` and avoids ambiguities that can arise with `NULL` (which is typically defined as `0`).

---

## 3. Dynamic Memory Allocation

### C
In C, dynamic memory allocation is done using `malloc`, `calloc`, and `free`:
```c
int *ptr = (int *)malloc(sizeof(int));  // Allocate memory
*ptr = 10;
free(ptr);  // Free memory
```

### C++
In C++, dynamic memory allocation is done using `new` and `delete`:
```cpp
int *ptr = new int;  // Allocate memory
*ptr = 10;
delete ptr;  // Free memory
```

For arrays:
```cpp
int *arr = new int[5];  // Allocate memory for an array
delete[] arr;  // Free memory for an array
```

#### Key Differences:
- `new` and `delete` are type-safe and do not require explicit type casting.
- `new` calls the constructor for objects, and `delete` calls the destructor.
- `malloc` and `free` do not call constructors or destructors.

---

## 4. References in C++

### C
C does not have references. Pointers are the only way to indirectly access variables.

### C++
C++ introduces **references**, which are aliases for variables. References are safer and easier to use than pointers in many cases:
```cpp
int x = 10;
int &ref = x;  // ref is a reference to x
ref = 20;      // Modifies x
cout << x;     // Output: 20
```

#### Key Differences:
- References cannot be `nullptr` and must be initialized when declared.
- References cannot be reassigned to refer to another variable.
- References are often used in function parameters to avoid copying large objects.

---

## 5. Smart Pointers in C++

### C
C does not have smart pointers. Memory management is entirely manual using `malloc` and `free`.

### C++
C++ introduces **smart pointers** to automate memory management and prevent memory leaks:
- **`unique_ptr`**: Manages a single object with exclusive ownership.
- **`shared_ptr`**: Manages an object with shared ownership (reference counting).
- **`weak_ptr`**: A non-owning pointer that works with `shared_ptr`.

Example:
```cpp
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(10);  // Automatically freed
    cout << *ptr << endl;  // Output: 10
    return 0;
}
```

#### Key Differences:
- Smart pointers automatically manage memory, reducing the risk of memory leaks and dangling pointers.
- C++ smart pointers are part of the Standard Template Library (STL) and are not available in C.

---

## 6. Example from lecutre

```cpp

#include <iostream>
#include <memory>

using namespace std;

struct A {
    int x;

    A() : x(0) {
        cout << "A constructor (default)\n";
    }

     A(int x) : x(x) {
        cout << "A constructor(" << x << ")\n";
    }

    ~A() {
        cout << "A destructor(" << x << ")\n";
    }
};

int main() {
    A a;
    A b(10);
    a.x++;

    A* p = &a;
    p->x += 10;

    A* c = new A(100);
    // a dangling memory reference you need to delete it using delete c;
    unique_ptr<A> ptr = make_unique<A>(1000);
    cout << ptr->x << endl;

    return 0;
}


```


## 6. Conclusion

While C and C++ share the same basic concept of pointers, C++ introduces several enhancements and additional features that make working with pointers safer and more efficient:

| Feature                | C                          | C++                          |
|------------------------|----------------------------|------------------------------|
| Null Pointer           | `NULL`                     | `nullptr`                    |
| Dynamic Memory         | `malloc`, `free`           | `new`, `delete`              |
| References             | Not available              | Supported                    |
| Smart Pointers         | Not available              | `unique_ptr`, `shared_ptr`, `weak_ptr` |


```
