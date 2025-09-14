#include <stdio.h>
#include "my_strlenn.h"
#include "my_strcmp.h"

int my_strcmp(const char* str1, const char* str2)
{
    for (size_t i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
    {
        if (str1[i] - str2[i])
            return str1[i] - str2[i];
    }

    size_t len1 = my_strlenn(str1);
    size_t len2 = my_strlenn(str2);

    if (len1 > len2)
        return 1;
    
    if (len1 < len2)
        return -1;

    return 0;
}