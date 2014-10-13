#include "istring.h"
#include "istring_rep.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char* istring_mk(const char* str) {
    if(str == NULL) {
        return NULL;
    }

    // Allocate memory
    int str_length = strlen(str);
    Istring new_istring = malloc(sizeof(_istring) + (sizeof(char) * (str_length + 1)));
    
    // Out of memory?
    if(new_istring == NULL) {
        return NULL;
    }

    // Store values
    new_istring->length = str_length;
    strcpy(new_istring->string, str);
    
    return new_istring->string;
}

void istring_rm(char* str) {
    if(str != NULL) {
        Istring istr = START(str);
        free(istr);
    }
}

char* istring_to_string(const char* str) {
    Istring istr = START(str);
    
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
    Istring istr = START(str);
    
    // If length differs, reset it
    if(length != istr->length) {
        istr->length = length;
    }
    
    return (size_t) length;
}

char* istrslen(char *s, size_t length) {
    Istring istr = START(s);

    if(istr->length >= (int) length) {
        s[length] = '\0';
        istr->length = length;
        return s;
    }
    else {
        // Create new char-array with the length argument as size
        char new_str[length];
        
        // Copy the old string to the new char-array
        strcpy((char*) &new_str, istr->string);

        // Retrieve the last char in the old string
        char last_char = istr->string[(istr->length) - 1];

        // Compute length difference
        int delta = length - istr->length;
        
        // Insert the last char until delta is zero
        while(delta) {
            new_str[length - delta--] = last_char;
        }

        // Release memory of old istring
        istring_rm(s);
        
        // Make sure the new string is correctly terminated
        new_str[length] = '\0';

        // Return a new istring instance with the new string
        return istring_mk(new_str);
    }
}

size_t istrlen(const char* str) {
    Istring istr = START(str);
    return (size_t) istr->length;
}

char* istrchr(const char *s, int c) {
    for(int i = 0; i <= (int) istrlen(s); i++){
        if (s[i] == c) {
            return (char*) s + i; 
        }
    } 
    return NULL;
}

char *istrrchr(const char *s, int c) {
    return NULL;
}

int istrcmp(const char *s1, const char *s2) {
    return 0;
}

int istrncmp(const char *s1, const char *s2, size_t n) {
    return 0;
}

char *istrcpy(char *dst, const char *src) {
    return NULL;
}

char *istrncpy(char *dst, const char *src, size_t n) {
    return NULL;
}

char *istrcat(char *dst, const char *src) {
    return NULL;
}

char *istrncat(char *dst, const char *src, size_t n) {
    return NULL;
}

/* int main(void) { */
/*     char* istr = istring_mk("Tjenare"); */

/*     printf("%d\n",(int) istrlen(istr)); */
/*     istrslen(istr, 5); */

/*     printf("%d\n",(int) istrlen(istr)); */
/*     puts(istr); */

/*     istr = istrslen(istr, 10); */
/*     puts(istr); */
/*     printf("%d\n", (int) istrlen(istr)); */
    
/*     char* test = istrchr(istr, 'j'); */
/*     if (test != NULL){ */
/*       printf("The character %c is in istr\n", test); */
/*     } */

/*     istring_rm(istr); */

/*     return 0; */
/* } */
