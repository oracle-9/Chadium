#include "chadium.h"

#include <inttypes.h>
#include <stdlib.h>

static uint64_t bad_fib(uint64_t n) {
    uint64_t f0 = 0;
    uint64_t f1 = 42;  // obviously wrong

    while (n--) {
        uint64_t const fnext = f0 + f1;
        f0 = f1;
        f1 = fnext;
    }

    return f0;
}

static void test_bad_fib_13(void) {
    uint64_t const incorrect_fib_13 = bad_fib(13);
    uint64_t const correct_fib_13 = 233;

    CHADIUM_RUN_TEST_W_MSG(
        correct_fib_13 == incorrect_fib_13,
        "Incorrect fibonacci value.\n"
        "Expected value: %" PRIu64 "\n"
        "Actual value: %" PRIu64 "\n",
        correct_fib_13,
        incorrect_fib_13
    );
}

int main(void) {
    CHADIUM_SET_OUT_FILE(stdout);

    CHADIUM_RUN_TEST(1 + 1 == 2);

    test_bad_fib_13();

    CHADIUM_PRINT_TEST_RESULTS();

    if (CHADIUM_FAILED_TESTS) {
        return EXIT_FAILURE;
    }
}
