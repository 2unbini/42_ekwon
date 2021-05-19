### libft functions manual

#### 1. memset
-   `#include <string.h>`
-   `void *memset(void *b, int c, size_t len);`
- fill a byte string with a byte value
- writes Len bytes of value c(converted to an unsigned char) to the string b.
- **returns** its first argument(= b)
- len 만큼의 c로 b를 초기화한다. 즉, 메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수.
- int 형 c를 인자로 받지만, 함수 안에서 1 바이트 크기의 unsigned char형으로 바뀌어 초기화된다.
- 주로 설정할 값을 0으로 지정하여 메모리의 내용을 모두 0으로 만들 때 사용한다.
- 성공시 첫 번째 인자로 들어간 b에 대한 포인터를 반환, 실패시 NULL 반환.

#### 2. bzero
- `#include <stings.h>`
- `void bzero(void *s, size_t n);`
- write zeroes to a byte string
- writes n zeroed bytes to the string s. if n = 0, bzero() does nothing.
- n 만큼의 0으로 s를 초기화한다. 즉, 메모리의 내용을 원하는 크기만큼 0으로 세팅할 수 있는 함수.
- memset 함수와 기능은 동일하지만, 특정 값을 세팅할 수 있는 memset함수와 달리 bzero는 0(0x00)으로 세팅해야 한다.
- n 의 값이 0이면, bzero 함수는 아무 동작도 하지 않으며, 함수의 반환형이 void이므로, 반환값이 없다.

#### 3. memcpy
- `#include <string.h>`
- `void *memcpy(void *restrict dst, const void *restrict src, size_t n);`
- copy memory area
- copies n bytes from memory area src to memory area dst.
- if dst and src overlap, behavior is undefined.
- applications in which dst and src might overlap should use memmove instead.
- **returns** the original value of dst.
- src 에서 n 바이트 만큼을 dst 로 복사한다.
- 오버플로우 문제를 방지하기 위해 dst와 src가 가리키는 배열의 크기는 반드시 n 바이트 이상이어야 하며, 서로 겹치면 안 된다. 복사 할 메모리와 결괏값을 붙여 넣을 메모리가 겹쳐져 있으면 함수가 제대로 작동하지 않는다. 덮어씌우기 위해선 (덮어씌워진다면) memmove 함수를 사용하자.
- 이 함수는 src의 널 종료 문자를 검사하지 않고, 정확히 n 만큼만 복사한다.
- dst를 반환한다.
- cf) restrict 포인터는 컴파일러에게 최적화를 하라고 알려주는 키워드(메모리가 다른 공간을 가리킨다고 보장하거나 메모리 공간을 검사하는 용도가 아님)

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
- src 에서 n 바이트 만큼을 dst 로 복사할 때, src 에서 문자 c 를 만나면 복사가 끝난 데이터의 다음 메모리 번지를 리턴한다. 즉, dst + 복사된 바이트 수 를 반환한다.
- c 문자를 만나지 않았다면, n 바이트 만큼을 복사하고 NULL 포인터를 리턴한다.
- memcpy와 마찬가지로 src와 dst는 덮어씌워지면 안 된다.

#### 5. memmove
- `#include <string.h>`
- `void *memmove(void *dst, const void *src, size_t len);`
- copy byte string
- copies len bytes from string src to string dst.
- the two strings may overlap; the copy is always done in a non-destructive manner.
- **returns** the original value of dst.
- src 문자열부터 len 바이트 만큼을 dst 문자열에 복사한다.
- 두 문자열은 중첩될 수 있다 수 => 메모리 복사 수행시, 이동할 데이터를 임시 버퍼에 옮긴 후 대상 버퍼로 옮기므로 중첩 현상이 발생하지 않는다.
- 이 함수는 src의 널 종료 문자를 검사하지 않고, 정확히 n 만큼만 복사한다.
- dst를 반환한다.

#### 6. memchr
- `#include <string.h>`
- `void *memchr(const void *s, int c, size_t n);`
- locate byte in byte string
- locates the first occurrence of c (converted to an unsigned char) in string s.
- **returns** a pointer to the byte located, or NULL if no byte exists within n bytes.
- s 문자열에서 처음 c 와 일치하는 값의 주소를 리턴한다. n 바이트 내에 c 가 발견되지 않으면 NULL 을 리턴한다.
- c 는 int 로 값이 전달되지만, 함수 내부적으로는 한 바이트씩 비교하기 때문에 unsigned char로 변환되어 사용된다.

#### 7. memcmp
- `#include <string.h>`
- `int memcmp(const void *s1, const void *s2, size_t n);`
- compare byte string
- compares byte string s1 against byte string s2. both strings are assumed to be n bytes long.
- **returns** zero if the two strings are identical, otherwise **returns** the difference between
  the first two differing bytes. treated as unsigned char values, so that '\200' is greater
  than '\0', for example.
- zero-length strings are always identical.
- n 바이트 만큼의 문자열 s1 와 s2 를 비교한다.
- 두 문자열이 같다면 0을 리턴하고 다르면 두 다른 바이트의 차이를 리턴한다. 이 때, 두 다른 바이트는 unsigned char 형으로 비교되며, s1 이 더 크면 0보다 큰 값을, s2 이 더 크면 0보다 작은 값을 리턴한다.
- 길이가 0인 문자열들은 항상 동일하다.

#### 8. strlen
- `#include <string.h>`
- `size_t strlen(const char *s);`
- find length of string
- computes the length of the string s.
- **returns** the number of characters that precede the terminating NUL character.
- 문자열 s의 길이를 계산한다. 널 문자 앞 문자까지의 개수를 리턴한다.

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
- **returns** the total length of the string they tried to create.
- **strlcpy returns** the length of src
- **strlcat returns** the initial length of dst + the length of src.
- 문자열을 복사하고 연결시키는 함수이며, 이 결괏값은 snprintf함수와 같다.
- 문자열을 복사/연결시킬 목적지 버퍼의 전체 크기를 차지하고 공간이 남아 있는 경우, 널 문자로 종료되는 것을 보장한다.
- dstsize 에 널 문자가 포함돼야 한다.
- **strlcpy** 는 dstsize 가 0이 아닐 때 src 부터 dstsize - 1 만큼을 dst 에 복사하고, 널 문자로 종료한다.
- **strlcat** 는 dst의 끝에 src를 붙인다.
  최대 dstsize - strlen(dst) - 1 만큼의 문자열이 붙여진다.
  dstsize가 0이 아니거나 dst 문자열의 길이가 dstsize 보다 길지 않을 때 널 문자로 종료한다. (dstsize가 부정확하거나 dst 가 적절한 문자열이 아닌 상황을 의미)
- 함수가 만드려고 시도한 총 문자열의 길이를 반환한다.
- **strlcpy** src 의 길이를 반환한다.
- **strlcat** dst 의 초기 길이 + src 의 길이를 반환한다.

#### 11. strchr
- `#include <string.h>`
- `char *strchr(const char *s, int c);`
- locate character in string
- locates the first occurrence of c (converted to a char) in the string pointed to by s.
- the terminating null character is considered to be part of the string.
- **returns** a pointer to the located character, or NULL if the character does not appear in the string.
- s 가 가리키고 있는 문자열에서 가장 처음 c(int 형으로 입력받지만 char 형으로 변환된다) 가 나오는 위치를 찾는다.
- 문자열 끝의 널 문자는 문자열의 일부로 여겨진다. => 이 함수는 문자열의 맨 끝 부분을 가리키는 포인터를 얻기 위해서 사용되기도 한다.
- c 가 발견되면 그 발견된 첫 번째 위치를 가리키는 포인터를, c 가 문자열에서 발견되지 않으면 NULL 을 반환한다.

#### 12. strrchr
- `#include <string.h>`
- `char *strrchr(const char *s, int c);`
- locate character in string
- identical to strchr(), except it locates the last occurrence of c.
- **returns** a pointer to the located character, or NULL if the character does not appear in the string.
- strchr 과 동일하지만, 가장 마지막으로 c가 발견되는 위치를 찾는다.
- 마찬가지로 문자열 맨 끝 널 문자는 문자열의 일부로 여겨진다.
- c 가 발견되면 그 발견된 마지막 위치를 가리키는 포인터를, 아니라면 NULL 을 반환한다.

#### 13. strnstr
- `#include <string.h>`
- `char *strnstr(const char *haystack, const char *needle, size_t len);`
- locates the first occurrence of the null-terminated string needle in the string haystack,
  where not more than len characters are searched.
- characters that appear after a '\0' character are not searched.
- **returns** haystack if needle is an empty string. NULL is returned if needle occurs nowhere in haystack.
  otherwise a pointer to the first character of the first occurrence of needle is returned.
- len 만큼을 탐색하는 동안 널로 끝나는 문자열 needle 이 haystack 에서 발견되는 첫 위치를 찾는다.
- 널 문자 뒤에 나오는 문자는 검색하지 않는다. 즉, 널 문자를 만나면 더이상 찾지 않는다.
- needle 이 비어있을 경우, haystack 을 리턴한다. needle 이 비어있지 않지만 haystack 에서 발견되지 않는 경우 NULL 을 리턴한다. 두 가지 경우가 모두 아니라면, needle 문자열이 발견된 첫 번째 문자열의 첫 글자를 가리키는 포인터를 반환한다.

#### 14.  strncmp
- `#include <string.h>`
- `int strncmp(const char *s1, const char *s2, size_t n);`
- compare strings.
- lexicographically compares the null-terminated strings s1 and s2 not more than n characters.
  strncmp is designed for comparing strings rather than binary data, characters that appear after a '\0' character are not compared.
- **returns** an integer greater than, equal to, or less than 0 according as the string s1 is greater than, equal to, or less than the string s2.
- the comparision is done using unsigned char, so that '\200' is greater than '\0'.
- 널로 끝나는 문자열 s1 과 s2 를 사전 편찬 순서대로 n 문자 만큼 비교한다.
  이진 데이터를 비교하는 대신 문자열을 비교하는 함수로 설계돼있으므로 널 문자 뒤에 오는 문자는 비교되지 않는다. 즉, 널 문자를 만나면 더 이상 비교하지 않는다.
- s1 와 s2 의 대소관계에 따라 각 0보다 큰, 같은, 0보다 작은 값을 반환한다.
- n < 0 이면, 언더플로우가 일어나 문자열 끝까지 탐색한다.

#### 15.  atoi
- `#include <stdlib.h>`
- `int atoi(const char *str);`
- convert ASCII string to integer
- converts the initial portion of the string pointed to by str to int representation.
- **returns** converted int
- atoi() need affect the value of errno on an error
- ASCII 문자열을 정수로 변환한다.
- str 이 가리키고 있는 문자열을 int 형으로 변환하여 변환된 정수를 반환한다.
- str 이 가리키고 있는 문자열을 int 형으로 변환할 수 없는 경우라면 0을 반환한다. 오버플로우의 경우 정의되지 않는다(신경X).
- 음수의 경우 - 처리해주기
- 문자열을 만나기 전 숫자까지 처리해주기(음수 역시 동일)

#### 16.  isalpha
- `#include <ctype.h>`
- `int isalpha(int c);`
- alphabetic character test
- tests for any character for which isupper or islower is true.
- the value of the argument must be representable as an unsigned char or the value of EOF.
- A to Z, a to z
- **returns** zero if the character tests false and returns non-zero if the character tests true.
- isupper 또는 islower 가 참인 문자를 체크한다.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- A 부터 Z, a 부터 z
- 거짓인 경우(isupper, islower 모두 거짓)엔 0을, 참인 경우 0이 아닌 수를 반환한다.

#### 17.  isdigit
- `#include <ctype.h>`
- `int isdigit(int c);`
- decimal-digit character test
- tests for a decimal digit character. 0 to 9
- the value of the argument must be representable as an unsigned char or the value of EOF.
- **returns** zero if the character tests fales and return non-zero if the character tests true.
- 0 부터 9 까지의 숫자를 체크한다.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- 거짓인 경우 0을, 참인 경우 0이 아닌 수를 반환한다.

#### 18.  isalnum
- `#include <ctype.h>`
- `int isalnum(int c);`
- alphanumeric character test
- tests for any character for which isalpha or isdigit is true.
- the value of the argument must be representable as an unsigned char or the value of EOF.
- 0 to 9, A to Z, a to z
- **returns** zero if the character tests false and returns non-zero if the character tests true.
- isalpha 혹은 isdigit 가 참인 문자를 체크한다.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- 0~9, A~Z, a~z
- 거짓인 경우 0을, 참인 경우 0이 아닌 수를 반환한다.

#### 19.  isascii
- `#include <ctype.h>`
- `int isascii(int c);`
- test for ASCII character
- tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.
- ASCII 문자인지 체크한다.
- 0 ~ 127 (8진수 000 ~ 177) 사이의 ASCII 문자를 체크한다.
- 거짓인 경우 0을, 참인 경우 0이 아닌 수를 반환한다.

#### 20.  isprint
- `#include <ctype.h>`
- `int isprint(int c);`
- printing character test(space character inclusive)
- tests for any printing character, including space (' ').
- the value of the argument must be representable as an unsigned char or the value of EOF.
- space to ~
- **returns** zero if the character tests false and returns non-zero if the character tests true.
- 공백 문자를 포함한 모든 출력 가능한 문자를 체크한다.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- ' ' 부터 ~ 까지 (10 진수 32 ~ 126)

#### 21.  toupper
- `#include <ctype.h>`
- `int toupper(int c);`
- lower case to upper case letter conversion
- converts a lower-case letter to the corresponding upper-case letter.
- the argument must be representable as an unsigned char or the value of EOF.
- **returns** the corresponding upper-case letter if the argument is a lower-case letter and if there is one. otherwise, the argument is returned unchanged.
- 소문자에서 대문자로 바꾸는 함수.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- 소문자가 존재하고, 그에 대응하는 대문자가 있을 때 대문자를 리턴한다. 그렇지 않다면, 바뀌지 않은 c 가 반환된다.

#### 22.  tolower
- `#include <ctype.h>`
- `int tolower(int c);`
- upper case to lower case letter conversion
- converts an upper-case letter to the corresponding lower-case letter.
- the argument must be representable as an unsigned char or the value of EOF.
- **returns** the corresponding lower-case letter if the argument is a upper-case letter and if there is one. otherwise, the argument is returned unchanged.
- 대문자에서 소문자로 바꾸는 함수.
- 인자로 들어온 값은 unsigned char 혹은 EOF 로 표현할 수 있어야 한다.
- 대문자가 존재하고, 그에 대응하는 소문자가 있을 때 소문자를 리턴한다. 그렇지 않다면, 바뀌지 않은 c 가 반환된다.

#### 23.  calloc
- `#include <stdlib.h>`
- `void *calloc(size_t count, size_t size);`
- memory allocation
- contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.
- the allocated memory is aligned on a page boundary.
- **returns** a pointer to allocated memory if successful. if there's an error, returns a NULL pointer and set errno to ENOMEM.
- 메모리 할당.
- size 바이트 만큼의 메모리를 count 만큼 할당하고, 할당된 메모리에 대한 포인터를 반환한다. 각 요소는 0으로 초기화된다.
- 성공한 경우 할당된 메모리에 대한 포인터를, 실패한 경우 NULL 포인터를 반환한다.

#### 24.  strdup
- `#include <string.h>`
- `char *strdup(const char *s1);`
- save a copy of a string
- allocates sufficient memory for a copy of the string *s1, does the copy, and **returns** a pointer to it.
- the pointer may subsequently be used as an argument to the function free().
- if insufficient memory is available, NULL is returned and errno is set to ENOMEM.
- 문자열 s1 를 복사할 메모리를 할당하고, 복사한 뒤, 할당되고 복사된 메모리 주소를 반환한다.
- 이 때 반환되는 포인터는 free 를 통해 해제할 수 있어야 한다.
- 충분한 메모리가 확보되지 않으면 NULL 을 반환한다.
