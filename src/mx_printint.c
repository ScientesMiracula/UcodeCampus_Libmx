#include "libmx.h"

static void print_reversed_arr(int *arr) {
    int count = 0;
    while (*arr > 0) {
        count++;
        arr++;
    }
    while (count > 0) {
        arr--;
        count--;
        mx_printchar(*arr + '0');
    }
}

void mx_printint(int n) {
    bool is_negative = false;
    int num_str[30] = {-1};
    int *num_str_element = num_str;

    if (n < 0) {
        is_negative = true;
        mx_printchar('-');
    }
    if (n == 0) {
        mx_printchar('0');
        return;
    }

    while (n != 0) {
        *num_str_element = (n % 10) * (-2 * is_negative + 1);
        n /= 10;
        num_str_element++;
    }
    print_reversed_arr(num_str);
}
