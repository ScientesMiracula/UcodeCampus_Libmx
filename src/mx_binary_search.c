#include "libmx.h"

static int bin_search(
    char **arr, const char *s, int left, int right, int *count) {
    int diff = right - left;
    int center = left + diff / 2;
    int compare_result;

    (*count)++;

    if (diff < 2) {
        if (mx_strcmp(arr[left], s) == 0) {
            return left;
        }
        if (mx_strcmp(arr[right], s) == 0) {
            return right;
        }
        *count = 0;
        return -1;
    }

    compare_result = mx_strcmp(arr[center], s);

    if (compare_result == 0) {
        return center;
    }
    return compare_result > 0
               ? bin_search(arr, s, left, center - 1, count)
               : bin_search(arr, s, center + 1, right, count);
}

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!arr || !s || !count) return -1;
    return bin_search(arr, s, 0, size - 1, count);
}
