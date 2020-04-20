//#include "ch2/ch2_test.h"  // exercises for chapter 2
//#include "ch3/ch3_test.h"  // exercises for chapter 3
//#include "ch4/ch4_test.h"  // exercises for chapter 4
//#include "ch5/ch5.h" // exercises for chapter 5
//#include "ch6/ch6.h" // exercises for chapter 6
//#include "ch7/ch7.h" // exercises for chapter 7
#include "ch8/ch8.h"
//#include "heap_sort.h"
#include <stdlib.h>

#define swap(t, x, y) {t tmp = x; x = y, y = tmp;} /* swap x, y of type t */

void test_swap() {
    int ix, iy;
    double dx, dy;
    char *px, *py;

    ix = 42;
    iy = 69;
    printf("integers before swap: %d and %d\n", ix, iy);
    swap(int, ix, iy);
    printf("integers after swap: %d and %d\n", ix, iy);

    dx = 123.0;
    dy = 321.0;
    printf("doubles before swap: %g and %g\n", dx, dy);
    swap(double, dx, dy);
    printf("integers after swap: %g and %g\n", dx, dy);

    px = "hello";
    py = "world";
    printf("pointers before swap: %s and %s\n", px, py);
    swap(char *, px, py);
    printf("integers after swap: %s and %s\n", px, py);
}

void test_ch2() {
    //    print_type_range();
//    test_any();
//    test_setbits();
//    test_invert();
//    test_bitcount();
//    test_lower();
}

void test_ch3() {
//    test_binary_search();
//    test_escape();
//    test_expand();
//    test_itoa();
//    test_itob();

}

void calculator(void);

void test_ch4() {
    //    test_strrindex();
//    test_atof2();
//    calculator();
//    test_itoa2();
//    test_reverse2();
}

void test_ch5() {
//    test_getint();
//    test_getfloat();
//    test_pointer_association();
//    test_pointer_array();
//    test_strcat_p();
//    test_strend();
//    test_sort_lines();
//    test_day_of_year_month_day();
}

void test_ch6() {
//    test_parse_keyword();
//    test_parse_keyword_p();
//    test_binary_tree();
}

void test_ch7(int argc, char *argv[]) {
//    printf("%s", get_program_name(argv[0]));
//    convert_characters(argc, argv);
//    test_hash_tab();
}

int main(int argc, char *argv[]) {
//    test_ch2();
//    test_ch4();
//    test_swap();
//    test_ch5();
//    test_ch6();
//    test_ch7(argc, argv);
//    test_last_stone();
//    print_diff_line(argc, argv);
    mycat(argc, argv);

    return 0;
    return 0;
}
