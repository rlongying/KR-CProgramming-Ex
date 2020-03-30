//
// Created by Mengjun Wang on 2020-03-29.
//

#ifndef KR_CPROGRAMMING_CH5_H
#define KR_CPROGRAMMING_CH5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_pointer_association();
void test_pointer_array();

/**
 * get next integer from input into *pn
 * @param pn
 * @return 0 if not a valid number, positive if a valid number
 */
int getint(int *pn);
void test_getint();

/**
 * get next double from input into *pn
 * @param pn
 * @return 0 if not a number, EOF if end of file, positive if a valid number
 */
int getfloat(double *pn);
void test_getfloat();

/**
 * pointer version of string cat
 * @param s assume s has enough space to hold t
 * @param t
 */
void strcat_p(char *s, char *t);
void test_strcat_p();

#endif //KR_CPROGRAMMING_CH5_H
