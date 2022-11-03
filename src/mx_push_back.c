#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *last_element = *list;
    t_list *new_element = mx_create_node(data);

    if (!last_element) {
        *list = new_element;
        return;
    }
    while (last_element->next) {
        last_element = last_element->next;
    }

    last_element->next = new_element;
}
