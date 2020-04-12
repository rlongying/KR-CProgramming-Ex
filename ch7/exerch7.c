//
// Created by Mengjun Wang on 2020-04-11.
//

#include "ch7.h"

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