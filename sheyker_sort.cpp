#include <stdio.h>
#include <stdlib.h>
#include "my_strcmp.h"
#include "shsort.h"

void shsort(const char** a, const size_t size_a) //разумеется надо добавить удаление пробелов и знаков препинания
{
    size_t left = 0, right = size_a - 1;
    size_t last_swap;
    while(left < right) {
        for(size_t i = left; i < right; ++i) {
            if(my_strcmp(a[i], a[i + 1]) > 0) {
                const char* tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                last_swap = i;
            }
        }
        right = last_swap;
        for(int i = right; i > left; --i) {
            if(my_strcmp(a[i - 1], a[i]) > 0) {
                const char* tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                last_swap = i;
            }
        }
        left = last_swap;
    }
    // for(int i = 0; i < size_a; ++i)
    //     printf("%s ", a[i]);
}

// int main()
// {
//     const char* a[] = {"abc", "cd", "acb", "ac", "zyx"};
//     size_t size_a = 5;

//     shsort(a, size_a);
//     return 0;
// }