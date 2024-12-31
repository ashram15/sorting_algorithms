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
    vector<int> testing;
    
    unsigned int seed = time(0);
    srand(seed);
    
    for (int i = 0; i < 100000; ++i)
    {
        testing.push_back(rand() % 10 + 1); // Generate random numbers between 1 and 10
    }
    
    int n = (int) testing.size();
    cout<< "Size of array: " << n << endl;
    
    //TESTING SORTING TIMES
    clock_t start_time, end_time;
    
    //bubble sort
    start_time = clock();
    bubbleSortArray(testing);
    end_time = clock();
    double bubble_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Generate random numbers between 1 and 10
    for (int i = 0; i < n; ++i)
    {
        testing[i] = rand() % 10 + 1;
    }

    //selection sort
    start_time = clock();
    selectionSort(testing);
    end_time = clock();
    double selection_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Generate random numbers between 1 and 10
    for (int i = 0; i < n; ++i)
    {
        testing[i] = rand() % 10 + 1;
    }

    //insertion sort
    start_time = clock();
    insertionSort(testing);
    end_time = clock();
    double insertion_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Generate random numbers between 1 and 10
    for (int i = 0; i < n; ++i)
    {
        testing[i] = rand() % 10 + 1;
    }

    //quick sort
    start_time = clock();
    quickSortArray(0, n - 1, testing);
    end_time = clock();
    double quick_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Generate random numbers between 1 and 10
    for (int i = 0; i < n; ++i)
    {
        testing[i] = rand() % 10 + 1;
    }
    
    //merge sort
    start_time = clock();
    mergeSortArray(testing);
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
    while(!arr1.empty()&&!arr2.empty()){
        if(arr1.front()>arr2.front()){
            merged.push_back(arr2.front());
            arr2.erase(arr2.begin());
        }else{
            merged.push_back(arr1.front());
            arr1.erase(arr1.begin());
        }
    }
    //now wither arr1 or arr2 is empty
    while(!arr1.empty()){
        merged.push_back(arr1.front());
        arr1.erase(arr1.begin());
    }
    while(!arr2.empty()){
        merged.push_back(arr2.front());
        arr2.erase(arr2.begin());
    }
    
}

//int mergeCount = 0;
void mergeSortArray(vector<int>& arr){
    if(arr.size() <= 1){ //Base case: array is alreay sorted or empty.
        //cout<<arr.size();
        return;
    }
    //mergeCount++;
    /*vector<int> arrayOne(arr.begin(), arr.begin()+arr.size()/2);
    vector<int> arrayTwo(arr.begin()+arr.size()/2, arr.end());*/
    vector<int>arrayOne;
    vector<int>arrayTwo;
    
    int index = (int) arr.size();
    for(int i = 0; i<index/2;i++){
        arrayOne.push_back(arr[i]);
    }
    for(int i =(index/2); i<arr.size(); i++){
        arrayTwo.push_back(arr[i]);
    }
    
   
    mergeSortArray(arrayOne);
    mergeSortArray(arrayTwo);
    
    merge(arrayOne, arrayTwo, arr);
    //cout<< "Number of comparisions: "<< mergeCount<<endl;//testing
    
}

//O(nlogn)
//Quick Sort
//Partioning and Sorting based on a Pivot
int partition(int low, int high, vector<int>& part)
{
    //Choose the middle element as pivot
    int mid = low + (high - low) / 2;
    swap(part.at(low), part.at(mid));
    
    int pivot = part[low];
    
    int i = low;
    int h = high;
    
    while(i < h)
    {
        do
        {
            i++;
        } while(i <= high && part.at(i) <= pivot);
        
        do
        {
            h--;
        } while(h >= low && part.at(h) > pivot);
        
        if(i<h)
        {
            swap(part.at(i), part.at(h));
        }
        
    }

    swap(part.at(low), part.at(h)); // Place pivot in correct position
    return h; //returning the new pivot (sorted element)
        
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


