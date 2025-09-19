#include <stdio.h>
#include <stdlib.h>
#include "shsort.h"
#include "struct.h"

void swap(struct strings* str1, struct strings* str2)
{
    const char* tmp_ptr = str1->ptr;
    str1->ptr = str2->ptr;
    str2->ptr = tmp_ptr;
    
    size_t tmp_len = str1->len;
    str1->len = str2->len;
    str2->len = tmp_len;
}

void shsort(struct strings* text, const size_t* len_array, int (*my_strcmp)(const void *a1, const void *a2))
{
    if (len_array == 0)
        return;
    
    size_t left = 0, right = *len_array - 1;
    size_t last_swap_right = 0, last_swap_left = 0;

    while (left < right) 
    {
        last_swap_right = left;
        for (size_t i = left; i < right; ++i) 
        {
            if (my_strcmp(&text[i], &text[i + 1]) > 0)
            {
                swap(&text[i], &text[i + 1]);
                last_swap_right = i;
            }
        }

        right = last_swap_right;

        if (left >= right)
            break;

        last_swap_left = right;

        for (size_t i = right; i > left; --i)
        {
            if (my_strcmp(&text[i - 1], &text[i]) > 0)
            {
                swap(&text[i - 1], &text[i]);
                last_swap_left = i;
            }
        }

        left = last_swap_left;
    }
}