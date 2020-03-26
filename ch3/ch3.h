//
// Created by Mengjun Wang on 2020-03-25.
//

#ifndef KR_CPROGRAMMING_CH3_H
#define KR_CPROGRAMMING_CH3_H

/**
 * binary search
 * @param x element to search for
 * @param v array to be searched, need to be sorted in ascending order
 * @param n size o f v
 * @return -1 if not found, otherwise, the location of x
 */
int binary_search(int x, const int v[], int n);

/**
 * cope s to t, and convert '\n' and '\t' into visible escape sequence
 * eg. "hello    world" will be printed as "hello\tworld"
 * @param s
 * @param t
 */
void escape(const char* s, char* t);
void reverse_escape(const char* s, char* t);

void expand(char* s1, char* s2);

#endif //KR_CPROGRAMMING_CH3_H
