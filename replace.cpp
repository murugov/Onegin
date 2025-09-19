#include <stdio.h>
#include <string.h>

void replace_n_to_0(char* buffer, size_t count_n)
{
    char* str = buffer;

    while ((str = strchr(str, '\0')) != NULL && count_n > 0)
    {
        *str = '\n';
        count_n--;

        str++;
    }
}