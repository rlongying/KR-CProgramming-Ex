//
// Created by Mengjun Wang on 2020-03-24.
//

#include "ch2_test.h"

void test_any() {

    char *leftstr[] =
            {
                    "",
                    "a",
                    "antidisestablishmentarianism",
                    "beautifications",
                    "characteristically",
                    "deterministically",
                    "electroencephalography",
                    "familiarisation",
                    "gastrointestinal",
                    "heterogeneousness",
                    "incomprehensibility",
                    "justifications",
                    "knowledgeable",
                    "lexicographically",
                    "microarchitectures",
                    "nondeterministically",
                    "organizationally",
                    "phenomenologically",
                    "quantifications",
                    "representationally",
                    "straightforwardness",
                    "telecommunications",
                    "uncontrollability",
                    "vulnerabilities",
                    "wholeheartedly",
                    "xylophonically",
                    "youthfulness",
                    "zoologically"
            };
    char *rightstr[] =
            {
                    "",
                    "a",
                    "the",
                    "quick",
                    "brown",
                    "dog",
                    "jumps",
                    "over",
                    "lazy",
                    "fox",
                    "get",
                    "rid",
                    "of",
                    "windows",
                    "and",
                    "install",
                    "linux"
            };

    size_t numlefts = sizeof leftstr / sizeof leftstr[0];
    size_t numrights = sizeof rightstr / sizeof rightstr[0];
    size_t left = 0;
    size_t right = 0;

    int passed = 0;
    int failed = 0;

    int pos = -1;
    char *ptr = NULL;

    for (left = 0; left < numlefts; left++) {
        for (right = 0; right < numrights; right++) {
            pos = any(leftstr[left], rightstr[right]);
            ptr = strpbrk(leftstr[left], rightstr[right]);

            if (-1 == pos) {
                if (ptr != NULL) {
                    printf("Test %d/%d failed.\n", left, right);
                    ++failed;
                } else {
                    printf("Test %d/%d passed.\n", left, right);
                    ++passed;
                }
            } else {
                if (ptr == NULL) {
                    printf("Test %d/%d failed.\n", left, right);
                    ++failed;
                } else {
                    if (ptr - leftstr[left] == pos) {
                        printf("Test %d/%d passed.\n", left, right);
                        ++passed;
                    } else {
                        printf("Test %d/%d failed.\n", left, right);
                        ++failed;
                    }
                }
            }
        }
    }
    printf("\n\nTotal passes %d, fails %d, total tests %d\n",
           passed,
           failed,
           passed + failed);

}

void test_setbits() {
    unsigned i;
    unsigned j;
    unsigned k;
    int p;
    int n;

    for (i = 0; i < 30000; i += 511) {
        for (j = 0; j < 1000; j += 37) {
            for (p = 0; p < 16; p++) {
                for (n = 1; n <= p + 1; n++) {
                    k = setbits(i, p, n, j);
                    printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);
                }
            }
        }
    }
}

void test_invert() {
    unsigned x;
    int p, n;

    for (x = 0; x < 700; x += 49)
        for (n = 0; n < 8; n++)
            for (p = 0; p < 8; p++)
                printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));
}

void test_bitcount() {
    int total = 10000, passed = 0, failed = 0;
    for(int i = 0; i < total; ++i) {
        int test = bitcount(i);
        int exp = bitcount_a(i);
        if(test == exp) {
            ++passed;
        }else {
            ++failed;
        }
    }
    printf("%d total tests, %d passed, %d failed.", total, passed, failed);
}

void test_lower() {
    char *Tests = "AaBbcCD3EdFGHgIJKLhM2NOjPQRkSTlUVWfXYf0Z1";
    char *p = Tests;
    int Result = 0;

    while('\0' != *p)
    {
        Result = lower(*p);
        printf("[%c] gives [%c]\n", *p, Result);
        ++p;
    }

    /* and the obligatory boundary test */
    Result = lower(0);
    printf("'\\0' gives %d\n", Result);

}

