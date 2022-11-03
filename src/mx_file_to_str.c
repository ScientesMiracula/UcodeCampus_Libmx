#include "libmx.h"

static long file_size(long file_d) {
    int size = 0;
    char buf;

    while (read(file_d, &buf, 1)) {
        size++;
    }
    return size;
}

char *mx_file_to_str(const char *filename) {
    char *new_str;
    long file_d;
    int bytes_to_read;

    file_d = open(filename, O_RDONLY);

    if (file_d == -1) {
        return NULL;
    }

    bytes_to_read = file_size(file_d);
    new_str = mx_strnew(bytes_to_read);
    close(file_d);

    file_d = open(filename, O_RDONLY);

    if (file_d == -1) {
        free(new_str);
        return NULL;
    }

    if (!read(file_d, new_str, bytes_to_read) || close(file_d)) {
        free(new_str);
        return NULL;
    }

    return new_str;
}
