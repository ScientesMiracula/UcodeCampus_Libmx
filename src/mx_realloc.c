#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (!ptr || size == 0) {
        if (!ptr) {
            return malloc(size);
        }
        else {
            free(ptr);
            return NULL;
        }
    }

    void *newptr;
    size_t ptr_size = malloc_usable_size(ptr);

    newptr = malloc(size);
    mx_memcpy(newptr, ptr, size >= ptr_size ? ptr_size : size);

    free(ptr);
    return newptr;
}
