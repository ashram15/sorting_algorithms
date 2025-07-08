# Sorting Algorithm Visualizer (C++): 

## Overview:
This project implements and analyzes five common sorting algorithms in C++. This program contains the following sorting algorithms and uses each of them to sort a large randomly assigned vector of size n. The program then displays the time taken to sort the vector using each sorting algorithm to the console (in seconds).

## Algorithms: 
**1. Bubble Sort**:
   - Simplest Sorting algorithm; works by repeatedly stepping through the list, comparing adjacent elements and swapping them if they are in the wrong order. 
   - Time Complexity: `$O(n^2)$`

**2. Selection Sort**:
   - Algorithm works by repeatedly finding the minimum value of each unsorted subarray in the full array and putting it at the beginning. At the end of the array, the full array will be sorted. 
   - Time Complexity: `$O(n^2)$`

**3. Insertion Sort**:
   - Sorts elements in the array by extracting and inserting the element in the correct spot (like sorting your hand of playing cards) 
   - Time Complexity: `$O(n^2)$`

**4. Quick Sort**
   - Highly efficient sorting algorithm, works by partioning and sorting based on a pivot.  
   - Time Complexity: `O(n \log n)$` (Linearithmic)

**5. Merge Sort**
   - A Highly efficient, stable, comparision-based sorting algorithm based on common divide and conquer algorithms. 
   - Time Complexity: `O(n \log n)$` (Linearithmic - Linear plus Logarithmic)
     

## How to run: 
- Clone the Repo:
  <code>git clone git@github.com:ashram15/sorting_algorithms.git</code>
- Compile <strong>main.cpp</strong>:  
  g++ main.cpp

## Sample Result: 
Size of array: 50000  

BUBBLE SORT TIME: 18.006124 seconds  
SELECTION SORT TIME: 5.936390 seconds  
INSERTION SORT TIME: 3.764035 seconds  
QUICK SORT TIME: 0.006673 seconds  
MERGE SORT TIME: 0.279051 seconds  

## Technologies 
- C++
- standard C++ template library (STL)

