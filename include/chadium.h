#ifndef CHADIUM_H
#define CHADIUM_H

#include <inttypes.h>
#include <stdio.h>

uintmax_t _chadium_ran_tests = 0;
uintmax_t _chadium_passed_tests = 0;
uintmax_t _chadium_failed_tests = 0;

FILE* _chadium_out_file = NULL;

#define CHADIUM_RAN_TESTS \
    ((uintmax_t)_chadium_ran_tests)  // prevent outside re-assignment

#define CHADIUM_PASSED_TESTS \
    ((uintmax_t)_chadium_passed_tests)  // prevent outside re-assignment

#define CHADIUM_FAILED_TESTS \
    ((uintmax_t)_chadium_failed_tests)  // prevent outside re-assignment

#define CHADIUM_SET_OUT_FILE(out_file_ptr)               \
    do {                                                 \
        extern FILE* _chadium_out_file;                  \
                                                         \
        /* prevent multiple re-evaluation */             \
        FILE* const _out_file_ptr_strict = out_file_ptr; \
                                                         \
        _chadium_out_file = _out_file_ptr_strict         \
            ? _out_file_ptr_strict                       \
            : stderr;                                    \
    } while (0)

#define CHADIUM_RUN_TEST(expr)                      \
    do {                                            \
        extern uintmax_t _chadium_ran_tests;        \
        ++_chadium_ran_tests;                       \
        if (expr) {                                 \
            extern uintmax_t _chadium_passed_tests; \
            ++_chadium_passed_tests;                \
        } else {                                    \
            extern uintmax_t _chadium_failed_tests; \
            ++_chadium_failed_tests;                \
        }                                           \
    } while (0)

#define CHADIUM_RUN_TEST_W_MSG(expr, err_msg_fmt, ...) \
    do {                                               \
        extern uintmax_t _chadium_ran_tests;           \
        ++_chadium_ran_tests;                          \
        if (expr) {                                    \
            extern uintmax_t _chadium_passed_tests;    \
            ++_chadium_passed_tests;                   \
        } else {                                       \
            extern uintmax_t _chadium_failed_tests;    \
            ++_chadium_failed_tests;                   \
            extern FILE* _chadium_out_file;            \
            fprintf(                                   \
                _chadium_out_file,                     \
                err_msg_fmt                            \
                "Function: %s\n"                       \
                "Line: %u\n\n",                        \
                __VA_ARGS__,                           \
                __func__,                              \
                __LINE__);                             \
        }                                              \
    } while (0)

#define CHADIUM_PRINT_TEST_RESULTS()            \
    do {                                        \
        extern uintmax_t _chadium_ran_tests;    \
        extern uintmax_t _chadium_passed_tests; \
        extern uintmax_t _chadium_failed_tests; \
        extern FILE* _chadium_out_file;         \
        fprintf(                                \
            _chadium_out_file,                  \
            "Ran tests: %" PRIuMAX "\n"         \
            "Passed tests: %" PRIuMAX "\n"      \
            "Failed tests: %" PRIuMAX "\n",     \
            _chadium_ran_tests,                 \
            _chadium_passed_tests,              \
            _chadium_failed_tests               \
        );                                      \
    } while (0)

#endif  // CHADIUM_H
