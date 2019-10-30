#ifndef CHADMIUM_H
#define CHADMIUM_H

#include <inttypes.h>
#include <stdio.h>

uintmax_t _chadmium_ran_tests = 0;
uintmax_t _chadmium_passed_tests = 0;
uintmax_t _chadmium_failed_tests = 0;

FILE* _chadmium_out_file = NULL;

#define CHADMIUM_RAN_TESTS \
    ((uintmax_t)_chadmium_ran_tests)  // prevent outside reassignment

#define CHADMIUM_PASSED_TESTS \
    ((uintmax_t)_chadmium_passed_tests)  // prevent outside reassignment

#define CHADMIUM_FAILED_TESTS \
    ((uintmax_t)_chadmium_failed_tests)  // prevent outside reassignment

#define CHADMIUM_SET_OUT_FILE(out_file_ptr)              \
    do {                                                 \
        extern FILE* _chadmium_out_file;                 \
                                                         \
        /* prevent multiple re-evaluation */             \
        FILE* const _out_file_ptr_strict = out_file_ptr; \
                                                         \
        _chadmium_out_file = _out_file_ptr_strict        \
            ? _out_file_ptr_strict                       \
            : stderr;                                    \
    } while (0)

#define CHADMIUM_RUN_TEST(expr)                      \
    do {                                             \
        extern uintmax_t _chadmium_ran_tests;        \
        ++_chadmium_ran_tests;                       \
        if (expr) {                                  \
            extern uintmax_t _chadmium_passed_tests; \
            ++_chadmium_passed_tests;                \
        } else {                                     \
            extern uintmax_t _chadmium_failed_tests; \
            ++_chadmium_failed_tests;                \
        }                                            \
    } while (0)

#define CHADMIUM_RUN_TEST_W_MSG(expr, err_msg_fmt, ...) \
    do {                                                \
        extern uintmax_t _chadmium_ran_tests;           \
        ++_chadmium_ran_tests;                          \
        if (expr) {                                     \
            extern uintmax_t _chadmium_passed_tests;    \
            ++_chadmium_passed_tests;                   \
        } else {                                        \
            extern uintmax_t _chadmium_failed_tests;    \
            ++_chadmium_failed_tests;                   \
            extern FILE* _chadmium_out_file;            \
            fprintf(                                    \
                _chadmium_out_file,                     \
                err_msg_fmt                             \
                "Function: %s\n"                        \
                "Line: %u\n\n",                         \
                __VA_ARGS__,                            \
                __func__,                               \
                __LINE__);                              \
        }                                               \
    } while (0)

#define CHADMIUM_PRINT_TEST_RESULTS()            \
    do {                                         \
        extern uintmax_t _chadmium_ran_tests;    \
        extern uintmax_t _chadmium_passed_tests; \
        extern uintmax_t _chadmium_failed_tests; \
        extern FILE* _chadmium_out_file;         \
        fprintf(                                 \
            _chadmium_out_file,                  \
            "Ran tests: %" PRIuMAX "\n"          \
            "Passed tests: %" PRIuMAX "\n"       \
            "Failed tests: %" PRIuMAX "\n",      \
            _chadmium_ran_tests,                 \
            _chadmium_passed_tests,              \
            _chadmium_failed_tests               \
        );                                       \
    } while (0)

#endif  // CHADMIUM_H
