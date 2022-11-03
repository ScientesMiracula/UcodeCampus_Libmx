#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *new_element = mx_create_node(data);

    if (!(*list)) {
        *list = new_element;
        return;
    }
    new_element->next = *list;
    *list = new_element;
}
