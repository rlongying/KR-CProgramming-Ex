//
// Created by Mengjun Wang on 2020-04-12.
//

#ifndef KR_CPROGRAMMING_HEAP_SORT_H
#define KR_CPROGRAMMING_HEAP_SORT_H

#include <stdio.h>

void swap(int *a, int *b);
void heapsort(int *arr, int n);
void heapify_bottom_up(int *arr, int pos);
void heapify_top_down(int *arr, int pos);
void insert(int *arr, int num);
int getMax(int *arr);
int lastStoneWeight(int* stones, int stonesSize);
void test_last_stone();
#endif //KR_CPROGRAMMING_HEAP_SORT_H
