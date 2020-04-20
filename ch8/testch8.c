//
// Created by Mengjun Wang on 2020-04-19.
//
#include "ch8.h"
#include <assert.h>
void test_ch8() {
    int i = -1;
    unsigned j = (unsigned) i;
    printf("%u - %u\n", j, UINT_MAX);
    if(j >= 0) {
        printf("j(%) is greater than 0\n");
    }
    char c = 0Xff;
    if(c >= 0) {
        printf("char is unsinged\n");
    }else {
        printf("char is signed\n");
    }

    printf("after assertion\n");
//    char buf[BUFSIZ];
//    int n;
//    while((n = read(0, buf, BUFSIZ)) != -1) {
//        write(1, buf, n);
//    }
}