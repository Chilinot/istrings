#include "istring.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Define Macros
#define START(p) (p - sizeof(int))
#define STRING(p) (p + sizeof(int))

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
    
    return new_istring->string;
}

void istring_rm(char* str) {
    Istring istr = (Istring) START(str);
    free(istr);
}

char* istring_to_string(const char* str) {
    Istring istr = (Istring) START(str);
    
    char* new_str = malloc(sizeof(char) * istr->length);
    if(!new_str) {
        return NULL;
    }

    strcpy(new_str, str);
    
    return new_str;
}

size_t istrfixlen(char* str) {
    int length = 0;

    // This loop will continue until segfault or nonprintable has been found.
    for(int i = 0 ;; i++) {
        if(!isprint(str[i])) {
            str[i] = '\0'; // Place null-char and exit loop
            break;
        }
        ++length;
    }

    // Retrieve Istring-structure
    Istring istr = (Istring) START(str);
    
    // If length differs, reset it
    if(length != istr->length) {
        istr->length = length;
    }
    
    return (size_t) length;
}

size_t istrlen(const char* str) {
    Istring istr = (Istring) START(str);
    return (size_t) istr->length;
}

int main(void) {
    printf("%d\n",(int) istrlen(istring_mk("Tjenare")));
    return 0;
}
