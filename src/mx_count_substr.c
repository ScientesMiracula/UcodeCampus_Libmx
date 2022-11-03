#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!sub || !str) {
        return -1;
    }

    int subs_count = 0;
    int sub_size = mx_strlen(sub);
    const char *sub_location = mx_strstr(str, sub);

    while (sub_location) {
        subs_count++;
        str = sub_location;
        str += sub_size;
        sub_location = mx_strstr(str, sub);
    }
    return subs_count;
}
