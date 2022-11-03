#include "libmx.h"

static void skip_delimeters_before_word(const char **link_to_str,
                                        char c) {
    while (**link_to_str == c) {
        link_to_str++;
    }
}

static char *dup_word(const char *src, int the_word_lenth) {
    char *word_copy = mx_strnew(the_word_lenth);

    mx_strncpy(word_copy, src, the_word_lenth);
    word_copy[the_word_lenth] = '\0';

    return word_copy;
}

char **mx_strsplit(char const *s, char c) {
    if (!s) return NULL;

    int words_in_str = mx_count_words(s, c);
    char **arr = malloc((words_in_str + 1) * sizeof(char *));
    char **arr_actual_str = arr;
    int the_word_lenth;

    arr[words_in_str] = NULL;

    while (*s) {
        skip_delimeters_before_word(&s, c);
        the_word_lenth = 0;
        while (*s && *s != c) {
            the_word_lenth++;
            s++;
        }
        s -= the_word_lenth;
        *arr_actual_str = dup_word(s, the_word_lenth);
        arr_actual_str++;
        s += the_word_lenth;
    }

    return arr;
}
