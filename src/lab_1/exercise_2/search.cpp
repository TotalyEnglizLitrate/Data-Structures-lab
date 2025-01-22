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
