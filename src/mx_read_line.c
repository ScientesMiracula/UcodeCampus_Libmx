#include "libmx.h"

int mx_read_line(char **lineptr,
                 size_t buf_size,
                 char delim,
                 const int fd) {
    if (buf_size < 0 || fd < 0) {
        return -2;
    }

    char buf;
    size_t readed_bytes = 0;

    (*lineptr) = mx_strnew(0);

    while (buf_size > 0 && read(fd, &buf, 1) && buf != delim ) {
        (*lineptr) = mx_realloc((*lineptr), readed_bytes + 1);
        (*lineptr)[readed_bytes] = buf;
        readed_bytes++;
        buf_size--;
    }

    if (readed_bytes == 0 && buf != delim) {
        return -1;
    }
    else {
        return readed_bytes + 1;
    }
}
