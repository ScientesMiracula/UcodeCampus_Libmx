#include "libmx.h"

static int calculate_num_size(int num) {
    int size = 0;

    if (num == 0) return 1;
    if (num < 0) size++;

    while (num != 0) {
        num /= 10;
        size++;
    }

    return size;
}

char *mx_itoa(int number) {
    int num_size = calculate_num_size(number);
    char *new_str = mx_strnew(num_size);
    char *str_element = new_str + num_size - 1;
    int leveler = 1;

    if (number < 0) {
        new_str[0] = '-';
        leveler = -1;
    }
    if (number == 0) {
        new_str[0] = '0';
        return new_str;
    }

    while (number != 0) {
        *str_element = (number % 10) * leveler + '0';
        number /= 10;
        str_element--;
    }

    return new_str;
}
