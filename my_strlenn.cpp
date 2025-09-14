#include <stdio.h>
#include "my_strlenn.h"

size_t my_strlenn(const char* str) 
{
    size_t index = 0;

    while (str[index] != '\n') // need '\n'
        index++;
    
    return index;
}