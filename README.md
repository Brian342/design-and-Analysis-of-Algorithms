# Design-and-Analysis-of-Algorithms
# Merging Two Sorted Lists
# HuffmanCode
# Travelling SalesPerson problem

## Overview
This project contains implementationof 3 algorithms -> 
1) merge two sorted lists into a single sorted list using C language.
2) Travelling Sales Man problem using Dynamic Programming using c langauge.
3) Huffman Coding for data compression using c language.
- Each algorithm has its own file for better understanding.


---

## Features
## Merge 2 Arrays
- Accepts two sorted lists as input from user input.
- Merges the lists while maintaining the sorted order.
- Handles edge cases, such as empty lists.
- Demonstrates efficient time complexity of **(n + m)**, where `n` and `m` are the sizes of the two input Arrays.
## Travelling Salesman Problem
- finds the shortest possible route that vists on the city onces and returns to the starting point.
- Dynamic programming Efficiently solve this problem by breaking it into smaller subproblems
## Huffman coding.

- Requires user to enter characters and their frequency
- outputs Huffman codes for each character from the user input

---

## Algorithm Design
## Merge 2 Arrays
1. Initialize two pointers (`i` for `array1` and `j` for `array2`) and an empty vector `mergedList`.
2. Traverse both lists:
   - Compare the elements at `Array1[i]` and `array2[j]`.
   - Append the smaller element to `mergedList` and increment the corresponding pointer.
3. Once one list is fully traversed, append the remaining elements of the other list to `mergedList`.
4. Return the `mergedList`.
   Recurrence Relation
- The mergeSortedArray function uses three pointers (i, j)
- to traverse both arrays (Array1 and array2).
- In the worst case, it visits each element in both arrays exactly once until both arrays are fully merged.
- The program does not involve recursive calls or splitting of the input, unlike divide-and-conquer algorithms such as Merge Sort.
- At most, there are n1+n2 comparisons where n1 is the size of the first array1 and n2 is size of array2.
- The two while loops traverse the arrays in 𝑂(𝑛1+𝑛2)and the merging process happens in the same linear time.
- Time Complexity: 𝑂(𝑛1+𝑛2) which simplifies to 𝑂(𝑛) where 𝑛 is the total size of both arrays.
- Space Complexity: 𝑂(𝑛) as the merged array of size 𝑛1 +𝑛2 
## Huffman coding
- Reads user input i.e The characters and their frequency
- Calculates the frequency of each characters input from user
- Construct a huffman Tree using Minimum-Heap
- Generates the codes based on tree structure
## Travelling salesMan
- Reads a cost matrix representing travel costs between the cities
- Solves the problem using Dynamic programming
- Outputs the minimum cost to visit all cities and return to the start

---

## Requirements
- A C compiler (e.g., g++, Clang).
- Basic knowledge of the C STL (Standard Template Library), particularly vectors.
- The codes are written using c language

---

## Code Running
### 1. save the files
save all the files on your device
```
  - Huffmancode.c
  - TravellingSalesMan.c
  - MergeSortedList.c
```
### 2. Open terminal
navigate to the location of your files

---
### Compilation
To compile the code, use a C compiler such as `g++`:
```bash
g++ MergeSortedList.cpp -o MergeSortedList
g++ Huffmancode.cpp -o Huffmancode
g++ TravellingSalesMan.cpp -o TravellingSalesMan
```

### Execution
Run the compiled program:
```bash
./TravellingSalesMan
./Huffmancode
./MergeSortedList

```

### Example Input and Output
#### Input from user MergeSortedList:
 ```
Enter the number of elements in the first array: 4
Enter the elements of the first array in sorted order :
Element 1: 1
Element 2: 3
Element 3: 5
Element 4: 7
Enter the number of elements in the second array: 3
Enter the elements of the second array in sorted error:
Element 1: 2
Element 2: 4
Element 3: 6

```

#### Output:
```
Merged Array: 1 2 3 4 5 6 7
```
#### Input from user HuffmanCode:
 ```
Enter the number of characters: 5
Enter the characters and their frequencies:
Character 1: q
Frequency of q: 23
Character 2: e
Frequency of e: 45
Character 3: r
Frequency of r: 3
Character 4: s
Frequency of s: 10
Character 5: t
Frequency of t: 7

```
#### Output:
```
Huffman Codes:
s: 000
r: 0010
t: 0011
q: 01
e: 1
```
#### Travelling Sales Man cost matrix:
 ```
  int sampleCostMatrix[MAX][MAX] = {
        {0, 11, 17, 22},
        {11, 0, 46, 25},
        {17, 46, 0, 30},
        {22, 25, 30, 0}
    };

```
#### Output:
```
The minimum cost of all cities visited = 83
```
---

## Contributing
Contributions are welcome! If you have suggestions to improve the code or documentation, feel free to fork the repository and open a pull request.

---

## Authors:
- Marylyne Nashipae
- Brian Kyalo Kimanzi
- Kaguchia Kago
  

