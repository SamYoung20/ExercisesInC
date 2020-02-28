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
#include "util.h"
#include "endswith.c"
#include "util.c"


int tests_run = 0;


static char *test_util_1() {
    char *res = icmpcode_v4(1);
    char *message = "test3 failed:icmpcode(1) should return host unreachable";
    printf("result: %s\n", res);
    mu_assert(message, res == "host unreachable");
    return NULL;
}

static char * all_tests() {
    mu_run_test(test_util_1);
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
