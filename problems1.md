##  Problem Set 1

### 1. Reverse an Array

**Problem:** Write a program that reverses the elements of an array in place.
**Instructions:**

* Ask the user for the size of the array.
* Read the elements into an array.
* Reverse the array without creating a second one.
  **Example:**
  Input: `[1, 2, 3, 4, 5]`
  Output: `[5, 4, 3, 2, 1]`
  **Hint:** Use two indices (`start`, `end`) and swap elements until they meet.

---

### 2. Rotate an Array

**Problem:** Rotate an array to the right by `k` positions.
**Instructions:**

* Read array size, elements, and integer `k`.
* Perform the rotation.
  **Example:**
  Input: `[1, 2, 3, 4, 5]`, `k=2`
  Output: `[4, 5, 1, 2, 3]`
  **Hint:** Try reversing parts of the array.

---

### 3. Find Duplicate Elements

**Problem:** Print all elements that appear more than once.
**Instructions:**

* Read array size and elements.
* Output duplicates only once, even if they repeat many times.
  **Example:**
  Input: `[2, 3, 1, 2, 3, 5]`
  Output: `2, 3`
  **Hint:** Use nested loops or a frequency array.

---

### 4. Check if Array is Sorted

**Problem:** Determine if an array is sorted in ascending order.
**Instructions:**

* Read array size and elements.
* Output `"Yes"` if sorted, `"No"` otherwise.
  **Example:**
  Input: `[1, 2, 3, 4, 5]` → Yes
  Input: `[1, 3, 2, 4]` → No
  **Hint:** Compare each element with the next one.

---

### 5. String Character Frequency

**Problem:** Count frequency of each character in a string.
**Instructions:**

* Input a string (e.g., `"hello"`).
* Print each character with its frequency.
  **Example:**
  `h:1, e:1, l:2, o:1`
  **Hint:** Use an array of size 256 (ASCII).

---

### 6. Matrix Addition

**Problem:** Add two matrices of the same size.
**Instructions:**

* Input dimensions and both matrices.
* Output their sum.
  **Example:**

```
Matrix A:      Matrix B:       Sum:
1 2            4 5             5 7
3 4            6 7             9 11
```

**Hint:** Use nested loops.

---

### 7. Matrix Multiplication

**Problem:** Multiply two matrices.
**Instructions:**

* Input dimensions (A is `m×n`, B is `n×p`).
* Multiply and output `m×p` result.
  **Example:**

```
A = [1 2]     B = [3 4]
    [3 4]         [5 6]
Result = [13 16]
         [29 36]
```

**Hint:** Each element = row of A × column of B.

---

### 8. Transpose of a Matrix

**Problem:** Find transpose of a matrix.
**Instructions:**

* Input a matrix.
* Print its transpose.
  **Example:**

```
Input:  1 2 3
        4 5 6
Output: 1 4
        2 5
        3 6
```

**Hint:** Swap rows and columns.

---

### 9. Check Symmetric Matrix

**Problem:** Check if a matrix is symmetric.
**Instructions:**

* Input a square matrix.
* A matrix is symmetric if `a[i][j] == a[j][i]`.
  **Example:**

```
1 2 3
2 4 5
3 5 6  → Symmetric
```

**Hint:** Compare upper and lower triangle.

---

### 10. Frequency of Array Elements

**Problem:** Count frequency of each element in an array.
**Instructions:**

* Input array size and elements.
* Print how many times each appears.
  **Example:**
  Input: `[2, 3, 2, 4, 3]`
  Output: `2 → 2 times, 3 → 2 times, 4 → 1 time`
  **Hint:** Use another array for visited elements.

---

### 11. Majority Element

**Problem:** Find element that appears more than `n/2` times.
**Instructions:**

* Input array size and elements.
* Print element if exists, otherwise `"No majority element"`.
  **Example:**
  Input: `[3, 3, 4, 3, 5, 3, 3]` → Majority: 3
  Input: `[1, 2, 3, 4]` → No majority element
  **Hint:** Use counting; advanced students may learn Boyer-Moore.

---

### 12. Second Largest Element

**Problem:** Find the second largest element in an array.
**Instructions:**

* Input array size and elements.
* Output second largest (distinct).
  **Example:**
  Input: `[10, 20, 5, 8]` → Second largest = 10
  **Hint:** Keep track of largest and second largest while scanning.

---

### 13. Binary Search Implementation

**Problem:** Implement binary search for a sorted array.
**Instructions:**

* Input sorted array and target element.
* Print index if found, else `-1`.
  **Example:**
  Input: `[1, 3, 5, 7, 9]`, target = 7 → Found at index 3
  Input: target = 6 → Not found (-1)
  **Hint:** Use `low`, `high`, `mid` with a loop.

---

