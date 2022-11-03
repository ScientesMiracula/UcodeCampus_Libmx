#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    bool is_previous_delimiter = true;
    int words_counter = 0;

    if (!str) {
        return -1;
    }

    while (*str) {
        if (*str == delimiter) {
            is_previous_delimiter = true;
        }
        else if (is_previous_delimiter) {
            words_counter++;
            is_previous_delimiter = false;
        }
        str++;
    }

    return words_counter;
}
