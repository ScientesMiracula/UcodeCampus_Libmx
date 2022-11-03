#include "libmx.h"

static char *get_pointer_to_strings_end(char *str) {
    char *link_end = str;

    while (*link_end) {
        link_end++;
    }
    return link_end;
}

char *mx_strcat(char *s1, const char *s2) {
    if (!s1 || !s2) return NULL;

    char *s1_end = get_pointer_to_strings_end(s1);

    while (*s2) {
        *s1_end = *s2;
        s1_end++;
        s2++;
    }
    *s1_end = '\0';

    return s1;
}
