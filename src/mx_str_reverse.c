#include "libmx.h"

void mx_str_reverse(char *s) {
    if (!s) {
        return;
    }

    char *center = s + mx_strlen(s) / 2;

    while (s <= center) {
        mx_swap_char(s, s + (s - center) * 2);
        s++;
    }
}
