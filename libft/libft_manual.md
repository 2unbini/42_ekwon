1. memset\
- fill a byte string with a byte value\
- #include <string.h>\
- void *memset(void *b, int c, size_t len);\
- writes Len bytes of value c(converted to an unsigned char) to the string b.\
- returns its first argument.
\fs20 \

\fs30 \
2. bzero\
- write zeroes to a byte string\
- #include <stings.h>\
- void bzero(void *s, size_t n);\
- writes n zeroed bytes to the string s. if n = 0, bzero() does nothing.\
- returns nothing(void)\
\
3. memcpy\
- copy memory area\
- #include <string.h>\
- void *memcpy(void *restrict dst, const void *restrict src, size_t n);\
- copies n bytes from memory area src to memory area dst.\
- if dst and src overlap, behavior is undefined.\
- applications in which dst and src might overlap should use memmove instead.\
- returns the original value of dst.\
\
4. memccpy\
- copy string until character found\
- #include <string.h>\
- void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);\
- copies bytes from string src to string dst.\
- if the character c (as converted to an unsigned char) occurs in the string src,\
  the copy stops and a pointer to the byte after the copy of c in the stirng dst\
  is returned.\
- otherwise, n bytes are copied, and a NULL pointer is returned.\
- the source and destination strings should not overlap, as the behavior is undefined.\
\
5. memmove\
- copy byte string\
- #include <string.h>\
- void *memmove(void *dst, const void *src, size_t len);\
- copies len bytes from string src to string dst.\
- the two strings may overlap; the copy is always done in a non-destructive manner.\
- returns the original value of dst.\
\
6. memchr\
- locate byte in byte string\
- #include <string.h>\
- void *memchr(const void *s, int c, size_t n);\
- locates the first occurrence of c (converted to an unsigned char) in string s.\
- returns a pointer to the byte located, or NULL if no byte exists within n bytes.\
\
7. memcmp\
- compare byte string\
- #include <string.h>\
- int memcmp(const void *s1, const void *s2, size_t n);\
- compares byte string s1 against byte string s2. both strings are assumed to be n bytes long.\
- returns zero if the two strings are identical, otherwise returns the difference between\
  the first two differing bytes. treated as unsigned char values, so that '\\200' is greater\
  than '\\0', for example.\
- zero-length strings are always identical.\
\
8. strlen\
- find length of string\
- #include <string.h>\
- size_t strlen(const char *s);\
- computes the length of the string s.\
- returns the number of characters that precede the terminating NUL character.\
\
9. strlcpy & 10. strlcat\
- size-bounded string copying and concatenation\
- #include <string.h>\
- size_t strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);\
- copies and concatenates strings with the same input parameters and output result as\
  snprintf.\
- takes the full size of the destination buffer and guarantee NUL-termination if there is room.\
- note that room for the NUL should be included in dstsize.\
-*- strlcpy copies up to dstsize - 1 characters from the string src to dst,\
    NUL-terminating the result if dstsize is not 0.\
-*- strlcat appends string src to the end of dst.\
    it will append at most dstsize - strlen(dst) - 1 characters.\
    it will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than\
    dstsize(it means that either dstsize is incorrect or that dst is not a proper string)\
- returns the total length of the string they tried to create.\
-*- strlcpy returns the length of src\
-*- strlcat returns the initial length of dst + the length of src.\
\
11. strchr\
- locate character in string\
- #include <string.h>\
- char *strchr(const char *s, int c);\
- locates the first occurrence of c (converted to a char) in the string pointed to by s.\
- the terminating null character is considered to be part of the string.\
\
12. strrchr\
\
13. strnstr\
\
14. strncmp\
\
15. atoi\
\
16. isalpha\
\
17. isdigit\
\
18. isalnum\
\
19. isascii\
\
20. isprint\
\
21. toupper\
\
22. tolower\
\
23. calloc\
\
24. strdup\
\
}