#include <stdio.h>
#include <string.h>
#include "struct.h"

void buf_to_struct(struct strings* text, char* buffer, size_t capacity)
{    
    size_t index = 0;
    char* str = buffer;
    char* flag_second_n = buffer - 1;

    while ((str = strchr(str, '\n')) != NULL)
    {
        if (flag_second_n + 1 == str)
            flag_second_n++;
        else
        {
            *str = '\0';
            text[index].ptr = flag_second_n + 1;
            text[index - 1].len = (size_t)(text[index].ptr) - (size_t)(text[index - 1].ptr);
            flag_second_n = str;
            index++;
        }

        str++;
    }
    
    text[index - 1].len = (size_t)(&buffer[capacity - 1]) - (size_t)(text[index - 1].ptr);
}