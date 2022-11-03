#include "libmx.h"

char *mx_strdup(const char *str) {
    if (!str) {
        return NULL;
    }
    return mx_strcpy(mx_strnew(mx_strlen(str)), str);
}
