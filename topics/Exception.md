#  **Complete Tutorial on Exceptions in C++**

---

## 🧩 1. Introduction

In C++, **exceptions** provide a structured, reliable way to handle **runtime errors**.
When something unexpected happens — like dividing by zero, a file not opening, or invalid input — exceptions allow you to **transfer control** from the point of error to an appropriate **error-handling block**.

This helps separate **normal program logic** from **error-handling logic**, improving both code readability and reliability.

---

## ⚙️ 2. Why Use Exceptions?

Before exceptions, C++ programs often used **error codes** or flags to signal problems:

```cpp
int divide(int a, int b, int& result) {
    if (b == 0)
        return -1;  // indicate error
    result = a / b;
    return 0;       // success
}
```

The main drawbacks are:

* You must remember to **check the return value** every time.
* Error-handling code gets mixed with normal logic.
* Complex systems become **hard to maintain** and debug.

✅ **Exceptions** solve these by:

* Automatically propagating errors up the call stack.
* Keeping code clean and readable.
* Allowing centralized error-handling.

---

## 🧱 3. The Basic Exception Mechanism

C++ exceptions use three keywords:

| Keyword | Purpose                                             |
| ------- | --------------------------------------------------- |
| `try`   | Defines a block of code that may throw an exception |
| `throw` | Signals (raises) an exception                       |
| `catch` | Defines a block to handle an exception              |

### Example:

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int x = 10, y = 0;
        if (y == 0)
            throw runtime_error("Division by zero!");

        cout << x / y << endl;  // never reached
    } 
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
}
```

**Output:**

```
Error: Division by zero!
Program continues...
```

---

## 🎯 4. Throwing Exceptions

You can throw **any type of object**, including:

* Built-in types (`int`, `char`, etc.)
* Strings (`std::string`, `const char*`)
* Standard library exceptions
* Custom user-defined classes

```cpp
throw 404;
throw "File not found";
throw std::runtime_error("Invalid operation");
```

---

## 🪄 5. Catching Exceptions

### Basic Syntax

```cpp
try {
    // risky code
} catch (Type variable) {
    // handle the exception
}
```

### Example

```cpp
try {
    throw 5;
}
catch (int e) {
    cout << "Caught integer exception: " << e << endl;
}
```

### Multiple Catch Blocks

You can handle different types separately:

```cpp
try {
    throw string("Error occurred");
}
catch (int e) {
    cout << "Integer exception: " << e << endl;
}
catch (const string& e) {
    cout << "String exception: " << e << endl;
}
catch (...) {
    cout << "Unknown exception caught!" << endl;
}
```

`catch(...)` is a **catch-all handler** for any exception not caught by earlier blocks.

---

## 🧠 6. The Standard Exception Hierarchy

C++ defines a set of exception classes in `<exception>` and `<stdexcept>`.

| Exception               | Description                               |
| ----------------------- | ----------------------------------------- |
| `std::exception`        | Base class for all standard exceptions    |
| `std::logic_error`      | Errors in program logic                   |
| `std::invalid_argument` | Invalid function arguments                |
| `std::out_of_range`     | Index or iterator out of bounds           |
| `std::domain_error`     | Invalid mathematical domain               |
| `std::runtime_error`    | Errors during runtime (I/O, memory, etc.) |
| `std::overflow_error`   | Arithmetic overflow                       |
| `std::underflow_error`  | Arithmetic underflow                      |

### Example:

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

void divide(int a, int b) {
    if (b == 0)
        throw invalid_argument("Denominator cannot be zero");
    cout << "Result: " << a / b << endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}
```

---

## 🧩 7. Creating Custom Exception Classes


You can define your own exception types by **inheriting from** `std::exception`.
This allows you to customize the error message and behavior.

### Example:

```cpp
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred!";
    }
};

int main() {
    try {
        throw MyException();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
```

---

### 🧠 **Note on Virtual Methods**

* The base class `std::exception` defines `what()` as **virtual**:

  ```cpp
  virtual const char* what() const noexcept;
  ```

* This means that when you catch exceptions **by base-class reference**,
  C++ will call the **derived class’s** `what()` method, not the base version.

  ```cpp
  try {
      throw MyException();
  } catch (const std::exception& e) {
      cout << e.what() << endl;  // Calls MyException::what()
  }
  ```

* This works because of **runtime polymorphism** — the decision about which version of `what()` to call is made at runtime based on the **actual object type**, not the static type of the reference.

✅ **Why it matters:**
If `what()` were not virtual, catching a derived exception through a base class reference would **lose the derived behavior**, making custom error messages invisible.

---

## 8. Stack Unwinding

When an exception is thrown:

1. The runtime starts **unwinding the stack**.
2. It destroys all local objects created since entering the current `try` block.
3. It searches for a matching `catch` block in the call chain.

### Example:

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor\n"; }
    ~Demo() { cout << "Destructor\n"; }
};

void test() {
    Demo d;
    throw runtime_error("Error inside test()");
}

int main() {
    try {
        test();
    } catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }
}
```

**Output:**

```
Constructor
Destructor
Caught: Error inside test()
```

This demonstrates that destructors are called automatically — ensuring **no memory leaks** during exception handling.

---

##  9. Functions Declared with `noexcept`

You can mark a function as **not throwing** exceptions:

```cpp
void safeFunction() noexcept {
    cout << "This function will not throw." << endl;
}
```

If a `noexcept` function does throw, the program **immediately terminates** (calls `std::terminate()`).

```cpp
void risky() noexcept {
    throw runtime_error("This will terminate the program!");
}
```

Use `noexcept` for performance-critical code or when you guarantee safety (e.g., destructors, move operations).

---

## 🔁 10. Rethrowing Exceptions

You can rethrow an exception to let another handler deal with it:

```cpp
try {
    try {
        throw runtime_error("Inner block error");
    } catch (...) {
        cout << "Inner handler\n";
        throw;  // rethrow to outer handler
    }
} catch (const exception& e) {
    cout << "Outer handler: " << e.what() << endl;
}
```

**Output:**

```
Inner handler
Outer handler: Inner block error
```

---

## 🧮 11. Exception Safety and RAII

**RAII (Resource Acquisition Is Initialization)** ensures that resources are released automatically when objects go out of scope — even during exceptions.

### Example:

```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

void readFile(const string& filename) {
    ifstream file(filename);
    if (!file)
        throw runtime_error("Cannot open file: " + filename);

    string line;
    while (getline(file, line))
        cout << line << endl;
}

int main() {
    try {
        readFile("missing.txt");
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
```

Because `ifstream` automatically closes its file in its destructor, even if an exception is thrown, **no resource leak occurs**.

---

## 🧩 12. Best Practices

✅ **Use exceptions for exceptional conditions only**
Don’t use them for normal control flow.

✅ **Catch by reference**
Avoid copying and slicing:

```cpp
catch (const std::exception& e)
```

✅ **Don’t throw from destructors**
If a destructor throws during stack unwinding, the program terminates.

✅ **Always clean up resources automatically**
Use smart pointers or RAII patterns.

✅ **Use meaningful exception types**
Throw `std::invalid_argument`, `std::runtime_error`, or your custom derived types instead of plain strings.

✅ **Document your exception behavior**
Indicate which functions may throw.

---

## 🧩 13. Comparing Exceptions vs Error Codes

| Aspect                    | Exceptions                | Error Codes                     |
| ------------------------- | ------------------------- | ------------------------------- |
| **Code clarity**          | Clean separation of logic | Error handling mixed with logic |
| **Automatic propagation** | Yes (stack unwinding)     | Must check manually             |
| **Resource cleanup**      | Automatic via destructors | Must handle manually            |
| **Performance**           | Slightly slower on throw  | Always costs runtime checks     |
| **Scalability**           | Better for large systems  | Harder to maintain              |

---

## 🧭 14. Summary

| Concept           | Description                                 |
| ----------------- | ------------------------------------------- |
| `try`             | Marks code that may throw                   |
| `throw`           | Raises an exception                         |
| `catch`           | Handles the exception                       |
| `catch(...)`      | Catch-all handler                           |
| `std::exception`  | Base class for standard exceptions          |
| `what()`          | Virtual method returning error message      |
| `noexcept`        | Declares a function will not throw          |
| Stack Unwinding   | Automatic cleanup when exceptions propagate |
| Custom Exceptions | Inherit from `std::exception`               |
| Virtual Methods   | Enable polymorphic error reporting          |

---

## 🧪 15. Complete Example Recap

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

class DivideByZero : public runtime_error {
public:
    DivideByZero() : runtime_error("Division by zero!") {}
};

double divide(double a, double b) {
    if (b == 0)
        throw DivideByZero();
    return a / b;
}

int main() {
    try {
        cout << divide(10, 0) << endl;
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program completed successfully." << endl;
}
```

**Output:**

```
Exception caught: Division by zero!
Program completed successfully.
```
