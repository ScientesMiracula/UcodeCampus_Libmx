#include "libmx.h"

bool comparator(char *left, char *right) {
    return mx_strlen(left) > mx_strlen(right);
}

static void swap_rows(char **l1, char **l2) {
    char *buffer = *l1;
    *l1 = *l2;
    *l2 = buffer;
}

static void partly_quicksort(char **left, char **right, int *swaps) {
    if (right - left == 1) {
        if (comparator(*left, *right)) {
            swap_rows(left, right);
            (*swaps)++;
        }
        return;
    }
    char **center = left + (right - left) / 2;
    char **save_left = left, **save_right = right;
    bool need_swap_left = 0, need_swap_right = 0;

    while (left <= center && right >= center && left < right) {
        if (left == center) need_swap_left = true;
        if (right == center) need_swap_right = true;

        if (!need_swap_left) {
            if (comparator(*left, *center)) {
                need_swap_left = true;
            }
            else {
                left++;
            }
        }
        if (!need_swap_right) {
            if (comparator(*center, *right)) {
                need_swap_right = true;
            }
            else {
                right--;
            }
        }

        if (need_swap_left && need_swap_right) {
            swap_rows(left, right);
            (*swaps)++;
            if (left == center || right == center) {
                left = save_left;
                right = save_right;
            }
            else {
                left++;
                right--;
            }
            need_swap_left = false;
            need_swap_right = false;
        }
    }

    partly_quicksort(save_left, center, swaps);
    partly_quicksort(center, save_right, swaps);
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;

    int swaps = 0;

    partly_quicksort(arr + left, arr + right, &swaps);

    return swaps;
}
