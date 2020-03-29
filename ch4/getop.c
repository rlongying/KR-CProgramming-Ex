//
// Created by Mengjun Wang on 2020-03-28.
//

#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getop(char *s) {
    int i;
    static int c = ' ';

    s[0] = c;
    while (s[0] == ' ' || s[0] == '\t') {
        s[0] = c = getch();
    }
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        int tmp = c;
        /*in this case, c is other ' ' or '\n', set c to ' ' so it can continue to read next character in next call */
        c = ' ';
        return tmp;
    }

    i = 0;
    if ('-' == c || '+' == c) {
        if (!isdigit(s[++i] = c = getch())) {
            // not a number
//            ungetch(c); // put the pre-read c into buf

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

//    if (c != EOF)
//        ungetch(c);
    return NUMBER;
}