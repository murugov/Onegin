#include <stdio.h>
#include "text_reader.h"
#include "print_verdict.h"

int main()
{
    FILE *input_file = fopen("files_txt/onegin.txt", "r");

    res_t result = text_reader(input_file);

    print_verdict(result);

    fclose(input_file);
    return 0;
}