# Sort and Search
# Exercise 1
## Statement
Write а C++ menu-driven program 10 sort а given array in ascending order. Design proper functions, maintain boundary conditions and follow coding best practices. The menus are as follows:
	a. Bubble Sort
	b. Selection Sort
	c. Insertion Sort
	d. Exit
## Algorithms
### Function: menu
**Inputs:**
- choice

**Outputs:**
- action corresponding to choice
### Function: Bubble Sort
**Inputs:**
- array of integers
- no. of elements in array

**Outputs:**
- Array is sorted in place

**Algorithm:**
$\begin{flalign}&for\ i\ in\ [0,length) \\&\quad for\ j\ in\ [0, length - i - 1) \\&\quad\quad if\ array[j] > array[j+1] \\&\quad\quad\quad swap(array[j], array[j+1])\end{flalign}$

### Function: Insertion Sort
**Inputs:**
- array of integers
- no. of elements in array

**Outputs:**
- Array is sorted in place

**Algorithm**
$\begin{flalign}&for\ i\ in [0, length)\\&\quad j = i - 1\\&\quad key = array[j]\\&\quad while\ j >= 0\ and\ array[j] > array[j+1]\\&\quad\quad arr[j+1] = arr[j]\\&\quad\quad j = j + 1\\&\quad arr[j+1] = key\end{flalign}$

### Function: Selection Sort
**Inputs:**
- array of integers
- no. of elements in array

**Outputs:**
- Array is sorted in place

**Algorithm:**
$\begin{flalign}&for\ i\ in [0, length)\\&\quad min = i\\&\quad for\ j\ in [i, length)\\&\quad\quad if\ arr[j] < arr[min]\\&\quad\quad\quad min = j\\&\quad swap(arr[min], arr[i])\end{flalign}$

## Code
```c
#include <iostream>

using namespace std;

/*
  Menu driven program to take integer array input and sort it using various algorithms.
  All algorithms sort in ascending order, in place.
*/

void menu(void);
void input(int *, int *);
void bubble_sort(int [], int);
void insertion_sort(int [], int);
void select_sort(int [], int);

int main(void) {
    while (1)
        menu();
    return 0;
}

void menu(void) {
    cout << "1. bubble sort" << endl << "2. select sort" << endl << "3. insertion sort" << endl << "0. exit" << endl;
    unsigned int choice;
    cin >> choice;

    int len;
    int *arr = (int *)malloc(0); // have an empty pointer to somewhere on the heap because cpp clears if malloced and returned to caller.
    switch (choice) {
    case 0:
        exit(0);
    case 1:
        input(arr, &len);
        bubble_sort(arr, len);
        break;
    case 2:
        input(arr, &len);
        select_sort(arr, len);
        break;
    case 3:
        input(arr, &len);
        select_sort(arr, len);
        break;
    default:
        cout << "Invalid input! please try again" << endl;
        goto invalid;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    invalid:
        free(arr);
        return;
}

// Take in an empty (int) pointer to dynamically sized array, and a int pointer for length
void input(int *arr, int *len) {
    cout << "Enter number of elements in the array: ";
    cin >> *len;
    if (*len < 0) {
        cout << "Invalid length";
        exit(1);
    }

    arr = (int *)realloc(arr, sizeof(int) * *len); // see declaration of arr in menu as to why realloc instead of malloc

    for (int i = 0; i < *len; i++) {
        cout << "Enter element no. " << i +1 << ": ";
        cin >> arr[i];
    }
}


// Standard ascending bubble sort implementation
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Standard ascending insertion sort function
void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > arr[j+1]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Standard ascending select sort function
void select_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
```
## Output
![[exercise_1.png]]
# Exercise 2
## Statement
Convert the sorting program into а header file and include it into а new cpp file. Write а C++ menu-driven program for linear and binary search in this new cpp file. Utilize any of the sorting functions in the included header file to sort the input array before performing a binary search. Design proper functions, maintain boundary conditions and follow coding best practices. The menu-driven program supports the following:
	a. Linear Search
	b. Binary Search
	c. Exit
## Algorithms

### Function: menu
**Inputs:**
- choice

**Outputs:**
- action corresponding to choice

Note: Sorting algorithms used as needed from exercise 1
### Function: Binary Search
**Inputs:**
- Sorted array of integers
- Length of array
- Target element to find

**Outputs:**
- Index of first occurrence of target (-1 if not found)

**Algorithm:**
$\begin{flalign}&start = 0\\&end = length-1\\&pivot = (start + end)/2\\&while\ start \leq end\\&\quad if\ array[pivot] > target\\&\quad\quad end = pivot - 1\\&\quad else\ if\ array[pivot] < target\\&\quad\quad start = pivot + 1\\&\quad else\\&\quad\quad return\ pivot\\&\quad if\ (start + end)/2 = pivot\\&\quad\quad break\\&\quad pivot = (start + end)/2\\&return\ -1\end{flalign}$

### Function: Linear Search
**Inputs:**
- Array of integers
- Length of array
- Target element to find

**Outputs:**
- Index of first occurrence of target (-1 if not found)

**Algorithm:**
$\begin{flalign}&for\ i\ in\ [0,length)\\&\quad if\ array[i] = target\\&\quad\quad return\ i\\&return\ -1\end{flalign}$
## Code
### sort.hpp
```c
/*
  Header file for misc. sort functions

  Functionality - common for all functions
  Inputs:
    `int *` dynamically sized arrary.
    `int` length no. of elements in the array.
  Outputs:
    the first argument of type `int *` is sorted in-place in ascending order.
*/


void bubble_sort(int [], int);
void insertion_sort(int [], int);
void select_sort(int [], int);
```
### sort.cpp
```c
#include <iostream>

using namespace std;

/*
  Menu driven program to take integer array input and sort it using various algorithms.
  All algorithms sort in ascending order, in place.
*/

void menu(void);
void input(int *, int *);
void bubble_sort(int [], int);
void insertion_sort(int [], int);
void select_sort(int [], int);

int main(void) {
    while (1)
        menu();
    return 0;
}

void menu(void) {
    cout << "1. bubble sort" << endl << "2. select sort" << endl << "3. insertion sort" << endl << "0. exit" << endl;
    unsigned int choice;
    cin >> choice;

    int len;
    int *arr = (int *)malloc(0); // have an empty pointer to somewhere on the heap because cpp clears if malloced and returned to caller.
    switch (choice) {
    case 0:
        exit(0);
    case 1:
        input(arr, &len);
        bubble_sort(arr, len);
        break;
    case 2:
        input(arr, &len);
        select_sort(arr, len);
        break;
    case 3:
        input(arr, &len);
        select_sort(arr, len);
        break;
    default:
        cout << "Invalid input! please try again" << endl;
        goto invalid;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    invalid:
        free(arr);
        return;
}

// Take in an empty (int) pointer to dynamically sized array, and a int pointer for length
void input(int *arr, int *len) {
    cout << "Enter number of elements in the array: ";
    cin >> *len;
    if (*len < 0) {
        cout << "Invalid length";
        exit(1);
    }

    arr = (int *)realloc(arr, sizeof(int) * *len); // see declaration of arr in menu as to why realloc instead of malloc

    for (int i = 0; i < *len; i++) {
        cout << "Enter element no. " << i +1 << ": ";
        cin >> arr[i];
    }
}


// Standard ascending bubble sort implementation
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);   
            }
        }
    }
}

// Standard ascending insertion sort function
void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > arr[j+1]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Standard ascending select sort function
void select_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
```

### search.cpp
```c
#include <iostream>
#include "sort.hpp"

using namespace std;

/*
  Menu driven program to take integer array input and sort it and search using binary and linear search
  All algorithms return the first occurence of the given element in the array (after sorting) and -1 if the given element is not in the array
*/

int binary_search(int [], int, int);
int linear_search(int [], int, int);
void menu(void);
void input(int *, int *);

int main(void) {
    while (1)
        menu();
    return 0;
}

void menu(void) {
    cout << "1. Linear search" << endl << "2. Binary search" << endl << "0. Exit" << endl;
    unsigned int choice;
    cin >> choice;

    int len, target;
    int *arr = (int *)malloc(0); // have an empty pointer to somewhere on the heap because cpp clears if malloced and returned to caller.
    int index;
    switch (choice) {
    case 0:
        exit(0);
    case 1:
        input(arr, &len);
        select_sort(arr, len);
        cout << "Enter target element to search: ";
        cin >> target;
        index = linear_search(arr, len, target);
        break;
    case 2:
        input(arr, &len);
        select_sort(arr, len);
        cout << "Enter target element to search: ";
        cin >> target;
        index = binary_search(arr, len, target);
        break;
    default:
        cout << "Invalid input! please try again" << endl;
        goto invalid;
    }

    if (index != -1) {
        cout << "Index of the given element is: " << index << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    invalid:
        free(arr);
        return;
}

// Take in an empty (int) pointer to dynamically sized array, and a int pointer for length
void input(int *arr, int *len) {
    cout << "Enter number of elements in the array: ";
    cin >> *len;
    if (*len < 0) {
        cout << "Invalid length";
        exit(1);
    }

    arr = (int *)realloc(arr, sizeof(int) * *len); // see declaration of arr in menu as to why realloc instead of malloc

    for (int i = 0; i < *len; i++) {
        cout << "Enter element no. " << i +1 << ": ";
        cin >> arr[i];
    }
}

// Standard implementation of binary search
int binary_search(int arr[], int len, int target) {
    int start = 0, end = len - 1, pivot;
    pivot = (start + end) / 2;
    while (start <= end) {
        if (arr[pivot] > target) {
            end = pivot - 1;
        } else if (arr[pivot] < target) {
            start = pivot + 1;
        } else {
            return pivot;
        }

        if ((start + end) / 2 == pivot) {
            break;
        }

        pivot = (start + end) / 2;
    }
    
    return -1;
}

// Standard implementation of linear search
int linear_search(int arr[], int len, int target) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
```
## Output
![[exercise_2.png]]