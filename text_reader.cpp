#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "text_writer.h"
#include "struct.h"
#include "number_str.h"
#include "buf_to_struct.h"

void text_reader(FILE* stream)
{
    if (stream == NULL)
    {
        perror("Ошибка открытия входного файла!\n");
        return;
    }
    
    struct stat file_info = {};

    if (fstat(fileno(stream), &file_info) != 0)
    {
        perror("Ошибка получения информации о файле!\n");
        fclose(stream);
        return;
    }

    char* buffer = (char*)calloc((size_t)file_info.st_size + 1, sizeof(char));

    size_t capacity = fread(buffer, sizeof(char), (size_t)file_info.st_size, stream);
    size_t count_n = number_str(buffer);

    struct strings* text = (struct strings*)calloc(count_n, sizeof(char*));
    buf_to_struct(text, buffer, capacity);

    text_writer(text, buffer, &count_n);

    fclose(stream);
    free(buffer);
    free(text);
}