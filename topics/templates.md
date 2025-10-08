# C/C++ Templates

Templates in C/C++ allow us to define generic functions and classes that work with any data type. They enable code reusability and type safety while maintaining high performance.

## Why Use Templates?
- **Code Reusability**: Write generic code that works with multiple data types.
- **Type Safety**: Ensures correctness at compile-time.
- **Performance**: Eliminates the need for runtime type checking.

## Function Templates
A function template allows a function to operate on different data types without rewriting it.

### Example: Function Template for Maximum Value
```cpp
#include <iostream>
using namespace std;

// Template function to find maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 5.5 and 2.2: " << findMax(5.5, 2.2) << endl;
    return 0;
}
```

## Class Templates
A class template allows us to define a blueprint for a class that can work with any data type.

### Example: Class Template for a Simple Pair
```cpp
#include <iostream>
using namespace std;

// Template class for a pair of values
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, double> p1(10, 20.5);
    p1.display(); // Output: (10, 20.5)
    
    Pair<string, int> p2("Alice", 30);
    p2.display(); // Output: (Alice, 30)
    return 0;
}
```

## Template Specialization
Sometimes, we need a specific implementation of a template for a certain type.

### Example: Specialization for `char*`
```cpp
#include <iostream>
#include <cstring>
using namespace std;

// General template
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Specialization for char*
template <>
const char* findMax<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    cout << "Max of Hello and World: " << findMax("Hello", "World") << endl;
    return 0;
}
```

## Best Practices for Templates
- Use meaningful names for template parameters (e.g., `typename T1, T2`).
- Avoid unnecessary template instantiations to reduce compilation time.
- Consider template specialization for edge cases.

## Conclusion
C++ templates provide a powerful way to write reusable and efficient code. Function templates and class templates help achieve type safety and code flexibility, while specialization allows fine-tuning for specific needs.