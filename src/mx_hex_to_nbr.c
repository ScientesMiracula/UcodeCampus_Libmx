#include "libmx.h"

static int convert_hex_digit_to_dec(const char c) {
    if (mx_is_digit(c)) {
        return c - '0';
    }
    if (mx_is_alpha(c)) {
        return c - (mx_is_lower(c) ? 'a' : 'A') + 10;
    }
    return 0;
}

static const char *get_en_of_num_link(const char *num) {
    while (*num) {
        num++;
    }
    return num;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long ans = 0;
    unsigned long number_rank = 1;
    const char *last_digit = get_en_of_num_link(hex);

    while (last_digit > hex) {
        last_digit--;
        ans += number_rank * convert_hex_digit_to_dec(*last_digit);
        number_rank *= 16;
    }

    return ans;
}
