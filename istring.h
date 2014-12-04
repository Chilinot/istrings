#ifndef ISTRING_H
#define ISTRING_H

#include <string.h>

/**
 * Returns a new istring instance created from supplied
 * string. Returns NULL if out of memory. Returns NULL string if
 * argument str is NULL. 
 *
 * @param str String to create istring from. 
 * @return The newly created istring. 
 */
char *istring_mk(const char* str);

/**
 * Deallocates an istring.
 *
 * @param str Istring to be deallocated.
 */
void istring_rm(char *str);

/**
 * Returns a standard null terminated char* representation of the
 * supplied istring. Returns NULL if out of memory.
 *
 * @param str Istring to create string from. 
 * @return The created string.
 */
char *istring_to_string(const char *str);

/**
 * Inspects the length of the string from str and if it differs from
 * length, updates length accordingly. If str does not contain a \0
 * token, it will be inserted at the first element which is not a
 * printable ascii character, and length updated accordingly. This
 * function must be as efficient as possible and not rescan the string
 * if it can be avoided.
 *
 * This function is useful when istrings have been manipulated as
 * regular C strings, to reestablish the length invariant.
 * @param s The istring.
 * @return The size of istring.
 */
size_t istrfixlen(char *s);

/**
 * Sets the length of an istring and inserts a corresponding '\0'
 * character. If the length argument is out of bounds for the string,
 * a new istring should be returned with the contents of the original
 * string. The last character of the original string will be repeated
 * to fill the string to its given length.
 *
 * @param s Istring to set length on.
 * @return The istring with altered length.
 */
char* istrslen(char *s, size_t length);

/**
 * Returns a pointer to the first occurrence of c in string s, if c
 * doesn't exist in s, return NULL;
 *
 * @param s Istring to search.
 * @param c char to search for.
 * @return Address of first occurrence of c in s.
 */
char *istrchr(const char *s, int c);

/**
 * See istrchr. Return the last occurrence instead.
 *
 * @param s Istring to search.
 * @param c Char to search for.
 * @return Address of last occurrence of c in s.
 */
char *istrrchr(const char *s, int c);

/**
 * Compares two istrings.
 *
 * @param s1 Istring to compare.
 * @param s2 Istring to compare.
 * @return 0 if istrings are equal. >0 if s1 is greater then s2 and vice versa.
 */
int istrcmp(const char *s1, const char *s2);

/**
 * See istrcmp. Only compares the n first characters.
 *
 * @param s1 Istring to compare.
 * @param s2 Istring to compare.
 * @return 0 if istrings are equal. >0 if s1 is greater then s2 and vice versa.
 */
int istrncmp(const char *s1, const char *s2, size_t n);

/**
 * Length of istring.
 *
 * @param s The istring to determine length of.
 * @return Length of istring.
 */
size_t istrlen(const char *s);

/**
 * Copies a src string to dst and makes dst an istring.
 * Creates a new Istring instance at dst.
 *
 * NOTE: dst must be large enough to fit an istring representation of src.
 * If this is not the case then program execution can not be predicted!
 *
 * @param dst Address to copy to.
 * @param src String to copy.
 * @return Pointer to the copied string.
 */
char *istrcpy(char *dst, const char *src);

/**
 * See istrcpy. Only copies the n first characters.
 * Creates a new Istring instance at dst.
 *
 * @param dst Address to copy to.
 * @param src String to copy.
 * @param n The amount of characters to copy.
 * @return Pointer to the copied string.
 */
char *istrncpy(char *dst, const char *src, size_t n);

/**
 * Concatenates src to the end of dst, overwriting the '\0' at the end of dst.
 * Creates a new Istring instance at dst.
 *
 * NOTE: dst must be large enough to fit an istring representation of dst + src.
 * If this is not the case then program execution can not be predicted!
 *
 *@param dst String to add src to.
 *@param src String to add to dst.
 *@return Pointer to the concatenated string.
 */
char *istrcat(char *dst, const char *src);

/**
 * See istrcat. Only appends the n first characters of dst.
 * Creates a new Istring instance at dst.
 *
 * @param dst String to add src to.
 * @param src String to add to dst.
 * @return Pointer to the concatenated string.
 */
char *istrncat(char *dst, const char *src, size_t n);

#endif

