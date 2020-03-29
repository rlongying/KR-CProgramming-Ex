//
// Created by Mengjun Wang on 2020-03-27.
//

#include "ch4.h"

int strrindex(char *s, char *t) {
    int pos = -1;

    for (int i = 0; s[i] != '\0'; ++i) {
        int k, j;
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k);
        if (t[k] == '\0') {
            pos = i;
        }
    }

    return pos;
}

double atof2(char *s) {
    int sign;
    int i = 0; // index for s
    long double val = 0.0;
    double power; // power to record number of digits after decimal point

    // skip white space
    while (isspace(s[i])) {
        ++i;
    }
    // get sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    // add integer part
    while (isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
        ++i;
    }

    // looking for decimal point
    power = 1.0;
    if (s[i] == '.') {
        ++i;
        // add fractional part
        while (isdigit(s[i])) {
            val = val * 10 + (s[i] - '0');
            ++i;
            power *= 10;
        }
    }
    // looking for scientific notation
    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        int neg_exp = 0;
        if (s[i] == '-') {
            neg_exp = 1;
        }
        if (s[i] == '-' || s[i] == '+') {
            ++i;
        }

        int exp = 0;
        while (isdigit(s[i])) {
            exp = exp * 10 + (s[i] - '0');
            ++i;
        }

        if (neg_exp) {
            for (; exp > 0; --exp) {
                val /= 10;
            }
        } else {
            for (; exp > 0; --exp) {
                val *= 10;
            }
        }
    }
    return sign * val / power;
}

