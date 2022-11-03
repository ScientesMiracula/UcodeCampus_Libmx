#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *dst_ch = b;

    while (len ) {
        *dst_ch = (unsigned char)c;
        len--;
        dst_ch++;
    }
    return b;
}
