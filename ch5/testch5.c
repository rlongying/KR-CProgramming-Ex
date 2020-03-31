//
// created by mengjun wang on 2020-03-29.
//

#include "ch5.h"

#define max 10

void test_getint() {
    int i, num[max];
    int val;

    for (i = 0; i < max && (val = getint(&num[i])) != EOF; i++)
        printf("num[%d] = %d, \tvalue returned: %d (%s)\n", i, num[i],
               val, val != 0 ? "number" : "not a number");
}


// 1.2 1.0 0.0 12.000 123.12313123123123123124 0.123 12.12ss 12.1
void test_getfloat() {
    int i;
    double num[max];
    int val;

    for (i = 0; i < max && (val = getfloat(&num[i])) != EOF; i++)
        printf("num[%d] = %.10f, \tvalue returned: %d (%s)\n", i, num[i],
               val, val != 0 ? "number" : "not a number");
}

void test_pointer_association() {
    int y = 10;
    int *x = &y;
    printf("size of int* : %d\n", sizeof(int *));
    printf("size of int : %d\n", sizeof(int));
    printf("%p -> %d\n", x, *x);
    printf("%p -> %d\n", x, ++*x);
    printf("%p -> %d\n", x, *x++);
    printf("%p -> %d\n", x, *x++);
    printf("%p -> %d\n", &y, y);
}

static void f(int *p) {
    printf("p: %d,  p[-1]: %d,  *(p - 1):%d\n", *p, p[-1], *(p - 1));
}

void test_pointer_array() {
    int a[] = { 0, 1, 2, 3, 4};
    for(int i = 4; i > -10; --i) {
        f(a + i);
    }
}

void test_strcat_p() {
    char testbuff[128];

    char *test[] =
            {
                    "",
                    "1",
                    "12",
                    "123",
                    "1234"
            };

    size_t numtests = sizeof test / sizeof test[0];
    size_t thistest;
    size_t inner;

    for(thistest = 0; thistest < numtests; thistest++)
    {
        for(inner = 0; inner < numtests; inner++)
        {
            strcpy(testbuff, test[thistest]);
            strcat_p(testbuff, test[inner]);

            printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
        }
    }
}

void test_strend() {
    char *s1 = "some really long string.";
    char *s2 = "ng.";
    char *s3 = "ng";

    if(strend(s1, s2))
    {
        printf("the string (%s) has (%s) at the end.\n", s1, s2);
    }
    else
    {
        printf("the string (%s) doesn't have (%s) at the end.\n", s1, s2);
    }
    if(strend(s1, s3))
    {
        printf("the string (%s) has (%s) at the end.\n", s1, s3);
    }
    else
    {
        printf("the string (%s) doesn't have (%s) at the end.\n", s1, s3);
    }
}

void test_sort_lines(void) {
    char *lineptr[MAXLINES];
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_2(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    } else {
        printf("error: input too big to sort -> %d\n", nlines);
    }
}


