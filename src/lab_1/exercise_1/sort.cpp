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
