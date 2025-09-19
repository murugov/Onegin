#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "text_writer.h"
#include "struct.h"
#include "number_str.h"
#include "buf_to_struct.h"
#include "find_size_file.h"

res_t text_reader(FILE* stream)
{
    if (stream == NULL)
        return OPEN_FAIL;

    ssize_t file_size = find_size_file(stream);
    
    if (file_size < 0)
        return FILE_INFO_FAIL;

    char* buffer = (char*)calloc((size_t)file_size + 2, sizeof(char));

    size_t capacity = fread(buffer, sizeof(char), (size_t)file_size, stream);
    buffer[capacity] =  '\n';

    size_t count_n = number_str(buffer);

    struct strings* text = (struct strings*)calloc(count_n, sizeof(char*));
    buf_to_struct(text, buffer, capacity);

    res_t write_verdict = text_writer(text, buffer, &count_n);

    free(buffer);
    free(text);

    return write_verdict;
}