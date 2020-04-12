//
// Created by Mengjun Wang on 2020-04-05.
//

#include <stdlib.h>
#include "ch6.h"

extern struct key keytab[];
extern size_t NKYES;

static int compare_key_tab(const void *k1, const void *k2) {
    return strcmp(((struct key *)k1)->word, ((
    struct key *)k2) ->word);
}

void test_parse_keyword() {
    int n;
    char word[MAXWORD];
    int index;

    qsort(keytab, NKYES, sizeof(struct key), compare_key_tab);

    FILE *pfile = fopen("../ch6/input.txt", "r");
    if (pfile != NULL) {
        while (getword(word, MAXWORD,pfile) != EOF) {
            if (isalpha(word[0])) {
                if ((index = binsearch(word, keytab, NKYES)) >= 0) {
                    keytab[index].count++;
                }
            }
        }
    } else {
        perror("ERROR opening file");
    }

    fclose(pfile);
    for (index = 0; index < NKYES; ++index) {
        if (keytab[index].count > 0) {
            printf("%4d %s\n", keytab[index].count, keytab[index].word);
        }
    }
}

void test_parse_keyword_p() {
    int n;
    char word[MAXWORD];
    struct key *p;
    qsort(keytab, NKYES, sizeof(struct key), compare_key_tab);

    FILE *pfile = fopen("../ch6/input.txt", "r");
    if (pfile != NULL) {
        while (getword(word, MAXWORD,pfile) != EOF) {
            if (isalpha(word[0])) {
                if ((p = binsearch_p(word, keytab, NKYES)) != NULL) {
                    p -> count++;
                }
            }
        }
    } else {
        perror("ERROR opening file");
    }

    fclose(pfile);
    int total = 0;
    for (p = keytab; p < keytab + NKYES; p++) {
        if (p->count > 0) {
            total += p->count;
            printf("%4d %s\n", (*p).count, p->word);
        }
    }
    printf("total: %4d\n", total);
}

static void treeprint(tnode *node) {
    if (node != NULL) {
        treeprint(node->left);
        printf("%4d %s\n", node->count, node->word);
        treeprint(node->right);
    }
}

void test_binary_tree() {
    tnode *root = NULL;
    char word[MAXWORD];

    FILE *pfile = fopen("../ch6/input.txt", "r");
    if (pfile != NULL) {
        while (getword(word, MAXWORD,pfile) != EOF) {
            root = addtree(root, word);
        }
    } else {
        perror("ERROR opening file");
    }
    printf("printing nodes in tree...\n");
    treeprint(root);

    fclose(pfile);
}

void test_nlist() {

}
