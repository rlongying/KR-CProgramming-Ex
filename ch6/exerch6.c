//
// Created by Mengjun Wang on 2020-04-05.
//

#include "ch6.h"

struct key keytab[] = {
        "auto", 0, /*  or {"auto", 0} for each row */
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "do", 0,
        "int", 0,
        "long", 0,
        "register", 0,
        "return", 0,
        "short", 0,
        "signed", 0,
        "sizeof", 0,
        "static", 0,
        "struct", 0,
        "switch", 0,
        "typedef", 0,
        "union", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0,
        "double", 0,
        "else", 0,
        "enum", 0,
        "extern", 0,
        "float", 0,
        "for", 0,
        "goto", 0,
        "if", 0
};
const size_t NKYES = sizeof(keytab) / sizeof(keytab[0]);

int binsearch(char *word, struct key *tab, int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        int comp = strcmp(word, tab[mid].word);
        if (comp < 0) {
            high = mid - 1;
        } else if (comp > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

struct key *binsearch_p(char *word, struct key *tab, int n) {
    struct key *low, *high, *mid;
    low = tab;
    high = tab + n;

    while (low <= high) {
        /* pointer addition is illegal thus, mid = (low + high) / 2 is illegal here */
        mid = low + (high - low) / 2;
        int cmp_res = strcmp(word, mid->word);
        if (cmp_res < 0) {
            high = mid - 1;
        } else if (cmp_res > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return NULL;
}

int getword(char *word, int lim, FILE *input) {
    int c;
    char *w = word;

    while (isspace(c = getc(input)));
    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getc(input))) {
            ungetc(*w, input);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

static tnode *talloc() {
    return (tnode *) malloc(sizeof(tnode));
}

static char *strdup_2(char *w) {
    char *p;
    p = (char *) malloc(strlen(w) + 1);
    if (p != NULL) {
        strcpy(p, w);
    }
    return p;
}

tnode *addtree(tnode *node, char *word) {
    int cmp_res;
    if (node == NULL) {
        node = talloc();
        if (node != NULL) {
            node->word = strdup_2(word);
            node->count = 1;
            node->left = node->right = NULL;
        }
    } else if ((cmp_res = strcmp(word, node->word)) == 0) {
        node->count++;
    } else if (cmp_res < 0) {
        node->left = addtree(node->left, word);
    } else {
        node->right = addtree(node->right, word);
    }
    return node;
}

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval += *s + hashval * 31;
    }
    return hashval;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(np->name, s) == 0) {
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *def) {
    struct nlist *np;
    if ((np = lookup(name)) == NULL) {
        // not exist, add a new one
        np = (struct nlist *) malloc(sizeof(struct nlist));
        if (np == NULL || (np->name = strdup_2(name)) == NULL || (np->def == strdup_2(def)) == NULL)
            return NULL;
        int hashval = hash(name);
        // insert at the beginning of the existing list
        np->next = hashtab[hashval];
        hashtab[hashval] = np;

    } else {
        // found, replace the text
        free(np->def);
        if ((np->def = strdup_2(def)) == NULL) {
            return NULL;
        }
    }

    return np;
}

int undef(char *name) {
    struct nlist *np, *np_prev;
    if ((np = lookup(name)) != NULL) {
        int hashval = hash(name);
        np = hashtab[hashval];
        np_prev = NULL;

        // find the position of np, and its previous entry
        for (np_prev = NULL; np != NULL; np_prev = np, np = np->next) {
            if (strcmp(np->name, name) == 0) {
                // found
                if (np_prev == NULL) {
                    // np is the beginning of the list
                    hashtab[hashval] = np->next;
                } else {
                    np_prev->next = np->next;
                }
                free(np->name);
                free(np->def);
                free(np);
                return 1;
            }
        }
    }
    return 0; // NOT FOUND
}
