#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *s_ch = (unsigned char *)s;

    while (n--) {
        if (*s_ch == (unsigned char)c) return s_ch;
        s_ch--;
    }
    return NULL;
}
