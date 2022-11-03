#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    const char *string_element = s;

    while (*string_element && *string_element != c) {
        string_element++;
    }
    
    return *string_element == c ? (char *)string_element : NULL;
}
