//
// Created by Mengjun Wang on 2020-03-28.
//
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
    }
    return 0;
}

void show_top(void) {
    if(sp > 0) {
        printf("top element: %f\n", val[sp - 1]);
    } else {
        printf("the stack is empty\n");
    }
}

void duplicate_top(void) {
    double temp = pop();
    push(temp);
    push(temp);
}

void swap_top_two(void) {
    if(sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("less than 2 element in stack\n");
    }
}

void clear(void) {
    sp = 0;
}
