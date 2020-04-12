//
// Created by Mengjun Wang on 2020-03-29.
//

#include "ch5.h"
#include "ctype.h"
#include <float.h>
#include <math.h>

#define MAXLEN 1000 /* max length of any input line */

int getch(void);

void ungetch(int);

int getint(int *pn) {
    int c, sign = 1;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // not a number
        ungetch(c);
        return 0;
    }

    if (c == '+' || c == '-') {
        sign = (c == '-') ? -1 : 1;
        c = getch();
        if (!isdigit(c)) {
            // not a number
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int getfloat(double *pn) {
    int c, sign = 1;
    double power = 1.0;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* not a number */
        return 0;
    }

    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c); /* not a number */
            return 0;
        }
        sign = (c == '-') ? -1 : 1;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    if (c == '.') {

        c = getch();
        for (power = 1; (power < DBL_MAX / 10) && isdigit(c); c = getch()) {
            *pn = *pn * 10 + (c - '0');
            power *= 10;
        }
    }

    if (c != EOF) {
        ungetch(c);
    }
    *pn *= sign;
    *pn /= power;

    return c;
}

void strcat_p(char *s, char *t) {
    while (*s)
        s++;

    while ((*s++ = *t++));
}

int strcmp_p(const char *s, const char *t) {
    while((*s) == (*t)) {
        if(*s == '\0') {
            return 0;
        }
        s++;
        t++;
    }
    return *s - *t;
}

int strend(const char *s, const char *t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    int diff = len_s - len_t;
    if(diff >= 0) {
        s += diff; // point to the position is s that is len_t away from then end of s
        if(!strcmp_p(s, t)) {
            return 1;
        }
    }

    return 0;
}

int getline_2(char *s, int lim) {
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline_2(line, MAXLEN)) > 0) {
        if(nlines >= maxlines || (p = malloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; // delete newline
            strncpy(p, line, len);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int readlines_2(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline_2(line, MAXLEN)) > 0) {
        if(nlines >= maxlines || (p = malloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; // delete newline
            strncpy(p, line, len);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; ++i) {
        printf("%s\n", lineptr[i]);
    }
}

static swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_2(char *v[], int left, int right) {
    if(left >= right) {
        return;
    }

    int last = left;
    // take the middle as pivot, and swap it to the begin of this section
    swap(v, left, left + (right - left) / 2);

    for(int i = left + 1; i <= right; ++i) {
        if(strcmp(v[i], v[left]) < 0) {
            swap(v, i, ++last); // last point to the last element which is less than pivot
        }
    }
    swap(v, last, left); // pivot is in place
    qsort_2(v, left, last - 1);
    qsort_2(v, last + 1, right);
}


static char daytab[][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, /* non leap year */
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} /* leap year */
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    if(year < 1752 || month < 1 || month > 12 || day < 1 ) {
        // not a valid year or month
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if( day > daytab[leap][month]) {
        // not a valid day
        return -1;
    }

    for(i = 1; i < month; ++i) {
        day += daytab[leap][i];
    }
    return day;
}
int day_of_year_p(int year, int month, int day) {
    int i, leap;

    if(year < 1752 || month < 1 || month > 12 || day < 1 ) {
        // not a valid year or month
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if( day > *(daytab[leap] + month)) {
        // not a valid day
        return -1;
    }

    for(i = 1; i < month; ++i) {
        day += *(daytab[leap] + i);
    }
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {

    if(year < 1752 || yearday < 1) {
        // not a valid year or month
        return -1;
    }

    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(i = 1; i <= 12 && yearday > daytab[leap][i]; ++i) {
        yearday -= daytab[leap][i];
    }

    // if i >= 13, yearday exceeds the max day of that year
    if(i < 13) {
        *pmonth = i;
        *pday = yearday;
    }else {
        return -1;
    }
    return 0;
}

int month_day_p(int year, int yearday, int *pmonth, int *pday) {

    if(year < 1752 || yearday < 1) {
        // not a valid year or month
        return -1;
    }

    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for(i = 1; i <= 12 && yearday > daytab[leap][i]; ++i) {
        yearday -= daytab[leap][i];
    }

    // if i >= 13, yearday exceeds the max day of that year
    if(i < 13) {
        *pmonth = i;
        *pday = yearday;
    }else {
        return -1;
    }
    return 0;
}