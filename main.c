//#include "ch2/ch2_test.h"  // exercises for chapter 2
//#include "ch3/ch3_test.h"  // exercises for chapter 3
//#include "ch4/ch4_test.h"  // exercises for chapter 4
#include "ch5/ch5.h" // exercises for chapter 5

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
    test_strcat_p();
}

int main() {
//    test_ch2();
//    test_ch4();
//    test_swap();
    test_ch5();

    return 0;
}
