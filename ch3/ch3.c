//
// Created by Mengjun Wang on 2020-03-25.
//

#include "ch3.h"

int binary_search(int x, const int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = low + (high - low) / 2;

    while (low <= high && v[mid] != x) {

        if (v[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }
    return x == v[mid] ? mid : -1;
}

void escape(const char *s, char *t) {
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break; // not necessary break, but good to have
        }
    }
    t[j] = '\0';
}

void reverse_escape(const char *s, char *t) {
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\\':
                switch (s[++i]) {
                    case 'n':
                        t[j++] = '\n';
                        break;
                    case 't':
                        t[j++] = '\t';
                        break;
                    default:
                        t[j++] = '\\';
                        t[j++] = s[i];
                        break;
                }
                break;
            default:
                t[j++] = s[i];
                break;
        }

    }
    t[j] = '\0';
}

void expand(char *s1, char *s2) {
    int i, j;
    char start = '\0';

    for (i = 0, j = 0; s1[i] != '\0'; ++i) {
        if ('-' == s1[i] && start != '\0' && start != '-' && s1[i + 1] != '\0') {
            ++i;
            char c = start;
            char end = s1[i];

            // assume the code for 'A' to 'Z' or 'a' to 'z' or '0' to '9' is consecutive
            if ((start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z')
                || (start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z')
                || (start >= '0' && start <= '9' && end >= '0' && end <= '9')) {
                // expand
                if (start > end) {
                    while ((c -= 1) >= end) {
                        s2[j++] = c;
                    }
                } else {
                    while ((c += 1) <= end) {
                        s2[j++] = c;
                    }
                }
            } else {
                // copy the unexpanded range, such as a-A, 0-A
                s2[j++] = '-';
                s2[j++] = end;
            }
        } else {
            // no need to expand
            s2[j++] = s1[i];
        }
        start = s1[i];
    }
    s2[j] = '\0'; // don't forget the terminating null
}

void reverse(char s[]) {
    char c;
    for (unsigned long i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
    }
}

void itoa(int n, char *s) {
    int i, sign;
    int is_int_min = 0;

    // handle INT_MIN to avoid overflow when converting INT_MIN to positive
    if (n == INT_MIN) {
        n += 1;
        is_int_min = 1;
    }

    if ((sign = n) < 0) { // record sign
        n = -n; // make n positive
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0'; // record number in reverse order
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
    if (is_int_min) {
        s[i - 1] += 1;
    }
}

void itob(int n, char *s, unsigned b) {

    if (b < 2 || b > 16) {
        fprintf(stderr, "Cannot support base %d (2 - 16)\n", b);
        exit(EXIT_FAILURE);
    }

    char letters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (n < 0) {
        n = ~(-n) + 1;
    }

    int i = 0;
    do {
        s[i++] = letters[n % b];
    } while (n /= b);

    s[i] = '\0';
    reverse(s);
}
