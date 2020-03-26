//
// Created by Mengjun Wang on 2020-03-25.
//

#include "ch3_test.h"

#define MAX_ELEMENT 20000
#define ITERATIONS 1000000
#define BUFFER 1000

int binary_search_b(int x, const int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (v[mid] < x) {
            low = mid + 1;
        } else if (v[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void test_binary_search() {
    int testdata[MAX_ELEMENT];
    int index = -1;                  /*  Index of found element in test data  */
    int n = 100;                 /*  Element to search for  */
    int i;
    clock_t time_taken;

    /*  Initialize test data  */

    for (i = 0; i < MAX_ELEMENT; ++i)
        testdata[i] = i;

    /*  Output approximation of time taken for
        100,000 iterations of binary_search()       */

    for (i = 0, time_taken = clock(); i < ITERATIONS; ++i) {
        index = binary_search(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);

    printf("binary_search() took %lu clocks (%f seconds)\n",
           (unsigned long) time_taken,
           (double) time_taken / CLOCKS_PER_SEC);


    /*  Output approximation of time taken for
        100,000 iterations of binary_search_b()        */

    for (i = 0, time_taken = clock(); i < ITERATIONS; ++i) {
        index = binary_search_b(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);

    printf("binary_search_b() took %lu clocks (%f seconds)\n",
           (unsigned long) time_taken,
           (double) time_taken / CLOCKS_PER_SEC);

}

void test_escape() {
    int i, c;
    char s[BUFFER], t[BUFFER];

    for (i = 0; i < BUFFER - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    s[i] = '\0';

    escape(s, t);
    printf("\n%s\n", t);
    reverse_escape(t, s);
    printf("\n%s\n", s);
}
/*
Unexpanded: a-z-
Expanded  : abcdefghijklmnopqrstuvwxyz-
Unexpanded: z-a-
Expanded  : zyxwvutsrqponmlkjihgfedcba-
Unexpanded: -1-6-
Expanded  : -123456-
Unexpanded: a-ee-a
Expanded  : abcdeedcba
Unexpanded: a-R-L
Expanded  : a-RQPONML
Unexpanded: 1-9-1
Expanded  : 123456789987654321
Unexpanded: 5-5
Expanded  : 5
EX3_3: Mismatched operands 'a-R'
 */
void test_expand() {
    char *s[] = {"a-z-", "z-a-", "-1-6-",
                 "a-ee-a", "a-R-L", "1-9-1",
                 "5-5", NULL};
    char result[100];
    int i = 0;

    while (s[i]) {

        /*  Expand and print the next string in our array s[]  */

        expand(s[i], result);
        printf("Unexpanded: %s\n", s[i]);
        printf("Expanded  : %s\n", result);
        ++i;
    }
}

