//
// Created by Mengjun Wang on 2020-03-24.
//

#include "ch2.h"

int ctoi(char c);

void print_type_range() {
    // range of signed char, short, int, long
    // range of unsigned char, short, int, long
    printf("\nMin value of char: %d", CHAR_MIN);
    printf("\nMax value of char: %d", CHAR_MAX);
    printf("\nMax value of UNSIGNED char: %d", UCHAR_MAX);

    printf("\nMin value of short: %d", SHRT_MIN);
    printf("\nMax value of short: %d", SHRT_MAX);
    printf("\nMax value of UNSIGNED short: %d", USHRT_MAX);

    printf("\nMin value of int: %d", INT_MIN);
    printf("\nMax value of int: %d", INT_MAX);
    printf("\nMax value of UNSIGNED int: %u", UINT_MAX);

    printf("\nMin value of long: %ld", LONG_MIN);
    printf("\nMax value of long: %ld", LONG_MAX);
    printf("\nMax value of UNSIGNED long: %lu", ULONG_MAX);

    printf("\nmy motto: %s", MOTTO);


}

void notes() {
    // names of enumerators (inside a enum) must be distinct
    // values of enumerators do not need to be distinct
    // values are integers
    typedef enum boolean {
        TRUE = 1, FALSE = 0
    } bool;
    //enum choices {TRUE, FALSE}; // ERROR : redefinition of TRUE, FALSE
    enum same {
        val = 1, code = 1
    };

    enum month {
        JAN = 1, FEB, MAR, APR, MAY, JUN, JULY, AUG, SEP, OCT, NOV, DEC
    };

    enum escapes {
        BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r'
    };
    //   string concatenation in c
//    char* str = "hello"
//                "world"
//                "I am fine";
//    printf("%s", str);

//    bool b;
//    b = FALSE;
//    if(b == TRUE) {
//        printf("b is true");
//    }else {
//        printf("b is false");
//    }

}

void rewrite_for() {
    // re write the for loop without using && ||
//    for(i = 0, i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
//        s[i] = c;

    int i, lim = 1000;
    char c;
    char s[100];
    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c != EOF) {
            s[i] = c;
        }
    }
//    int a = 1;
//    char b = 'a';
//    double d = 1.0;
//    a = b;
//    b = a;
//    b = d; // narrow conversion
//    a = d;
}

/*
 * convert a string of hexadecimal digits into its equivalent integer value,
 * return -1 if s is not a string of hexadecimal digits
 */
int htoi(char *s) {
    int res = -1;
    if (*s == '0') {
        ++s;
        if (*s == 'x' || *s == 'X') {
            ++s;
            res = 0;
            while (*s != '\0') {
                char c = *s;
                int i = ctoi(c);
                if (i >= 0) {
                    res = res * 16 + ctoi(c);
                } else {
                    // not a legal hexa string
                    // reset res to -1 and return
                    res = -1;
                    break;
                }
                ++s;
            }
        }
    }
    return res;
}

void squeeze(char s1[], char s2[]) {
    typedef enum {
        TRUE = 1, FALSE = 0
    } bool;
    bool exist = FALSE;

    int i = 0, j = 0;
    for (i = 0, j = 0; s1[i] != '\0'; ++i) {
        exist = FALSE;
        char *temp = s2;
        while (*temp != '\0') {
            if (*temp == s1[i]) {
                exist = TRUE;
                break;
            }
            ++temp;
        }

        if (!exist) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

/**
 * convert a hexadecimal character to its equivalent integer, or -1 if the passed 'c' is illegal
 * @param c '0' to '9' and 'a' to 'f' or 'A' to 'F'
 * @return
 */
int ctoi(char c) {
    int res = -1;

    if (c >= '0' && c <= '9') {
        res = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        res = 10 + (c - 'a');
    } else if (c >= 'A' && c <= 'F') {
        res = 10 + (c - 'A');
    }

    return res;
}

/**
 * find the location of first occurrence of any characters in s2
 * @param s1
 * @param s2
 * @return the location of first occurrence of any character in s2, or -1
 */
int any(const char *s1, const char *s2) {
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s2[j] == s1[i]) {
                return i;
            }
        }
    }
    return -1;
}

/**
 * set n bit of x begin at position p to rightmost n bits of y
 * @param x
 * @param p position p, position 0 at the right end
 * @param n
 * @param y
 * @return modified x
 */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // rightmost n bits of y
    unsigned y_rightmost_n = y & (~(~0 << n));

    // set n bit begin at position p to 0
    x = x & ~(~(~0 << n) << (p + 1 - n));

    // set n bit begin at position p to rightmost n bits of y
    x = x | (y_rightmost_n << (p + 1 - n));
    return x;
//    return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n)); // one line code
//setbits(29638, 15, 11, 999) = 31974
//setbits(29638, 15, 12, 999) = 15990
//setbits(29638, 15, 13, 999) = 7998
//setbits(29638, 15, 14, 999) = 3998
//setbits(29638, 15, 15, 999) = 1998
//setbits(29638, 15, 16, 999) = 999
}

/**
 * invert n bits that begin at position p
 * @param x
 * @param p position p, position 0 at the right end
 * @param n
 * @return modified x
 */
unsigned invert(unsigned x, int p, int n) {
    // get n bit begin at position p
    unsigned n_bits_p = (x >> (p + 1 - n)) & ~(~0U << n);

    unsigned inverted = ~(n_bits_p << (p + 1 - n)) & (~(~0U << n) << (p + 1 - n));

    // clear target n bits to 0 and set inverted
    return ((x & ~(~(~0U << n) << (p + 1 - n))) | inverted);
//    return x ^ ((~(~0 << n)) << p + 1 - n); // one line solution
//    2ae, 3, 7: e00002ae
//    2ae, 4, 7: c00002ae
//    2ae, 5, 7: 800002ae
//    2ae, 6, 7: 2d1
//    2ae, 7, 7: 250
}

int bitcount(unsigned x) {
    int count = 0;

    while (x != 0U) {
        ++count;
        x &= (x - 1);
    }
    return count;

}

int bitcount_a(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}

///*
//   ok, the original routine we are trying to convert looks like this..
//*/
//#if ORIGINAL
///* lower: convert c to lower case; ASCII only */
//int lower(int c)
//{
//  if(c >= 'A' && c <= 'Z')
//    return c + 'a' - 'A';
//  else
//    return c;
//}
//#endif
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
//    a more portable solution
//    char *Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    char *Lowercase = "abcdefghijklmnopqrstuvwxyz";
//    char *p = NULL;
//
//    return NULL == (p = strchr(Uppercase, c)) ? c : *(Lowercase + (p - Uppercase));
}


