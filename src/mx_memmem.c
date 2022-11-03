#include "libmx.h"

static void *new_potential_little(unsigned char *little_in_big,
                                  unsigned char *little_ch,
                                  const void *big,
                                  size_t big_len) {
    return mx_memchr(little_in_big,
                     *little_ch,
                     little_in_big - (unsigned char *)big + big_len);
}

void *mx_memmem(const void *big,
                size_t big_len,
                const void *little,
                size_t little_len) {
    unsigned char *big_ch = (unsigned char *)big;
    unsigned char *little_ch = (unsigned char *)little;
    unsigned char *little_in_big = big_ch;

    while ((little_in_big = new_potential_little(little_in_big,
                                                 little_ch,
                                                 big,
                                                 big_len))) {
        if (mx_memcmp(little_in_big, little_ch, little_len) == 0) {
            return little_in_big;
        }
        else {
            little_in_big++;
        }
    }
    return NULL;
}
