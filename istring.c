#include "istring.h"
#include <stdlib.h>
#include <stdio.h>

// Define macros
#define START(p)  p - ((int)sizeof(int))
#define STRING(p) p + ((int)sizeof(int))

// istring structure
typedef struct _istring {
    int length;
    char** str;
} *istring;


char* istring_mk(const char* str) {
    istring new_istr = malloc(sizeof(struct _istring));
    
    //Out of memory, or argument is null.
    if(new_istr == NULL || str == NULL) {
        return NULL;
    }

    //Copy data to struct
    new_istr->length = strlen(str);
    
    *new_istr->str = malloc(sizeof(char) * (new_istr->length + 1));
    strcpy(*new_istr->str, str);

    //Return pointer to string in istring
    return *((char**) STRING(new_istr));
}

void istring_rm(char* str) {
    istring istr = (istring) START(str);

    free(istr->str);
    free(istr);
    
    return;
}

int main(void) {

    printf("%d", START(4));
    printf("%d", STRING(4));

    char* tjenare = istring_mk("YOLO");
    puts(tjenare == NULL ? "YUP" : "NOPE");
    
    puts(tjenare);

    istring_rm(tjenare);

    return 0;
}
