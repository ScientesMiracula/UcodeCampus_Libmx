#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *s_ch_end = (unsigned char *)s + mx_strlen((char *)s);

    while (n--) {
        if (*s_ch_end == (unsigned char)c) return s_ch_end;
        s_ch_end--;
    }
    return NULL;
}
