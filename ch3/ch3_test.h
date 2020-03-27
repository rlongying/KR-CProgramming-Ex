//
// Created by Mengjun Wang on 2020-03-25.
//

#ifndef KR_CPROGRAMMING_CH3_TEST_H
#define KR_CPROGRAMMING_CH3_TEST_H

#include "ch3.h"
#include <time.h>
#include <stdio.h>

typedef struct TEST
{
    char *data;
    char* testchar;
    int expected;
} TEST;

void test_binary_search();
void test_escape();
void test_expand();
void test_itoa();
void test_itob();
void test_strrindex();
void test_atof2();

#endif //KR_CPROGRAMMING_CH3_TEST_H
