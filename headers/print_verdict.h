#ifndef PRINT_VERDICT_H
#define PRINT_VERDICT_H

enum {SUCCESS = 1, OPEN_FAIL = -1, OUT_FAIL = -2, FILE_INFO_FAIL = -3};

typedef int res_t;

void print_verdict(res_t result);

#endif