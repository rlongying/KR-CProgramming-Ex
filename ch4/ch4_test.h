//
// Created by Mengjun Wang on 2020-03-27.
//

#ifndef KR_CPROGRAMMING_CH4_TEST_H
#define KR_CPROGRAMMING_CH4_TEST_H

#include "ch4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TEST
{
    char *data;
    char* testchar;
    int expected;
} TEST;

void test_strrindex(void);
void test_atof2(void);

#endif //KR_CPROGRAMMING_CH4_TEST_H
