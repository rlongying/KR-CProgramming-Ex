//
// Created by Mengjun Wang on 2020-04-12.
//

#include "heap_sort.h"

static int size;
static int capacity;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapsort(int arr[], int n) {
    int i;
    for(i = n/2 - 1; i >= 0; i--) {
        heapify_top_down(arr, i);
    }

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}


void heapify_bottom_up(int arr[], int pos) {
    int parent;
    parent = (pos - 1) / 2;
    while(parent >= 0 && *(arr + parent) < *(arr + pos)) {
        swap(arr+parent, arr+pos);
        pos = parent;
        parent = (pos - 1) / 2;
    }
}

void heapify_top_down(int arr[], int pos) {
    int l, r, max; // index of left and right child
    l = 2 * pos + 1;
    r = 2 * pos + 2;
    max = pos;

    if(l < size && *(arr+l) > *(arr + max)) {
        max = l;
    }
    if(r < size && *(arr+r) > *(arr + max)) {
        max = r;
    }

    if(max != pos) {
        swap(arr + max, arr + pos);
        heapify_top_down(arr, max);
    }

}

void insert(int *arr, int num) {
    if(size <= capacity) {
        *(arr+ size) = num;
        heapify_bottom_up(arr, size);
        size++;
    }
}


int getMax(int *arr) {
    int max = *arr;
    *arr = *(arr + size - 1);
    size--;
    heapify_top_down(arr, 0);
    return max;
}

int lastStoneWeight(int* stones, int stonesSize){
    size = capacity = stonesSize;
    heapsort(stones, stonesSize);

    int max1, max2, left;
    while(size > 1) {
        max1 = getMax(stones);
        max2 = getMax(stones);
        printf("max1: %d, max2: %d \n", max1, max2);
        left = max1 < max2 ? max2 - max1 : max1 - max2;
        if(left != 0) {
            insert(stones, left);
        }
    }

    return 1 == size ? *stones : 0;
}

void test_last_stone() {
    int stones[] = {2, 7, 4, 1, 8, 1};
    lastStoneWeight(stones, 6);
}