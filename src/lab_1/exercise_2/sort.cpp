#include <iostream>

using namespace std;


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