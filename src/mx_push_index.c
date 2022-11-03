#include "libmx.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (index <= 0) {
        mx_push_front(list, data);
    }

    t_list *list_element = *list;
    t_list *new_element = mx_create_node(data);

    while (index > 0 && list_element->next) {
        list_element = list_element->next;
        index--;
    }

    if (!(list_element->next)) {
        mx_push_back(list, data);
    }

    new_element->next = list_element->next;
    list_element->next = new_element;
}
