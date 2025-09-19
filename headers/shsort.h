#ifndef SHSORT_H
#define SHSORT_H

#include "struct.h"

void shsort(struct strings* text, const size_t len_array, size_t width, int (*my_strcmp)(const void *a1, const void *a2));

#endif