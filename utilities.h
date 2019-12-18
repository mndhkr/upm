
#include "types.h"



struct options {
    char verbose:1;
    char quiet:1;
};

typedef struct options Options;

string merge(char** argv, int from, int argc);

Options get_options(char** argv, int argc);