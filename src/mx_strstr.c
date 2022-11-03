#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    if (!s1 || !s2) return NULL;

    char *first_character = mx_strchr(s1, *s2);
    int sub_lenth = mx_strlen(s2);

    while (first_character) {
        if (mx_strncmp(first_character, s2, sub_lenth) == 0) {
            return first_character;
        }
        else {
            first_character = mx_strchr(first_character + 1, *s2);
        }
    }

    return NULL;
}
