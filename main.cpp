#include <stdio.h>
#include "text_reader.h"

int main()
{
    FILE *input_file = fopen("files_txt/text.txt", "r");

    text_reader(input_file);

    return 0;
}