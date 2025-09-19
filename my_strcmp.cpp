#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_strcmp.h"
#include "struct.h"

//int my_strcmp(struct strings* str1, struct strings* str2)

int my_strcmp(const void *a1, const void *a2)
{
    struct strings* str1 = (struct strings*)a1;
    struct strings* str2 = (struct strings*)a2;

    size_t i1 = 0, i2 = 0;
    
    while (i1 < str1->len && i2 < str2->len)
    {
        while (i1 < str1->len && !isalpha(str1->ptr[i1])) 
            i1++;

        while (i2 < str2->len && !isalpha(str2->ptr[i2]))
            i2++;
        
        if (i1 >= str1->len || i2 >= str2->len)
            break;
        
        char c1 = tolower(str1->ptr[i1]);
        char c2 = tolower(str2->ptr[i2]);
        
        if (c1 - c2)
            return c1 - c2;
        
        i1++;
        i2++;
    }
    

    while (i1 < str1->len && !isalpha(str1->ptr[i1]))
        i1++;

    while (i2 < str2->len && !isalpha(str2->ptr[i2]))
        i2++;
    
    if (i1 < str1->len && i2 >= str2->len)
        return 1;

    else if (i1 >= str1->len && i2 < str2->len)
        return -1;
    
    return 0;
}

//int my_rvs_strcmp(struct strings* str1, struct strings* str2)

int my_rvs_strcmp(const void *a1, const void *a2)
{
    struct strings* str1 = (struct strings*)a1;
    struct strings* str2 = (struct strings*)a2;

    size_t i1 = str1->len, i2 = str2->len;
    
    while (i1 > 0 && i2 > 0)
    {
        i1--;
        i2--;
        
        while (i1 > 0 && !isalpha(str1->ptr[i1]))
        {
            if (i1 == 0)
                break;

            i1--;
        }

        while (i2 > 0 && !isalpha(str2->ptr[i2]))
        {
            if (i2 == 0)
                break;
            
            i2--;
        }
        
        char c1 = tolower(str1->ptr[i1]);
        char c2 = tolower(str2->ptr[i2]);
        
        if (c1 - c2)
            return c1 - c2;
        
        if (i1 == 0 || i2 == 0)
            break;
    }

    
    while (i1 > 0 && !isalpha(str1->ptr[i1]))
    {
        if (i1 == 0)
            break;

        i1--;
    }
    
    while (i2 > 0 && !isalpha(str2->ptr[i2]))
    {
        if (i2 == 0)
            break;

        i2--;
    }
    
    if (i1 > 0 && i2 == 0)
        return 1;

    if (i1 == 0 && i2 > 0)
        return -1;
    
    return 0;
}