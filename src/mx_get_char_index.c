#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str) return -2;

    int index = 0;

    while (*str && *str != c) {
        str++;
        index++;
    }
    if (*str == c) return index;

    return -1;
}
