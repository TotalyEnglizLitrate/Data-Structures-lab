/*
  Write C++ menu driven program to determine if a given number is a pallindrome, an armstrong number or a perfect number,
  normal variable allocations are not allowed, only heap allocated pointers.
*/


#include <math.h>
#include <iostream>

using namespace std;

void is_pallindrome(int*, void*, bool*);
void is_armstrong(int*, void*, bool*);
void power(int *, int*, int*);
void get_order(int*, int*);
void is_perfect(int*, void*, bool*);
void menu(void*);

int main(void) {
    // Chunk of memory for variables that are going to be used in menu function
    // so as to not re request memory on the heap for each iteration.
    // freed memory in exit case of menu.
    // Chunk is split up into various variables across multiple functions
    // so as to not have them all be re-allocated on the heap everytime the function is called
    void *chunk = malloc(
        sizeof(char) + sizeof(int) + sizeof(bool) // for menu function itself
        + sizeof(int) * 2 // For sub functions pallindrome, armstrong and perfect numbers
        + sizeof(int) * 4 // Armstrong number itself requires 1 more integer variable, power requires 3 more
        );

    if (chunk == nullptr) {
        cout << "Error allocating memory!";
        return 1;
    }

    while (true)
        menu(chunk);
}

// Takes in a chunk of heap allocated memory for assigning variables
// Calls appropriate function according to menu input
void menu(void *chunk) {
    char *input = (char *) chunk;
    int *num_check = (int *) (chunk + sizeof(char));
    bool *ret = (bool *) (chunk + sizeof(char) + sizeof(int));

    // Seperate unused memory in chunk to be passed into sub functions
    void *unused = chunk + sizeof(char) + sizeof(int) + sizeof(bool);

    cout << "Enter number to check: ";
    cin >> *num_check;

    if (*num_check < 0) {
        cout << "Number must be positive!" << endl;
        return;
    }

    cout << "a. Palindrome" << endl << "b. Armstrong number" << endl << "c. Perfect number" << endl << "d. Exit" << endl;
    cout << "Enter check to perform: ";
    cin >> *input;

    switch (*input) {

    case 'a':
    case 'A':
        is_pallindrome(num_check, unused, ret);
        cout << "The given number " << *num_check << " is" << (*ret ? " " : " not ") << "a pallindrome" << endl;
        break;

    case 'b':
    case 'B':
        is_armstrong(num_check, unused, ret);
        cout << "The given number " << *num_check << " is" << (*ret ? " " : " not ") << "an armstrong number" << endl;
        break;

    case 'c':
    case 'C':
        is_perfect(num_check, unused,ret);
        cout << "The given number " << *num_check << " is" << (*ret ? " " : " not ") << "a perfect number" << endl;
        break;

    case 'd':
    case 'D':
        free(chunk);
        exit(0);
        break;

    default:
        cout << "Invalid choice!" << endl;
    }

    cout << endl << endl;
}

// Takes in an integer and returns (by value) boolean indicating whether given number is a pallindrome or not
// Also takes in chunk of heap allocated memory for usage
void is_pallindrome(int *num, void *chunk, bool* ret) {
    int *cpy = (int *) chunk;
    int *rev = cpy + 1;

    *cpy = *num,
    *rev = 0;

    while (*cpy != 0) {
        *rev *= 10;
        *rev += *cpy % 10;
        *cpy /= 10;
    }
    
    *ret = (*rev == *num);
}

// Takes in an integer and returns (by value) boolean indicating whether given number is an armstrong number or not
// Also takes in chunk of heap allocated memory for usage
void is_armstrong(int *num, void *chunk, bool* ret) {
    int *cpy = (int *) chunk;
    int *order = cpy + 1;
    int *order_cpy = cpy + 2; // variable to pass to power as it modifies value, keep actual order in order and use this whenever power is to be calculated
    int *sum = cpy + 3;
    int *pow = cpy + 4;
    int *digit = cpy + 5;

    *cpy = *num;

    get_order(cpy, order);

    *cpy = *num;
    *sum = 0;

    while (*cpy != 0) {
        *order_cpy = *order;
        *digit = *cpy % 10;
        power(digit, order_cpy, pow);
        *sum += *pow;
        *cpy /= 10;
    }

    *ret = (*sum == *num);
}

// Helper function to armstrong for calculating powers
void power(int *base, int *power, int *ret) {
    for (*ret = 1;*power > 0; (*power)--)
        *ret *= *base;
}

// Helper function to armstrong for calculating order of a given number
void get_order(int *num, int* ret) {
    *ret = 0;
    while (*num != 0) {
        *num /= 10;
        *ret += 1;
    }
}

// Takes in an integer and returns (by value) boolean indicating whether given number is a perfect number or not
// Also takes in chunk of heap allocated memory for usage
void is_perfect(int *num, void *chunk, bool* ret) {
    int *i = (int *)chunk;
    int *sum = i + 1;

    for (*i = 1, *sum = 0; *i < *num; (*i)++) {
        if (!(*num % *i)) {
            *sum += *i;
        }
    }

    *ret = (*sum == *num);
}
