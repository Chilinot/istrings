#include "istring.h"
#include <stdlib.h>
#include <stdio.h>

//Define Macros
#define START(p)  p - sizeof(int)
#define STRING(p) p + sizeof(int)

typedef struct _istring {
    int length;
    char string[];
} _istring, *Istring;

char* istring_mk(const char* str) {
    if(!str) {
        return NULL;
    }

    // Allocate memory
    int str_length = strlen(str);
    Istring new_istring = malloc(sizeof(_istring) + (sizeof(char) * (str_length + 1)));
    
    // Out of memory?
    if(!new_istring) {
        return NULL;
    }

    // Store values
    new_istring->length = str_length;
    strcpy(new_istring->string, str);
    
    return (char*) STRING(new_istring);
}

int foo(char* str) {
    int* yo = (int*) START(str);
    return *yo;
}

int main(void) {
    char* istr = istring_mk("Tjenare");
    puts(istr);

    int len = foo(istr);
    printf("%d\n", len);

    return 0;
}
