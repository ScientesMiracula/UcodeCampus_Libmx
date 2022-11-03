#include "libmx.h"

void mx_del_strarr(char ***arr) {
    if (!(*arr)) return;

    while (**arr) {
        mx_strdel(*arr);
        (*arr)++;
    }
    free(*arr);
    *arr = NULL;
}
