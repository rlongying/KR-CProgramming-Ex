//
// Created by Mengjun Wang on 2020-03-29.
//

#ifndef KR_CPROGRAMMING_CH5_H
#define KR_CPROGRAMMING_CH5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* MAX # of lines to be sorted, used for sort lines of text */

void test_pointer_association();
void test_pointer_array();

/**
 * read a line (including the newline character '\n') into s, return length, terminated by '\0'
 * @param s
 * @param lim read up to lim - 1 characters
 * @return length of s
 */
int getline_2(char *s, int lim);

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

/**
 * test if string t occurs at the end of the string s
 * @param s
 * @param t
 * @return 1 if yes, otherwise, 0
 */
int strend(const char *s, const char *t);
void test_strend();

/**
 * compare string
 * @return 0 if equal, -1 if first is less than second, otherwise 1
 */
int strcmp_p(const char *, const char *);

void test_sort_lines(void);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_2(char *v[], int left, int right);


#endif //KR_CPROGRAMMING_CH5_H
