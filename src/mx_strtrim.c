#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) return NULL;
    if (!(*str)) {
        return mx_strnew(0);
    }

    int trimed_lenth;
    const char *end_of_str;

    while (*str && mx_is_space(*str)) {
        str++;
    }

    trimed_lenth = mx_strlen(str);
    end_of_str = str;
    while (*end_of_str) {
        end_of_str++;
    }

    while (mx_is_space(*end_of_str)) {
        trimed_lenth--;
        end_of_str--;
    }

    return mx_strndup(str, trimed_lenth);
}
