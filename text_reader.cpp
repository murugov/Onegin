#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "shsort.h"

void text_reader()
{
    FILE *input_file = fopen("files_txt/text.txt", "r"); //assert на адресс

    if (input_file == NULL)
    {
        printf("Ошибка открытия входного файла!\n"); //perror
        exit(1);
    }

    struct stat file_info;

    size_t capacity = file_info.st_size;

    char* buffer = (char*)calloc(capacity, sizeof(char));
    const char** arr_ptr = (const char**)calloc(capacity, sizeof(char*));

    fread(buffer, sizeof(char), capacity, input_file);

    size_t counter = 1;
    arr_ptr[0] = buffer;
    
    for (size_t i = 0; i < capacity - 1; ++i)
    {
        if (buffer[i] == '\n' && buffer[i + 1] != '\n')
        {
            arr_ptr[counter] = &(buffer[i + 1]);
            buffer[i] = '\0';
            counter++;
        }
        else if (buffer[i] == '\n')
            buffer[i] = '\0';
    }

    shsort(arr_ptr, counter);

    // for(int i = 0; i < counter; ++i)
    //     printf("%s\n", arr_ptr[i]);

    FILE *output_file = fopen("files_txt/out.txt", "w"); //assert на адресс
    
    if (output_file == NULL)
    {
        printf("Ошибка создания выходного файла!\n"); //perror
        exit(1);
    } 
    else
    {
        for(size_t i = 0; i < counter; ++i)
            fprintf(output_file, "%s\n", arr_ptr[i]);
    }


    fclose(input_file);
    fclose(output_file);
    free(buffer);
    free(arr_ptr);
}

int main()
{
    text_reader();

    return 0;
}