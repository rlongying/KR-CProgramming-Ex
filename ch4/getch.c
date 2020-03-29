//
// Created by Mengjun Wang on 2020-03-28.
//

#include <stdio.h>

#define BUFFSIZE 100 /* buffer size for ungetch */

static char buf[BUFFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("ungetch: buf is full\n");
    }
}
