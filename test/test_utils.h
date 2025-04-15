#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMS(arr) (sizeof(arr) / sizeof(arr[0]))

// Green coloured [PASS] string
static const char *passText = "\e[32m[PASS]\e[0m";

// Some hand picked test bytes, including the status flag bitmasks
static const uint8_t testBytes[] = {0x00, 0xff, 0xf0, 0x01, 0x02, 0x04,
                                    0x08, 0x10, 0x20, 0x40, 0x80};

#endif // TEST_UTILS_H
