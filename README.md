# Cadmium

## Description
Cadmium is a lightweight C unit test library.

## Setting up
To install cadmium, simply place and `#include` `cadmium.h` in your project.
Additionally, you can `make` (or `make install`) to add the header to your include path (`/usr/include/`).

## Usage
Cadmium consists of 7 macros:
- `CADMIUM_RAN_TESTS`: provides a read-only amount of ran tests up until this point;
- `CADMIUM_PASSED_TESTS`: provides a read-only amount of passed tests up until this point;
- `CADMIUM_FAILED_TESTS`: provides a read-only amount of failed tests up until this point;
- `CADMIUM_SET_OUT_FILE` takes a `FILE*` to which the messages will be printed to. If `NULL` is given, `stderr` will be used by default. __This macro must be called at least once__, with a valid `FILE*` to a writable file;
- `RUN_TEST` takes an expression that can be evaluated to a boolean, and checks if it's true. The expression is evaluated only once;
- `RUN_TEST_W_MSG` is the same as `RUN_TEST`, but takes an additional amount of printf-like arguments, which will be printed if the expression is false;
- `PRINT_TEST_RESULTS()` prints the total amount of ran tests, passed tests and failed tests executed up until this point.

There is an example file in the directory `examples` illustrating the usage of these macros.
