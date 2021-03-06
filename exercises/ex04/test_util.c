/* Example code for Software Systems at Olin College.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "endswith.h"
#include "minunit.h"
#include "trout/util.h"
#include "endswith.c"


int tests_run = 0;


static char *test_util_1() {
    char *res = icmpcode_v4(1);
    char *message = "test1 failed:icmpcode(1) should return host unreachable";
    printf("result: %s\n", res);
    mu_assert(message, !strcmp(res,"host unreachable"));
    return NULL;
}

static char *test_util_2() {
    char *res = icmpcode_v4(0);
    char *message = "test2 failed:icmpcode(0) should return network unreachable";
    printf("result: %s\n", res);
    mu_assert(message, !strcmp(res,"network unreachable"));
    return NULL;
}
static char *test_util_3() {
    char *res = icmpcode_v4(200);
    char *message = "test3 failed:icmpcode(0) should return [unknown code]";
    printf("result: %s\n", res);
    mu_assert(message, !strcmp(res,"[unknown code]"));
    return NULL;
}

static char * all_tests() {
    mu_run_test(test_util_1);
    mu_run_test(test_util_2);
    mu_run_test(test_util_3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
