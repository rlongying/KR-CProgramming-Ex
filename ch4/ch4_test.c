//
// Created by Mengjun Wang on 2020-03-27.
//

#include "ch4_test.h"

void test_strrindex(void) {
    TEST test[] =
            {
                    {"Hello world",                        "o", 7},
                    {"This string is littered with iiiis", "i", 32},
                    {"No 'see' letters in here",           "c", -1}
            };

    size_t numtests = sizeof test / sizeof test[0];
    size_t i;

    char ch = 'o';
    int pos;

    for (i = 0; i < numtests; i++) {
        pos = strrindex(test[i].data, test[i].testchar);

        printf("Searching %s for last occurrence of %s.\n",
               test[i].data,
               test[i].testchar);

        printf("Expected result: %d\n", test[i].expected);
        printf("%sorrect (%d).\n", pos == test[i].expected ? "C" : "Inc", pos);
    }
}

void test_atof2(void) {
    char *strings[] = {
            "1.0e43",
            "999.999",
            "123.456e-9",
            "-1.2e-3",
            "1.2e-3",
            "-1.2E3",
            "-1.2e03",
            "cat",
            "",
            0
    };
    int i = 0;
    for (; *strings[i]; i++) {
        printf("atof(%s) = %f\n", strings[i], atof(strings[i]));
        printf("atof2(%s) = %f\n", strings[i], atof2(strings[i]));
    }

}

#define MAXSTRING 1000

void test_itoa2() {
    int array[22] =
            {0,
             1,
             2,
             9,
             10,
             11,
             16,
             17,
             21,
             312,
             -0,
             -1,
             -2,
             -9,
             -10,
             -11,
             -16,
             -17,
             -21,
             -312,
             INT_MAX,
             INT_MIN,
            };

    int i;
    char s[MAXSTRING];

    for (i = 0; i < 22; ++i) {
        char* s1 = itoa2(array[i], s);
        printf("%d  ->  %s\n", array[i], s1);
    }

}

void test_reverse2() {
    char test1[] = "Hello World!";
    char test2[] = "abcd";
    char test3[] = "ab";
    char test4[] = "";

    printf("input: \"%s\"\n", test1);
    reverse2(test1);
    printf("reversed: \"%s\"\n", test1);
    reverse2(test1);
    printf("twice reversed: \"%s\"\n", test1);
    printf("input: \"%s\"\n", test2);
    reverse2(test2);
    printf("reversed: \"%s\"\n", test2);
    reverse2(test2);
    printf("twice reversed: \"%s\"\n", test2);
    printf("input: \"%s\"\n", test3);
    reverse2(test3);
    printf("reversed: \"%s\"\n", test3);
    reverse2(test3);
    printf("twice reversed: \"%s\"\n", test3);
    printf("input: \"%s\"\n", test4);
    reverse2(test4);
    printf("reversed: \"%s\"\n", test4);
    reverse2(test4);
    printf("twice reversed: \"%s\"\n", test4);

}
