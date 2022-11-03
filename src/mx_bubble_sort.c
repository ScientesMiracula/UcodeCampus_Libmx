#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2);

static void swap_links(char **link1, char **link2) {
    char *buffer;
    buffer = *link1;
    *link1 = *link2;
    *link2 = buffer;
}

int mx_bubble_sort(char **arr, int size) {
    int counter = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                counter++;
                swap_links(&arr[j], &arr[j + 1]);
            }
        }
    }
    return counter;
}
