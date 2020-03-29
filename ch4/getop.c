//
// Created by Mengjun Wang on 2020-03-28.
//

#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getop(char *s) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        return c;
    }

    i = 0;
    if('-' == c || '+' == c) {
        if(!isdigit(s[++i] = c = getch())) {
            // not a number
            ungetch(c); // put the pre-read c into buf
            s[i] = '\0';
            return s[i - 1]; // s[i - 1] is the operator not c
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}