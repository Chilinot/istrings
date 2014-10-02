#include "istring.h"
#include <stdlib.h>
#include <stdio.h>

//Define Macros
#define START(p)  p - ((int) sizeof(int))
#define STRING(p) p + ((int) sizeof(int))

typedef struct _istring {
    int length;
    char str[];
} *istring;

int main(void) {
    return 0;
}
