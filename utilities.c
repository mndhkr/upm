#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "utilities.h"

#define stddeb stderr

string merge(char** argv, int from, int argc)
{

    //TODO: check for --switches or -s
    char* merged = (char*)calloc(5000, sizeof(char));

    for(int i = from; i < argc; i ++) {
        if(argv[i][0] != '-')
            sprintf(merged, "%s %s", merged, argv[i]);
    }

    fprintf(stddeb, "Debug info: utilities.c - merge: %s", merged);
    fputc('\n', stddeb);
    fflush(stddeb);
    return merged;
}

Options set_options(char** argv, int argc) {

    Options options;

    options.quiet = 0;
    options.verbose = 0;

    for(int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--quiet") == 0 || strcmp(argv[i], "-q") == 0) {
            options.quiet = 1;
        } else if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
            options.verbose = 1;
        }
    }
}