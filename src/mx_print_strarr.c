#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !arr[0] || !delim) {
        return;
    }
    while (*arr) {
        mx_printstr(*arr);
        mx_printstr(delim);
        arr++;
    }
    mx_printchar('\n');
}
