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
    size_t str_length = strlen(str);
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
    size_t length = 0;

    // This loop will continue until segfault or non printable has been found.
    // this loop counts the length and copies it at the same time.
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
        istr->length = (int) length;
    }
    
    return length;
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
        int delta = (int) (length - istr->length);
        
        // Insert the last char until delta is zero
        while(delta > 0) {
            new_str[length - delta--] = last_char;
        }
        
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
    char* found = NULL;
    for(int i = 0; i <= (int) istrlen(s); i++){
        if (s[i] == c) {
            found = (char*) s + i;
        }
    } 
    return found;
}

int istrcmp(const char *s1, const char *s2) {
    size_t s1_len = istrlen(s1);
    size_t s2_len = istrlen(s2);

    if(s1_len > s2_len) {
        return 1;
    }
    else if(s1_len < s2_len) {
        return -1;
    }
    else {
        return istrncmp(s1, s2, s1_len);
    }
}

int istrncmp(const char *s1, const char *s2, size_t n) {
    for(int i = 0; i < (int) n; i++) {
        if(s1[i] == '\0' && s2[i] == '\0') return 0;
        if(s1[i] == '\0') return -1;
        if(s2[i] == '\0') return 1;
        if(s1[i] < s2[i]) return -1;
        if(s1[i] > s2[i]) return 1;
    }
    return 0;
}

char *istrcpy(char *dst, const char *src) {
    Istring istr = (Istring) dst;

    size_t length = 0;
    for(; src[length] != '\0'; length++) {
        istr->string[length] = src[length];
    }

    // Terminate the string.
    istr->string[length] = '\0';

    // Store length
    istr->length = length;

    return STRING(dst);
}

char *istrncpy(char *dst, const char *src, size_t n) {
    Istring istr = (Istring) dst;

    for(int i = 0; i < n; i++) {
        istr->string[i] = src[i];
    }

    istr->length = n;

    return STRING(dst);
}

char *istrcat(char *dst, const char *src) {
    size_t dst_length = strlen(dst);
    size_t src_length = strlen(src);

    // Copy the original string in dst to our buffer
    // so we won't overwrite the dst string when we
    // "convert" it to an Istring.
    char buffer[dst_length];
    strcpy(buffer, dst);

    Istring istr = (Istring) dst;

    istr->length = dst_length + src_length;
    istr->string = strcat(buffer, src);

    return STRING(dst);
}

char *istrncat(char *dst, const char *src, size_t n) {
    return NULL;
}
