#include "libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) {
    while (size > 0) {
        size--;
        f(*arr);
        arr++;
    }
}
