#ifndef CADMIUM_H
#define CADMIUM_H

#include <inttypes.h>
#include <stdio.h>

uintmax_t _cadmium_ran_tests = 0;
uintmax_t _cadmium_passed_tests = 0;
uintmax_t _cadmium_failed_tests = 0;

FILE* _cadmium_out_file = NULL;

#define CADMIUM_RAN_TESTS \
    (0 + _cadmium_ran_tests)  // prevent outside assignment

#define CADMIUM_PASSED_TESTS \
    (0 + _cadmium_passed_tests)  // prevent outside assignment

#define CADMIUM_FAILED_TESTS \
    (0 + _cadmium_failed_tests)  // prevent outside assignment

#define CADMIUM_SET_OUT_FILE(out_file_ptr)    \
    do {                                      \
        extern FILE* _cadmium_out_file;       \
        if (out_file_ptr) {                   \
            _cadmium_out_file = out_file_ptr; \
        } else {                              \
            _cadmium_out_file = stderr;       \
        }                                     \
    } while (0)

#define CADMIUM_RUN_TEST(expr)                      \
    do {                                            \
        extern uintmax_t _cadmium_ran_tests;        \
        ++_cadmium_ran_tests;                       \
        if (expr) {                                 \
            extern uintmax_t _cadmium_passed_tests; \
            ++_cadmium_passed_tests;                \
        } else {                                    \
            extern uintmax_t _cadmium_failed_tests; \
            ++_cadmium_failed_tests;                \
        }                                           \
    } while (0)

#define CADMIUM_RUN_TEST_W_MSG(expr, err_msg_fmt, ...) \
    do {                                               \
        extern uintmax_t _cadmium_ran_tests;           \
        ++_cadmium_ran_tests;                          \
        if (expr) {                                    \
            extern uintmax_t _cadmium_passed_tests;    \
            ++_cadmium_passed_tests;                   \
        } else {                                       \
            extern uintmax_t _cadmium_failed_tests;    \
            ++_cadmium_failed_tests;                   \
            extern FILE* _cadmium_out_file;            \
            fprintf(                                   \
                _cadmium_out_file,                     \
                err_msg_fmt                            \
                "Function: %s\n"                       \
                "Line: %u\n\n",                        \
                __VA_ARGS__,                           \
                __func__,                              \
                __LINE__);                             \
        }                                              \
    } while (0)

#define CADMIUM_PRINT_TEST_RESULTS()            \
    do {                                        \
        extern uintmax_t _cadmium_ran_tests;    \
        extern uintmax_t _cadmium_passed_tests; \
        extern uintmax_t _cadmium_failed_tests; \
        extern FILE* _cadmium_out_file;         \
        fprintf(                                \
            _cadmium_out_file,                  \
            "Ran tests: %" PRIuMAX "\n"         \
            "Passed tests: %" PRIuMAX "\n"      \
            "Failed tests: %" PRIuMAX "\n",     \
            _cadmium_ran_tests,                 \
            _cadmium_passed_tests,              \
            _cadmium_failed_tests               \
        );                                      \
    } while (0)

#endif  // CADMIUM_H
