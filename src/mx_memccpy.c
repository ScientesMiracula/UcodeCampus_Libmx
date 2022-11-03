#include "libmx.h"

void *mx_memccpy(void *restrict dst,
                 const void *restrict src,
                 int c,
                 size_t n) {
    unsigned char *dst_ch = (unsigned char *)dst;
    unsigned char *src_ch = (unsigned char *)src;

    while (n) {
        if (*dst_ch == c) {
            return dst_ch + 1;
        }
        *dst_ch = *src_ch;
        n--;
    }
    return NULL;
}
