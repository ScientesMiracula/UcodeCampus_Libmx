#include "libmx.h"

int mx_list_size(t_list *list) {
    int lenth = 0;

    if (!list) {
        return 0;
    }
    else {
        lenth++;
    }

    while (list->next) {
        lenth++;
        list = list->next;
    }

    return lenth;
}
