#ifndef ISTRING_REP_H
#define ISTRING_REP_H

// Istring structure
typedef struct _istring {
    size_t length;
    char string[];
} _istring, *Istring;

// Macros
#define START(p) ((Istring) (p - sizeof(size_t)))
#define STRING(p) ((char*) (p + sizeof(size_t)))

#endif
