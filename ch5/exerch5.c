//
// Created by Mengjun Wang on 2020-03-29.
//

#include "ch5.h"
#include "ctype.h"
#include <float.h>
#include <math.h>

int getch(void);

void ungetch(int);

int getint(int *pn) {
    int c, sign = 1;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // not a number
        ungetch(c);
        return 0;
    }

    if (c == '+' || c == '-') {
        sign = (c == '-') ? -1 : 1;
        c = getch();
        if (!isdigit(c)) {
            // not a number
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int getfloat(double *pn) {
    int c, sign = 1;
    double power = 1.0;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* not a number */
        return 0;
    }

    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c); /* not a number */
            return 0;
        }
        sign = (c == '-') ? -1 : 1;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    if (c == '.') {

        c = getch();
        for (power = 1; (power < DBL_MAX / 10) && isdigit(c); c = getch()) {
            *pn = *pn * 10 + (c - '0');
            power *= 10;
        }
    }

    if (c != EOF) {
        ungetch(c);
    }
    *pn *= sign;
    *pn /= power;

    return c;
}

void strcat_p(char *s, char *t) {
    while (*s)
        s++;

    while ((*s++ = *t++));
}
