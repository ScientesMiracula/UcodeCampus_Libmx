#include "libmx.h"

void mx_pop_front(t_list **list) {
    if (!((*list)->next)) {
        free(*list);
        *list = NULL;
    }

    t_list *second_element = (*list)->next;

    free(*list);
    *list = second_element;
}
