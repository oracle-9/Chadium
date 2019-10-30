#ifndef CADMIUM_H
#define CADMIUM_H

#include <inttypes.h>
#include <stdio.h>

uintmax_t cadmium_ran_tests = 0;
uintmax_t cadmium_passed_tests = 0;
uintmax_t cadmium_failed_tests = 0;

#define RUN_TEST(expr)                             \
    do {                                           \
        extern uintmax_t cadmium_ran_tests;        \
        ++cadmium_ran_tests;                       \
        if (expr) {                                \
            extern uintmax_t cadmium_passed_tests; \
            ++cadmium_passed_tests;                \
        } else {                                   \
            extern uintmax_t cadmium_failed_tests; \
            ++cadmium_failed_tests;                \
        }                                          \
    } while (0)

#define RUN_TEST_W_MESSAGE(expr, err_message_fmt, ...) \
    do {                                               \
        extern uintmax_t cadmium_ran_tests;            \
        ++cadmium_ran_tests;                           \
        if (expr) {                                    \
            extern uintmax_t cadmium_passed_tests;     \
            ++cadmium_passed_tests;                    \
        } else {                                       \
            extern uintmax_t cadmium_failed_tests;     \
            ++cadmium_failed_tests;                    \
            printf(                                    \
                err_message_fmt                        \
                "Function: %s\n"                       \
                "Line: %u\n\n",                        \
                __VA_ARGS__,                           \
                __func__,                              \
                __LINE__);                             \
        }                                              \
    } while (0)

#define PRINT_TEST_RESULTS()                   \
    do {                                       \
        extern uintmax_t cadmium_ran_tests;    \
        extern uintmax_t cadmium_passed_tests; \
        extern uintmax_t cadmium_failed_tests; \
        printf(                                \
            "Ran tests: %" PRIuMAX "\n"        \
            "Passed tests: %" PRIuMAX "\n"     \
            "Failed tests: %" PRIuMAX "\n",    \
            cadmium_ran_tests,                 \
            cadmium_passed_tests,              \
            cadmium_failed_tests               \
        );                                     \
    } while (0)

#endif  // CADMIUM_H

