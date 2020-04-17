//
// Created by Mengjun Wang on 2020-04-11.
//

#include "ch7.h"
#include <stdarg.h>

char *get_program_name(char *s) {
    char *p;
    char *name;

    for (name = p = s; *p != '\0'; p++) {
        if (*p == '/') {
            name = p + 1;
        }
    }
    return name;
}

void convert_characters(int argc, char *argv[]) {

    int (*converter)(int c);
    if (strcmp(get_program_name(argv[0]), "tolower") == 0) {
        // to lower
        converter = tolower;
    } else if (strcmp(get_program_name(argv[0]), "toupper") == 0) {
        // to upper
        converter = toupper;
    } else {
        return;
    }

    char c;
    while (EOF != (c = getchar())) {
        putchar(converter(c));
    }

}

void minprintf(char *fmt, ...) {
    char *sval, *p;
    int ival;
    double fval;
    va_list ap; // a pointer points to the first of unnamed argument.

    va_start(ap, fmt);

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            // print directly
            putchar(*p);
            continue;
        }

        // handle unnamed argument
        switch (*++p) {
            case 'd':
                // integer
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                fval = va_arg(ap, double);
                printf("%f", fval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
        va_end(ap); // clean up
    }

}

void miniscanf(char *fmt, ...) {
    char *p;
    va_list ap;
    int *ival; // store integer
    double *fval; // store floating value
    char *sval; // store string value

    va_start(ap, fmt);

    for(p = fmt; *p; p++) {
        if(*p != '%') {
            continue;
        }

        // get specifier
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'f':
                fval = va_arg(ap, double *);
                scanf("%lf", fval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            default:
                break;
        }
        va_end(ap);

    }

}

/**
 * buf should be large enough to hold num characters including the null terminator
 * @param buff
 * @param num
 * @param fp
 * @return
 */
static char *sfgets(char *buff, int num, FILE *fp) {
    char *ptr;
    for(ptr = buff; num > 1 && (*ptr = fgetc(fp)) != EOF; num--, ptr++) {
        if(*ptr == '\n') {
            *ptr = '\0';
            return ptr;
        }
    }
    return (ferror(fp) || ptr == buff) ? NULL : buff;
}

#define MAXLINE 1024
void print_diff_line(int argc, char *argv[]) {
    if(argc == 3) {
        FILE *fp1, *fp2;
        char fp1_line[MAXLINE], fp2_line[MAXLINE];

        if((fp1 = fopen(argv[1], "r")) == NULL) {
            printf("FILE %s can't be opened.\n", argv[1]);
        }

        if((fp2 = fopen(argv[2], "r")) == NULL) {
            printf("FILE %s can't be opened.\n", argv[1]);
        }

        while(sfgets(fp1_line, MAXLINE, fp1) != NULL && sfgets(fp2_line, MAXLINE, fp2) != NULL) {
            if(strcmp(fp1_line, fp2_line) != 0) {
                printf("Different line:\n""\"%s\"\n\"%s\"\n", fp1_line, fp2_line);
            }
        }

    }
}