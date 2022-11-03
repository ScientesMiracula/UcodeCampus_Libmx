#include "libmx.h"

static char conver_to_hex_digit(int num) {
    if (num < 10) {
        return num + '0';
    }
    else {
        return num - 10 + 'a';
    }
}

static int calculate_hex_bit_size(unsigned long num) {
    int ans = 0;

    if (num == 0) return 1;

    while (num > 0) {
        ans++;
        num /= 16;
    }

    return ans;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int byte_size = calculate_hex_bit_size(nbr);
    char *ans = mx_strnew(byte_size);

    if (!ans) return NULL;

    while (byte_size > 0) {
        ans[byte_size - 1] = conver_to_hex_digit(nbr % 16);
        nbr /= 16;
        byte_size--;
    }

    return ans;
}
