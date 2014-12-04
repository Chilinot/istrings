#ifndef ISTRING_REP_H
#define ISTRING_REP_H

// Istring structure
typedef struct _istring {
    size_t length;
    char string[];
} _istring, *Istring;

// Macros
#define START(p) ((Istring) (p - sizeof(int)))
#define STRING(p) ((char*) (p + sizeof(int)))

#endif
