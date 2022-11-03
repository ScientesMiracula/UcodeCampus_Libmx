#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *save_dst = dst;

    if (!dst) {
        return NULL;
    }
    while (*src && len) {
        *dst = *src;
        dst++;
        src++;
        len--;
    }
    while (len) {
        *dst = '\0';
        len--;
        dst++;
    }

    return save_dst;
}
