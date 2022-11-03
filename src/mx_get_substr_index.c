#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) return -2;

    const char *potential_sub_start = mx_strchr(str, *sub);
    int sub_lenth = mx_strlen(sub);

    while (potential_sub_start) {
        if (mx_strncmp(potential_sub_start, sub, sub_lenth) == 0) {
            return potential_sub_start - str;
        }
        else {
            potential_sub_start =
                mx_strchr(potential_sub_start + 1, *sub);
        }
    }

    return -1;
}
