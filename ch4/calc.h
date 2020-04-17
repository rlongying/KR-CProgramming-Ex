//
// Created by Mengjun Wang on 2020-03-28.
//

#ifndef KR_CPROGRAMMING_CALC_H
#define KR_CPROGRAMMING_CALC_H

#define NUMBER '0' /* signal that a number was found */

double pop();

void push(double f);

int getop(char s[]);
int getop_2(char s[]);

int getch(void);

void ungetch(int c);

void show_top(void);

void duplicate_top(void);

/**
 * swap the top two elements of the val stack
 */
void swap_top_two(void);

void clear(void);

#endif //KR_CPROGRAMMING_CALC_H
