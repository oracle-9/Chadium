# Chadium

## Description
Chadium is a lightweight C unit test library.

## Setting up
To install chadium, simply place and `#include` `chadium.h` in your project.
Additionally, you can `make` (or `make install`) to add the header to your include path (`/usr/include/`).

## Usage
Chadium consists of 7 macros:
- `CHADIUM_RAN_TESTS`: provides a read-only amount of ran tests up until this point;
- `CHADIUM_PASSED_TESTS`: provides a read-only amount of passed tests up until this point;
- `CHADIUM_FAILED_TESTS`: provides a read-only amount of failed tests up until this point;
- `CHADIUM_SET_OUT_FILE` takes a `FILE*` to which the messages will be printed to. The `FILE*` is evaluated only once. If `NULL` is given, `stderr` will be used by default. __This macro must be called at least once, before any call to CHADIUM_RUN_TEST_W_MSG and CHADIUM_PRINT_TEST_RESULTS()__, with a valid `FILE*` to a writable file;
- `CHADIUM_RUN_TEST` takes an expression that can be evaluated to a boolean, and checks if it's true. The expression is evaluated only once;
- `CHADIUM_RUN_TEST_W_MSG` is the same as `CHADIUM_RUN_TEST`, but takes an additional amount of printf-like arguments, which will be printed if the expression is false;
- `CHADIUM_PRINT_TEST_RESULTS()` prints the total amount of ran tests, passed tests and failed tests executed up until this point.

There is an [example file](https://github.com/Oracle-UM/Chadium/blob/master/examples/example.c) in the directory `examples` illustrating the usage of these macros. The following block displays its output.
```
>>> ./example.out
Incorrect fibonacci value.
Expected value: 233
Actual value: 9786
Function: test_bad_fib_13
Line: 23

Ran tests: 2
Passed tests: 1
Failed tests: 1
```
