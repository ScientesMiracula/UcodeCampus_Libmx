#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *buf = malloc(len);

    for (size_t i = 0; i < len; i++) {
        buf[i] = ((unsigned char *)(src))[i];
    }
    for (size_t i = 0; i < len; i++) {
        ((unsigned char *)(dst))[i] = buf[i];
    }
    free(buf);

    return dst;
}
