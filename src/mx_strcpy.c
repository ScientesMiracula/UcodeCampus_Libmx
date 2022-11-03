#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *save_dst = dst;

    if (!dst) {
        return NULL;
    }
    while (*src) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';

    return save_dst;
}
