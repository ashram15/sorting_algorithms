# Sorting Algorithm Visualizer (C++): 

## Overview:
This project implements and analyzes five common sorting algorithms in C++. This program contains the following sorting algorithms and uses each of them to sort a large randomly assigned vector of size n. The program then displays the time taken to sort the vector using each sorting algorithm to the console (in seconds).

## Algorithms: 
**1. Bubble Sort**:
   - Simplest Sorting algorithm; works by repeatedly stepping through the list, comparing adjacent elements and swapping them if they are in the wrong order. 
   - Time Complexity: $O(n^2)$

**2. Selection Sort**:
   - Algorithm works by repeatedly finding the minimum value of each unsorted subarray in the full array and putting it at the beginning. At the end of the array, the full array will be sorted. 
   - Time Complexity: $O(n^2)$

**3. Insertion Sort**:
   - Sorts elements in the array by extracting and inserting the element in the correct spot (like sorting your hand of playing cards) 
   - Time Complexity: $O(n^2)$

**4. Quick Sort**
   - Highly efficient sorting algorithm, works by partioning and sorting based on a pivot.  
   - Time Complexity: $O(n \log n)$ (Linearithmic)

**5. Merge Sort**
   - A Highly efficient, stable, comparision-based sorting algorithm based on common divide and conquer algorithms. 
   - Time Complexity: $O(n \log n)$ (Linearithmic - Linear plus Logarithmic)
     

## How to run: 
- Clone the Repo:  
  <code>git clone git@github.com:ashram15/sorting_algorithms.git</code>
- Compile <strong>main.cpp</strong>:  
  <code>g++ main.cpp</code>
  
## To visualize results
- <code>python plot.py</code>

## Sample Result Graph (from plot.py)
<img width="1004" alt="Screenshot 2025-07-09 at 10 49 24 PM" src="https://github.com/user-attachments/assets/1aa597b5-45b7-4e27-978b-0a7f8675d8df" />


## Technologies 
- C++
- Python matplotlib (to plot)

