#include <stdio.h>
#include <stdlib.h>
#include "shsort.h"
#include "my_strcmp.h"
#include "struct.h"
#include "replace.h"

void text_writer(struct strings* text, char* buffer, size_t* count_n)
{
    FILE *output_file = fopen("files_txt/out.txt", "w");
    
    if (output_file == NULL)
    {
        perror("Ошибка создания выходного файла!\n");
        return;
    } 
    else
    {
        //qsort(text, *count_n, sizeof(strings), my_strcmp);

        shsort(text, count_n, my_strcmp);

        for(size_t i = 0; i < *count_n; ++i)
            fprintf(output_file, "%s\n", text[i].ptr);
        
        fprintf(output_file, "-----------------------------------------------------------------------------------------------------------------------------\n");


        shsort(text, count_n, my_rvs_strcmp);

        for(size_t i = 0; i < *count_n; ++i)
            fprintf(output_file, "%s\n", text[i].ptr);

        fprintf(output_file, "-----------------------------------------------------------------------------------------------------------------------------\n");
        
        replace_n_to_0(buffer, *count_n);

        fputs(buffer, output_file);
    }
    
    fclose(output_file);
}