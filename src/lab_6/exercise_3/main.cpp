/*
* Write a menu driven program to do the following using an SLL stack
* 1. Get infix expression
* 2. Convert infix to postfix
* 3. Evaluvate postfix expression
* 4. Exit
*/

// TODO: allow variable names for = operator
// TODO: postfix expression evaluvation

#include <iostream>
#include "stack.hpp"

struct Op {
    char symbol;
    unsigned precedence;
};

Op assign = {'=', 0}, add = {'+', 1}, sub = {'-', 1},
         mul = {'*', 2}, divide = {'/', 2}, mod = {'%', 2};
Op *operators[] = {&assign, &add, &sub, &mul, &divide, &mod};
unsigned op_len = 6;
char *nums = "0123456789";

void menu(Stack *);
bool validate_infix(string *);
bool is_op(char);
string to_postfix(string *);
Op *get_op(char);

int main(void) {
    Stack *stack = new Stack();
    while (true)
        menu(stack);
}

void menu(Stack *stack) {
    cout << "Enter an infix expression: ";
    string infix_expr;
    cin >> infix_expr;
    if (!validate_infix(&infix_expr)) {
        cout << "Not a valid infix expression!" << endl;
    } else {
        cout << to_postfix(&infix_expr) << endl;
    }
}

bool validate_infix(string *infix_expr) {
    bool is_operator = true;
    char i_char;
    for (unsigned i = 0; i < infix_expr->length(); i++) {
        i_char = infix_expr->at(i);
        if (i_char == ' ') continue;

        if (is_operator) { 
            if (is_op(i_char)) return false;
            else is_operator = false;
        } else {
            if (!(48 <= i_char &&  i_char <= 57))
                if (!is_op(i_char)) return false;
                else is_operator = true;
        }
    }
    return !is_operator;
}

bool is_op(char c) {
    for (unsigned i = 0; i < op_len; i++) {
        if (c == operators[i]->symbol)
            return true;
    }
    return false;
}


string to_postfix(string *infix_expr) {
    string postfix_expr;
    Stack ops = Stack();
    char i_char;
    for (unsigned i = 0; i < infix_expr->length(); i++) {
        i_char = infix_expr->at(i);
        if (is_op(i_char)) {
            Op *i_op = get_op(i_char);

            repeated_check_pop:
            if (ops.peek() == nullptr) {
                ops.push(i_char);
                postfix_expr.push_back(' ');
            } else {
                Op *stack_operator = get_op(*ops.peek());
                if (stack_operator->precedence >= i_op->precedence) {
                    postfix_expr.push_back(stack_operator->symbol);
                    postfix_expr.push_back(' ');
                    ops.pop();
                    goto repeated_check_pop;
                } else {
                    ops.push(i_op->symbol);
                    postfix_expr.push_back(' ');
                }
            }   
        } else {
            postfix_expr.push_back(i_char);
        }
    }
    
    char *c;
    while ((c = ops.pop()) != nullptr)
        postfix_expr.push_back(*c);

    return postfix_expr;
}

Op *get_op(char c) {
    for (unsigned i = 0; i < op_len; i++) {
        if (c == operators[i]->symbol)
            return operators[i];
    }
    return nullptr;
}