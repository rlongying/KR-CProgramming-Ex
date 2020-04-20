//
// Created by Mengjun Wang on 2020-04-11.
//

#include "ch7.h"
void test_hash_tab() {
    char *words[] = {"wehrmarcht", "collectorate", "hello", "hello","precorrection", "hello","wehrmarcht"};
    char **wp;

    for(wp = words; wp - words < sizeof(words)/ sizeof(char *); wp++) {
        printf("wp -> %s\n", *wp);
    }
    printf("==============================================\n");
    for(int i = 0; i < sizeof(words) / sizeof(char *); i++) {
        printf("words[%d] -> %s\n", i,words[i]);
    }
//    for(wp = *words; wp - *words < sizeof(words); wp += strlen(wp) + 1) {
//        insert_word(wp);
//        np = contains(wp);
//        if(np != NULL) {
//            if(strcmp(np->word, wp) == 0) {
//                printf("%s inserted and found %d\n", np->word, np->count);
//            }else {
//                printf("%s inserted but %s found\n", wp, np->word);
//            }
//        }else {
//            printf("%s not inserted\n", wp);
//        }
//    }
}