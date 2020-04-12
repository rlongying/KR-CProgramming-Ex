//
// Created by Mengjun Wang on 2020-04-11.
//

#ifndef KR_CPROGRAMMING_CH7_H
#define KR_CPROGRAMMING_CH7_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * get the base name of a program from argv[0]
 * @param s program name can't end by /
 * @return
 */
char *get_program_name(char *s);
void convert_characters(int argc, char *argv[]);


#endif //KR_CPROGRAMMING_CH7_H
