#include <check.h>
#include <stdlib.h>

#include "format_number.h"

#define MAKE_TEST(n, r) START_TEST(test_format_##n)	\
    {							\
	char *s;					\
	ck_assert(s = format_number(n));		\
	ck_assert_str_eq(s, r);				\
	free(s);					\
    }							\
    END_TEST

/*
  basic tests
*/
MAKE_TEST(1, "1")
MAKE_TEST(123, "123")
MAKE_TEST(1234, "1,234")
MAKE_TEST(123456, "123,456")
MAKE_TEST(1234567, "1,234,567")

/*
  corner case tests
*/
MAKE_TEST(0, "0")

START_TEST(test_format_max)
{
    char *s;
    ck_assert(s = format_number(-1));
    ck_assert_str_eq(s, "4,294,967,295");
    free(s);
}
END_TEST

Suite*
format_suite()
{
    Suite *s = suite_create("Format Number");

    TCase *tc_core = tcase_create("Core");
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_format_1);
    tcase_add_test(tc_core, test_format_123);
    tcase_add_test(tc_core, test_format_1234);
    tcase_add_test(tc_core, test_format_123456);
    tcase_add_test(tc_core, test_format_1234567);

    TCase *tc_corner = tcase_create("Corner cases");
    tcase_add_test(tc_corner, test_format_0);
    tcase_add_test(tc_corner, test_format_max);
    suite_add_tcase(s, tc_corner);

    return s;
}

int main()
{
    int number_failed;
    Suite *s = format_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
