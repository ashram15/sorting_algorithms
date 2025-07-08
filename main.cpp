//
//  sorting_algorithms.cpp
//  Time_complexity
//
//  Created by Aishwarya Ramesh on 12/30/24.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2, vector<int>& merged);
void mergeSortArray(vector<int>& arr);
int partition(int low, int high, vector<int>& part);
void quickSortArray(int low, int high, vector<int> &arr);
void bubbleSortArray(vector<int>& arr);
void selectionSort(vector<int>& arr);
void insertionSort(vector<int> &arr);

long long comparisionCount = 0;
long long swapCount = 0;


int main()
{
    vector<int> originalData;
    
    unsigned int seed = time(0);
    srand(seed);
    
    for (int i = 0; i < 50000; ++i)
    {
        originalData.push_back(rand()); // Generate random numbers between 1 and 10
    }
    
    int n = (int) originalData.size();
    cout<< "Size of array: " << n << endl;
    
    //TESTING SORTING TIMES
    clock_t start_time, end_time;
    
    //bubble sort
    vector<int> copyArray = originalData;
    start_time = clock();
    bubbleSortArray(copyArray);
    end_time = clock();
    double bubble_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    //selection sort
    copyArray = originalData;
    start_time = clock();
    selectionSort(copyArray);
    end_time = clock();
    double selection_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    //insertion sort
    copyArray = originalData;
    start_time = clock();
    insertionSort(copyArray);
    end_time = clock();
    double insertion_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    //quick sort
    copyArray = originalData;
    start_time = clock();
    quickSortArray(0, n - 1, copyArray);
    end_time = clock();
    double quick_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    
    //merge sort
    copyArray = originalData;
    start_time = clock();
    mergeSortArray(copyArray);
    end_time = clock();
    double merge_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    cout << fixed << showpoint;
    
    cout<<"\n"<<"BUBBLE SORT TIME: "<<bubble_sort_time<<endl;
    cout<<"\n"<<"SELECTION SORT TIME: "<<selection_sort_time<<endl;
    cout<<"\n"<<"INSERTION SORT TIME: "<<insertion_sort_time<<endl;
    cout<<"\n"<<"QUICK SORT TIME: "<<quick_sort_time<<endl;
    cout<<"\n"<<"MERGE SORT TIME: "<<merge_sort_time<<endl;
    
}

//O(n log n)
//sorting elements in an array using merge sort (2 methods/functions)
//Linearthmic
//Recursion
void merge(vector<int>& arr1, vector<int>& arr2, vector<int>& merged){
    merged.clear(); //clear merged vector before merging new elements.
    int i = 0, j = 0;
    
    while(i < arr1.size()&& j < arr2.size()){
        if(arr1[i] < arr2[j]){
            merged.push_back(arr1[i++]);
        }else{
            merged.push_back(arr2[j++]);
        }
    }
    //now wither arr1 or arr2 is empty
    while(i < arr1.size()){
        merged.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        merged.push_back(arr2[j++]);
    }
    
}

void mergeSortArray(vector<int>& arr){
    if(arr.size() <= 1){ //Base case: array is alreay sorted or empty.
        return;
    }
    
    vector<int> arrayOne(arr.begin(), arr.begin()+arr.size() / 2);
    vector<int> arrayTwo(arr.begin()+arr.size() / 2, arr.end());
    
   
    mergeSortArray(arrayOne);
    mergeSortArray(arrayTwo);
    
    merge(arrayOne, arrayTwo, arr);
    
}

//O(nlogn)
//Quick Sort
//This algorithm uses the Lomuto Partition Scheme. But
//Partioning and Sorting based on a Pivot
int partition(int low, int high, vector<int>& part)
{
    //Choose a random element as pivot and move this to end
    int randomIndex = low + rand() % (high - low + 1);
    swap(part[randomIndex], part[high]);
    
    int pivot = part[high]; //new pivot based on randomized selection
    int leftIndex = low-1; //new pivot location tracker
    
    //loop through partition. If an element to the right of leftIndex is less than pivot, make that element new leftIndex.
    //Now, everything to the right of new leftIndex is greater and everything to left is less.
    for(int i = low; i < high; i++){
        if(part[i] < pivot){
            leftIndex++;
            swap(part[leftIndex], part[i]);
        }
    }
    
    //After for loop is done, we have properly found our new pivot and correctly sorted it.
    //Swap old pivot location with new one.
    swap(part[high], part[leftIndex+1]);
    return leftIndex+1;
        
}

void quickSortArray(int low, int high, vector<int> &arr){
    if(low < high){ //if array has at least 2 elements
        int pivotIndex = partition(low, high, arr); //finds pivot
        quickSortArray(low, pivotIndex - 1, arr); //sort parted section less than arr[j]
        quickSortArray(pivotIndex + 1, high, arr); //sort parted section greater arr[j]
    }
}





//O(n^2)
//Quadratic
//Duplicate elements in an array
//Sorting elements using bubble sort-->2 for loops--> puts each element in its correct place one by one.
void bubbleSortArray(vector<int>& arr){
    for(int i = 1; i<arr.size(); i++){//outer for loop signifies iterations
        for(int k = 0; k<arr.size()-1; k++){
            if(arr.at(k)>arr.at(k+1)){
                //testing
                //count++;
                swap(arr[k], arr[k+1]);
            }
        }
    }
    //cout<< "Number of comparisions: "<< count<<endl;
}
//O(n^2) even in best case scenario with a mostly sorted array
//Selection Sort
//Sorting elements in an array by finding the minimum value of each unsorted subarray in the full array
/*
 *
 SIDE NOTE: WHEN PASSING VECTOR PARAMETERS, YOU SHOULD USE THE REFERENCE OPERATOR &, AS VECTORS ARE PASSED BY VALUE AND IF YOU WANT TO CHANGE A VALUE,
    YOU HAVE TO INDICATE THAT IT IS A REFERENCE TO THAT VALUE. FOR ARRAYS, YOU DO NOT HAVE TO DO THIS, BECAUSE ARRAYS ARE ALREADY PASSED BY REFERENCE.
 *
 * FOR VECTORS, IF YOU ARE ADDING A NEW ELEMENT, USE .PUSH_BACK(), NOT []. YOU CAN USE [] INSTEAD OF .AT()
 */
void selectionSort(vector<int>& arr)
{
    int minIdx = 0;
    for(int i = 0; i<arr.size(); i++){ //outer loop through all unsorted indicis in array
        minIdx = i;              //set the minimum index value as the first element index.
        for(int k = i+1; k<arr.size(); k++){ //loop through all array elements after the first element
            if(arr.at(k)<arr.at(minIdx)){  //if an array element is less than the minimum
                //testing
                //count++;
                minIdx = k;  //the index of that element becomes the minIdx
            }
        }
        swap(arr[i], arr[minIdx]); //after looping through all elements, swap the left most element with the new minimum element.
        
        //SWAP METHOD CONTEXT OR CODE//
        /*int pointer = arr[i];
        arr[i]=arr[minIdx];
        arr[minIdx]=pointer;*/
    }
    //testing
   // cout<< "Number of comparisions: "<< count<<endl;
}
//O(n^2)
//Insertion Soet
//Sorting elements in an array by extracting and inserting the element in the correct spot (like sorting your hand of playing cards)
//If partially or almost fully sorted, then time complexity maybe less the O(n^2)
void insertionSort(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        int pointer = arr.at(i);//extracted element
        int k = i-1; //index of elemnt before it
        while(k>=0 && arr.at(k)>pointer){ //loop through all elements before extracted element that are greater
                                        //than extracted element
            //testing
            //count++;
            arr.at(k+1) = arr.at(k);            //move all elements greater than arr[i] up one spot.
            k--;                        //decrement element index to loop through all indicis before element.
        }
        arr.at(k+1) = pointer; //once an elemet is less than extracted element, INSERT extracted element after that element.
        
    }
    
}


