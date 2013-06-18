#include <stdio.h>
#include <stdlib.h>
#include "format_number.h"

void test_num(uint32_t n) {
    char *c = format_number(n);
    printf("%d -> %s\n", n, c);
    free(c);
}

int main(void)
{
    test_num(0);
    test_num(10);
    test_num(100);
    test_num(123);
    test_num(1234);
    test_num(12345);
    test_num(123456);
    test_num(1234567);
    test_num(12345678);
    test_num(123456789);
    test_num(1234567890);
    test_num(-1);

    return 0;
}
