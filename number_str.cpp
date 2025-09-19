#include <stdio.h>
#include <string.h>

size_t number_str(char* buffer)
{
    size_t count_n = 0;
    char* str = buffer;
    char* flag_second_n = NULL;

    while ((str = strchr(str, '\n')) != NULL)
    {
        if (flag_second_n + 1 == str)
            flag_second_n++;
        else
        {
            count_n++;
            flag_second_n = str;
        }

        str++;
    }

    return count_n;
}