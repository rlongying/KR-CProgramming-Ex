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
