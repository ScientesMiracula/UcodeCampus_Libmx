#include "libmx.h"

char *mx_replace_substr(const char *str,
                        const char *sub,
                        const char *replace) {
    if (!str || !sub || !replace) return NULL;

    int sub_lenth = mx_strlen(sub);
    int replacement_lenth = mx_strlen(replace);
    char *new_str =
        mx_strnew(mx_strlen(str) - mx_count_substr(str, sub) *
                                       (sub_lenth - replacement_lenth));
    char *new_str_element = new_str;
    const char *sub_start = mx_strstr(str, sub);

    while (*sub_start) {
        mx_strncpy(new_str_element, str, sub_start - str);
        new_str_element += sub_start - str;
        str = sub_start;
        mx_strncpy(new_str_element, replace, replacement_lenth);
        str += sub_lenth;
        new_str_element += replacement_lenth;
        sub_start = mx_strstr(str, sub);
    }
    mx_strcpy(new_str_element, str);

    return new_str;
}
