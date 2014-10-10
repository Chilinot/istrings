#ifndef ISTRING_REP_H
#define ISTRING_REP_H

typedef struct _istring {
    int length;
    char string[];
} _istring, *Istring;

#endif
