#include <stdio.h>
#include "print_verdict.h"
#include "colors.h"

void print_verdict(res_t result)
{
    switch (result)
    {
        case OPEN_FAIL:
            perror(ANSI_COLOR_RED "Error opening input file!\n" ANSI_COLOR_RESET);
            break;
        case OUT_FAIL:
            perror(ANSI_COLOR_RED "Error creating output file!\n" ANSI_COLOR_RESET);
            break;
        case FILE_INFO_FAIL:
            perror(ANSI_COLOR_RED "Error getting file information!\n" ANSI_COLOR_RESET);
            break;
        case SUCCESS:
            printf(ANSI_COLOR_GREEN "SUCSESS\n" ANSI_COLOR_RESET);
            break;
        default:
            break;
    }
}