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
    for(i = 0, j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\\':
                switch(s[++i]) {
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

}
