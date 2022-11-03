#include "libmx.h"

void mx_pop_index(t_list **list, int index) {
    if (index <= 0) {
        mx_pop_front(list);
    }

    t_list *list_element = *list;
    t_list *prelist_element = *list;

    while (index > 0 && list_element->next) {
        prelist_element = list_element;
        list_element = list_element->next;
        index--;
    }

    if (!(list_element->next)) {
        mx_pop_back(list);
    }

    prelist_element->next = list_element->next;
    free(list_element);
}
