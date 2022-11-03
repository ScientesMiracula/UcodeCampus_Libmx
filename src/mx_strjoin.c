#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *new_string;

    if (!s1 && !s2) return NULL;
    if (!s1 || !s2) return mx_strdup(s1);

    new_string = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    mx_strcpy(new_string, s1);
    mx_strcpy(new_string + mx_strlen(s1), s2);

    return new_string;
}
