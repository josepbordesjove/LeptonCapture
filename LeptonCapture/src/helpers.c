#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

void pabort(const char *s) {
    perror(s);
    abort();
}