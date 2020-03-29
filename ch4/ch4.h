//
// Created by Mengjun Wang on 2020-03-27.
//

#ifndef KR_CPROGRAMMING_CH4_H
#define KR_CPROGRAMMING_CH4_H

#include <stdlib.h>
#include <ctype.h>

/*
 * search for the rightmost occurrence of t in s
 * @return -1 if not found, otherwise the rightmost position
 */
int strrindex(char *s, char *t);

/**
 * converts string to double, could handle scientific notation 123.45e-6
 * @return
 */
double atof2(char []);


#endif //KR_CPROGRAMMING_CH4_H
