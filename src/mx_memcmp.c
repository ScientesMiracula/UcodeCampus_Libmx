#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *s1_ch = (unsigned char *)s1;
    unsigned char *s2_ch = (unsigned char *)s2;

    while (*s1_ch == *s2_ch && n) {
        n--;
        s1_ch++;
        s2_ch++;
    }

    return s1_ch - s2_ch;
}
