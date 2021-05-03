### libft functions manual

#### 1. memset
-   `#include <string.h>`
-   `void *memset(void *b, int c, size_t len);`
- fill a byte string with a byte value
- writes Len bytes of value c(converted to an unsigned char) to the string b.
- len 만큼의 c로 b를 초기화한다.
- int 형 c를 인자로 받지만, 함수 안에서 unsigned char형으로 바뀌어 초기화된다.
- **returns** its first argument(= b)

#### 2. bzero
- `#include <stings.h>`
- `void bzero(void *s, size_t n);`
- write zeroes to a byte string
- writes n zeroed bytes to the string s. if n = 0, bzero() does nothing.
- **returns** nothing(void)

#### 3. memcpy
- `#include <string.h>`
- `void *memcpy(void *restrict dst, const void *restrict src, size_t n);`
- copy memory area
- copies n bytes from memory area src to memory area dst.
- if dst and src overlap, behavior is undefined.
- applications in which dst and src might overlap should use memmove instead.
- **returns** the original value of dst.

#### 4. memccpy
- `#include <string.h>`
- `void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);`
- copy string until character found
- copies bytes from string src to string dst.
- if the character c (as converted to an unsigned char) occurs in the string src,
  the copy stops and a pointer to the byte after the copy of c in the stirng dst
  is returned.
- otherwise, n bytes are copied, and a NULL pointer is returned.
- the source and destination strings should not overlap, as the behavior is undefined.

#### 5. memmove
- `#include <string.h>`
- `void *memmove(void *dst, const void *src, size_t len);`
- copy byte string
- copies len bytes from string src to string dst.
- the two strings may overlap; the copy is always done in a non-destructive manner.
- **returns** the original value of dst.

#### 6. memchr
- `#include <string.h>`
- `void *memchr(const void *s, int c, size_t n);`
- locate byte in byte string
- locates the first occurrence of c (converted to an unsigned char) in string s.
- **returns** a pointer to the byte located, or NULL if no byte exists within n bytes.

#### 7. memcmp
- `#include <string.h>`
- `int memcmp(const void *s1, const void *s2, size_t n);`
- compare byte string
- compares byte string s1 against byte string s2. both strings are assumed to be n bytes long.
- **returns** zero if the two strings are identical, otherwise **returns** the difference between
  the first two differing bytes. treated as unsigned char values, so that '200' is greater
  than '0', for example.
- zero-length strings are always identical.

#### 8. strlen
- `#include <string.h>`
- `size_t strlen(const char *s);`
- find length of string
- computes the length of the string s.
- **returns** the number of characters that precede the terminating NUL character.

#### 9. strlcpy & 10. strlcat
- `#include <string.h>`
- `size_t strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);`
- `size_t strlcat(char *restrict dst, const char *restrict src, size_t dstsize);`
- size-bounded string copying and concatenation
- copies and concatenates strings with the same input parameters and output result as
  snprintf.
- takes the full size of the destination buffer and guarantee NUL-termination if there is room.
- note that room for the NUL should be included in dstsize.
- **strlcpy** copies up to dstsize - 1 characters from the string src to dst,
    NUL-terminating the result if dstsize is not 0.
- **strlcat** appends string src to the end of dst.
    it will append at most dstsize - strlen(dst) - 1 characters.
    it will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than
    dstsize(it means that either dstsize is incorrect or that dst is not a proper string)
- **returns** the total length of the string they tried to createe.
-*- strlcpy **returns** the length of src
-*- strlcat **returns** the initial length of dst + the length of src.

#### 11. strchr
- `#include <string.h>`
- `char *strchr(const char *s, int c);`
- locate character in string
- locates the first occurrence of c (converted to a char) in the string pointed to by s.
- the terminating null character is considered to be part of the string.
- **returns** a pointer to the located character, or NULL if the character does not appear in the string.

#### 12. strrchr
- `#include <string.h>`
- `char *strrchr(const char *s, int c);`
- locate character in string
- identical to strchr(), except it locates the last occurrence of c.
- **returns** a pointer to the located character, or NULL if the character does not appear in the string.

#### 13. strnstr
- `#include <string.h>`
- `char *strnstr(const char *haystack, const char *needle, size_t len);`
- locates the first occurrence of the null-terminated string needle in the string haystack,
  where not more than len characters are searched.
- characters that appear after a '\0' character are not searched.
- **returns** haystack if needle is an empty string. NULL is returned if needle occurs nowhere in haystack.
  otherwise a pointer to the first character of the first occurrence of needle is returned.

#### 14.  strncmp
- `#include <string.h>`
- `int strncmp(const char *s1, const char *s2, size_t n);`
- compare strings.
- lexicographically compares the null-terminated strings s1 and s2 nor more than n characters.
  strncmp is designed for comparing strings rather than binary data, characters that appear after a '\0' character are not compared.
- **returns** an integer greater than, equal to, or less than 0 according as the string s1 is greater than, equal to, or less than the string s2.
- the comparision is done using unsigned char, so that '\200' is greater than '\0'.

#### 15.  atoi
- `#include <stdlib.h>`
- `int atoi(const char *str);`
- convert ASCII string to integer
- converts the initial portion of the string pointed to by str to int representation.
- **returns** converted int
- atoi() need affect the value of errno on an error

#### 16.  isalpha
- `#include <ctype.h>`
- `int isalpha(int c);`
- alphabetic character test
- tests for any character for which isupper or islower is true.
- the value of the argument must be representable as an unsigned char or the value of EOF.
- A to Z, a to z
- **returns** zero if the character tests false and returns non-zero if the character tests true.

#### 17.  isdigit
- `#include <ctype.h>`
- `int isdigit(int c);`
- decimal-digit character test
- tests for a decimal digit character. 0 to 9
- the value of the argument must be representable as an unsigned char or the value of EOF.
- **returns** zero if the character tests fales and return non-zero if the character tests true.

#### 18.  isalnum
- `#include <ctype.h>`
- `int isalnum(int c);`
- alphanumeric character test
- tests for any character for which isalpha or isdigit is true.
- the value of the argument must be representable as an unsigned char or the value of EOF.
- 0 to 9, A to Z, a to z
- **returns** zero if the character tests false and returns non-zero if the character tests true.


#### 19.  isascii
- `#include <ctype.h>`
- `int isascii(int c);`
- test for ASCII character
- tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.

#### 20.  isprint
- `#include <ctype.h>`
- `int isprint(int c);`
- printing character test(space character inclusive)
- tests for any printing character, including space (' ').
- the value of the argument must be representable as an unsigned char or the value of EOF.
- space to ~
- **returns** zero if the character tests false and returns non-zero if the character tests true.

#### 21.  toupper
- `#include <ctype.h>`
- `int toupper(int c);`
- lower case to upper case letter conversion
- converts a lower-case letter to the corresponding upper-case letter.
- the argument must be representable as an unsigned char or the value of EOF.
- **returns** the corresponding upper-case letter if the argument is a lower-case letter and if there is one. otherwise, the argument is returned unchanged.

#### 22.  tolower
- `#include <ctype.h>`
- `int tolower(int c);`
- upper case to lower case letter conversion
- converts an upper-case letter to the corresponding lower-case letter.
- the argument must be representable as an unsigned char or the value of EOF.
- **returns** the corresponding lower-case letter if the argument is a upper-case letter and if there is one. otherwise, the argument is returned unchanged.

#### 23.  calloc
- `#include <stdlib.h>`
- `void *calloc(size_t count, size_t size);`
- memory allocation
- contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.
- the allocated memory is aligned on a page boundary.
- **returns** a pointer to allocated memory if successful. if there's an error, returns a NULL pointer and set errno to ENOMEM.

#### 24.  strdup
- `#include <string.h>`
- `char *strdup(const char *s1);`
- save a copy of a string
- allocates sufficient memory for a copy of the string *s1, does the copy, and **returns** a pointer to it.
- the pointer may subsequently be used as an argument to the function free().
- if insufficient memory is available, NULL is returned and errno is set to ENOMEM.
