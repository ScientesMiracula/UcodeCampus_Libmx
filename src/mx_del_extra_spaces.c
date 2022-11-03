#include "libmx.h"

static int count_words(const char *str) {
    bool is_previous_delimiter = true;
    int words_counter = 0;

    if (!str) {
        return -1;
    }

    while (*str) {
        if (mx_is_space(*str)) {
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

static char *dup_word(const char *src, int the_word_lenth) {
    char *word_copy = mx_strnew(the_word_lenth);

    mx_strncpy(word_copy, src, the_word_lenth);
    word_copy[the_word_lenth] = '\0';

    return word_copy;
}

static char *rebase_arr_to_str(char **arr, int arr_size) {
    int new_word_lenth = 0;
    int words_lenthes[arr_size];
    int *lenthes_element = words_lenthes;
    char *new_word;
    char *new_word_element;

    while (*arr) {
        *lenthes_element = mx_strlen(*arr);
        new_word_lenth += *lenthes_element;
        lenthes_element++;
        arr++;
    }
    new_word_lenth += arr_size - 1;

    lenthes_element -= arr_size;
    arr -= arr_size;

    new_word = mx_strnew(new_word_lenth);
    new_word_element = new_word;

    while (*arr) {
        mx_strncpy(new_word_element, *arr, *lenthes_element);
        new_word_element += *lenthes_element;
        arr++;
        lenthes_element++;
    }

    mx_del_strarr(&arr);
    return new_word;
}

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;
    int words_count = count_words(str);
    char **words = malloc((words_count + 1) * sizeof(char *));
    char **words_element = words;
    int the_word_lenth;

    words[words_count] = NULL;

    while (*str) {
        while (mx_is_space(*str)) {
            str++;
        }
        the_word_lenth = 0;
        while (!mx_is_space(*str)) {
            the_word_lenth++;
            str++;
        }
        str -= the_word_lenth;
        *words_element = dup_word(str, the_word_lenth);
        words_element++;
        str += the_word_lenth;
    }

    return rebase_arr_to_str(words, words_count);
}
