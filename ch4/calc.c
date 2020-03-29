//
// Created by Mengjun Wang on 2020-03-28.
//

#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */

enum operator {
    ADDITION = '+',
    SUBTRACTION = '-',
    DIVISION = '/',
    MULTIPLICATION = '*',
    NEWLINE = '\n',
    MODULUS = '%',
    SHOWTOP = '?',
    DUPLICATE_TOP = '#',
    SWAPTOP = '~',
    CLEAR = '!'
};

void calculator(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case ADDITION:
                push(pop() + pop());
                break;
            case SUBTRACTION:
                op2 = pop();
                push(pop() - op2);
                break;
            case DIVISION:
                op2 = pop();
                if (0.0 == op2) {
                    printf("error: zero divisor\n");
                } else {
                    push(pop() / op2);
                }
                break;
            case MULTIPLICATION:
                push(pop() * pop());
                break;
            case MODULUS:
                op2 = pop();
                if (0.0 == op2) {
                    printf("error: modulus by zero");
                } else {
                    push(fmod(pop(), op2));
                }
                break;
            case SHOWTOP:
                show_top();
                break;
            case DUPLICATE_TOP:
                duplicate_top();
                break;
            case SWAPTOP:
                swap_top_two();
                break;
            case CLEAR:
                clear();
                break;
            case NEWLINE:
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("unknown command: %s\n", s);
                break;
        }
    }
}
