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