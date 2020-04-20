//
// Created by Mengjun Wang on 2020-04-11.
//

#ifndef KR_CPROGRAMMING_CH7_H
#define KR_CPROGRAMMING_CH7_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct _cnode {
    char *word;
    int count;
    struct _cnode *next;
} cnode;
/**
 * get the base name of a program from argv[0]
 * @param s program name can't end by /
 * @return
 */
char *get_program_name(char *s);
void convert_characters(int argc, char *argv[]);

void minprintf(char *fmt, ...);

void miniscanf(char *fmt, ...);

// read two filenames from command line, and print first different line
void print_diff_line(int argc, char *argv[]);

cnode *contains(const char *s);
cnode *insert_word(const char *s);
void test_hash_tab();

#endif //KR_CPROGRAMMING_CH7_H
