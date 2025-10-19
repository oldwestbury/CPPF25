# PowerPoint Export: rule of three.json


---

## Slide 1: C++: Rule of Three

**Slide Text Summary:**

C++: Rule of Three
C++: Rule of Three
CPSC 131 ~ CSU Fullerton
Kevin A. Wortman


### Shapes and Elements:

- **Shape 1** (text) at (0.045, 0.1253)
  - Text: `C++: Rule of Three`
- **Shape 2** (text) at (0.045, 0.6607)
  - Text: `CPSC 131 ~ CSU Fullerton
Kevin A. Wortman`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": []}
- **Spacing:** {"horizontal_avg": 0.0, "vertical_avg": 289.13}

---

## Slide 2: C++ Rule of Three

**Slide Text Summary:**

C++ Rule of Three
C++ Rule of Three
Recall RAII
constructor is solely responsible for new
destructor is solely responsible for delete
Rule of Three: if a class defines any of these, it must define all three:
Destructor
Copy constructor
Copy assignment operator


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `C++ Rule of Three`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `Recall RAII
constructor is solely responsible for new
destructor is solely responsible for delete
Rule of Three: if a class defines any of these, it must define all three:
Destructor
Copy constructor
Copy assignment operator`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": []}
- **Spacing:** {"horizontal_avg": 0.0, "vertical_avg": 115.1}

---

## Slide 3: Why?

**Slide Text Summary:**

Why?
Why?
These are the member functions that initialize an object
Obligated to handle new/delete
Recall
Destructor: called to destroy an object ~ needs to delete owned data members
Copy constructor: called to copy an object ~ needs to make a new copy
Copy assignment operator: called to assign = an object ~ needs to make a new copy


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Why?`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `These are the member functions that initialize an object
Obligated to handle new/delete
Recall
Destructor: called to destroy an object ~ needs to delete owned data members
Copy constructor: called to copy an object ~ needs to make a new copy
Copy assignment operator: called to assign = an object ~ needs to make a new copy`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": []}
- **Spacing:** {"horizontal_avg": 0.0, "vertical_avg": 115.1}

---

## Slide 4: Example: MaybeInt

**Slide Text Summary:**

Example: MaybeInt
Example: MaybeInt
class MaybeInt: either owns
One integer in dynamic memory; or
Nothing
Example to illustrate Rule of Three
Single responsibility principle: better to use std::optional instead


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Example: MaybeInt`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `class MaybeInt: either owns
One integer in dynamic memory; or
Nothing
Example to illustrate Rule of Three
Single responsibility principle: better to use std::optional instead`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": []}
- **Spacing:** {"horizontal_avg": 0.0, "vertical_avg": 115.1}

---

## Slide 5: Bug Example: MaybeInt

**Slide Text Summary:**

Bug Example: MaybeInt
Bug Example: MaybeInt
class MaybeInt { public:  MaybeInt() : value_(nullptr) {}  MaybeInt(int value)  : value_(new int(value)) {}  ~MaybeInt() {    if (value_ != nullptr) {      delete value_;    }   }…private:  int* value_;};
… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Bug Example: MaybeInt`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `class MaybeInt { public:  MaybeInt() : value_(nullptr) {}  MaybeInt(int value)  : value_(new int(value)) {}  ~MaybeInt() {    if (value_ != nullptr) {      delete value_;    }   }…private:  int* value_;};`
- **Shape 3** (text) at (0.5, 0.2856)
  - Text: `… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": [[1, 2]]}
- **Spacing:** {"horizontal_avg": 223.64, "vertical_avg": 57.55}

---

## Slide 6: Bug Example: MaybeInt

**Slide Text Summary:**

Bug Example: MaybeInt
(invalid)
Bug Example: MaybeInt
… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}
a::value_
7
b::value_
c::value_
nullptr
🅧 double delete


### Shapes and Elements:

- **Shape 1** (text) at (0.2948, 0.3026)
  - Text: `(invalid)`
- **Shape 2** (text) at (0.0341, 0.0724)
  - Text: `Bug Example: MaybeInt`
- **Shape 3** (text) at (0.5, 0.2856)
  - Text: `… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}`
- **Shape 4** (text) at (0.0476, 0.3027)
  - Text: `a::value_`
- **Shape 5** (text) at (0.2654, 0.3027)
  - Text: `7`
- **Shape 6** (text) at (0.0476, 0.4169)
  - Text: `b::value_`
- **Shape 7** (text) at (0.0476, 0.5311)
  - Text: `c::value_`
- **Shape 8** (text) at (0.2654, 0.5311)
  - Text: `nullptr`
- **Shape 9** (text) at (0.3238, 0.3665)
  - Text: `🅧 double delete`

### Layout Analysis:
- **Alignments:** {"vertical": [[3, 5], [3, 6], [4, 7], [5, 6]], "horizontal": [[0, 3], [0, 4], [3, 4], [6, 7]]}
- **Spacing:** {"horizontal_avg": 226.91, "vertical_avg": 57.61}
- **Clusters:** [[0, 4, 8], [0, 4], [0, 8]]

---

## Slide 7: Solution: All 3 Initialization Functions Must new

**Slide Text Summary:**

Solution: All 3 Initialization Functions Must new
Solution: All 3 Initialization Functions Must new
Destructor: called to destroy an object ~ needs to delete owned data members
Copy constructor: called to copy an object ~ needs to make a new copy
Copy assignment operator: called to assign = an object ~ needs to make a new copy


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Solution: All 3 Initialization Functions Must new`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `Destructor: called to destroy an object ~ needs to delete owned data members
Copy constructor: called to copy an object ~ needs to make a new copy
Copy assignment operator: called to assign = an object ~ needs to make a new copy`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": []}
- **Spacing:** {"horizontal_avg": 0.0, "vertical_avg": 115.1}

---

## Slide 8: Example: MaybeInt

**Slide Text Summary:**

Example: MaybeInt
Example: MaybeInt
MaybeInt() : value_(nullptr) {}  MaybeInt(int value)  : value_(new int(value)) {}  MaybeInt(const MaybeInt& other) {    if (other.value_ == nullptr) {      value_ = nullptr;    } else {      value_ = new int(*other.value_);    }  }  ~MaybeInt() {    if (value_ != nullptr) {      delete value_;    }   }
MaybeInt& operator=(const MaybeInt& other) {    if (value_ != nullptr) {      delete value_;    }    if (other.value_ == nullptr) {      value_ = nullptr;    } else {      value_ = new int(*other.value_);    }  }… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Example: MaybeInt`
- **Shape 2** (text) at (0.0341, 0.2856)
  - Text: `MaybeInt() : value_(nullptr) {}  MaybeInt(int value)  : value_(new int(value)) {}  MaybeInt(const MaybeInt& other) {    if (other.value_ == nullptr) {      value_ = nullptr;    } else {      value_ = new int(*other.value_);    }  }  ~MaybeInt() {    if (value_ != nullptr) {      delete value_;    }   }`
- **Shape 3** (text) at (0.5, 0.2856)
  - Text: `MaybeInt& operator=(const MaybeInt& other) {    if (value_ != nullptr) {      delete value_;    }    if (other.value_ == nullptr) {      value_ = nullptr;    } else {      value_ = new int(*other.value_);    }  }… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}`

### Layout Analysis:
- **Alignments:** {"vertical": [[0, 1]], "horizontal": [[1, 2]]}
- **Spacing:** {"horizontal_avg": 223.64, "vertical_avg": 57.55}

---

## Slide 9: Example: MaybeInt

**Slide Text Summary:**

Example: MaybeInt
Example: MaybeInt
… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}
a::value_
7
b::value_
7
c::value_
7
(invalid)
(invalid)
(invalid)


### Shapes and Elements:

- **Shape 1** (text) at (0.0341, 0.0724)
  - Text: `Example: MaybeInt`
- **Shape 2** (text) at (0.5, 0.2856)
  - Text: `… int main(int argc, char* argv[]) {  MaybeInt a(7);  MaybeInt b(a);  MaybeInt c;  c = a;  return 0;}`
- **Shape 3** (text) at (0.0476, 0.3027)
  - Text: `a::value_`
- **Shape 4** (text) at (0.2654, 0.3027)
  - Text: `7`
- **Shape 5** (text) at (0.0476, 0.4065)
  - Text: `b::value_`
- **Shape 6** (text) at (0.2654, 0.4065)
  - Text: `7`
- **Shape 7** (text) at (0.0476, 0.5103)
  - Text: `c::value_`
- **Shape 8** (text) at (0.2654, 0.5103)
  - Text: `7`
- **Shape 9** (text) at (0.2654, 0.3027)
  - Text: `(invalid)`
- **Shape 10** (text) at (0.2654, 0.4065)
  - Text: `(invalid)`
- **Shape 11** (text) at (0.2654, 0.5103)
  - Text: `(invalid)`

### Layout Analysis:
- **Alignments:** {"vertical": [[2, 4], [2, 6], [3, 5], [3, 7], [3, 8], [3, 9], [3, 10], [4, 6], [5, 7], [5, 8], [5, 9], [5, 10], [7, 8], [7, 9], [7, 10], [8, 9], [8, 10], [9, 10]], "horizontal": [[2, 3], [2, 8], [3, 8], [4, 5], [4, 9], [5, 9], [6, 7], [6, 10], [7, 10]]}
- **Spacing:** {"horizontal_avg": 192.7, "vertical_avg": 46.07}
- **Clusters:** [[3, 8], [5, 9], [7, 10]]
