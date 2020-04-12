//
// Created by Mengjun Wang on 2020-04-05.
//

#ifndef KR_CPROGRAMMING_CH6_H
#define KR_CPROGRAMMING_CH6_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct key {
    char *word;
    int count;
};

typedef struct _tnode tnode;
struct _tnode {
    char *word;
    int count;
    tnode *left;
    tnode *right;
};

struct nlist {
    struct nlist *next;
    char *name;
    char *def;
};

#define MAXWORD 100 /* max size of a word */
/* size of the keyword table */


/**
 * search word in a keyword table
 * @param word
 * @param tab
 * @param n size of tab[]
 * @return -1 if not found, or actual index if found
 */
int binsearch(char* word, struct key tab[], int n);

struct key *binsearch_p(char* word, struct key *tab, int n);

/**
 * read up to lim characters into word from 'input'
 * @param word
 * @param lim
 * @param input input source
 * @return
 */
int getword(char *word, int lim, FILE* input);
void test_parse_keyword();
void test_parse_keyword_p();

tnode *addtree(tnode *node, char *word);
void test_binary_tree();

#define  HASHSIZE 101 /* size of the hashtable */
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *def);
int undef(char *name);
void test_nlist();

#endif; //KR_CPROGRAMMING_CH6_H
