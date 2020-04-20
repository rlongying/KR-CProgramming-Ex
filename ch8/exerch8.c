//
// Created by Mengjun Wang on 2020-04-19.
//
#include "ch8.h"
#include <string.h>

int getchar_m(void) {
    static char buf[BUFSIZ];
    static char *bufp;
    static size_t n;

    if(n == 0) {
        n = read(stdin->_file, buf, BUFSIZ); // read BUFSIZ from stdin
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

#define STDOUT 1
#define OPENING_ERROR -1
void mycat(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "error: mycat filename ...\n");
    } else {
        int fd, n;
        char buf[BUFSIZ];
        char *file_separator = "\n\n";
        while(--argc > 0) {
            if((fd = open(*++argv, O_RDONLY, 0)) != OPENING_ERROR) {
                while ((n = read(fd, buf, BUFSIZ)) > 0) {
                    if (write(STDOUT, buf, n) != n) {
                        fprintf(stderr, "error: reading %s\n", *argv);
                    }
                }
                write(STDOUT, file_separator, strlen(file_separator)); // separate files
                close(fd);
            }else {
                fprintf(stderr, "error: opening %s\n", *argv);
            }
        }
    }
}