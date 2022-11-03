#include "libmx.h"

void mx_pop_back(t_list **list) {
    t_list *last_element = *list;
    t_list *prelast_element = *list;

    while (last_element->next) {
        prelast_element = last_element;
        last_element = last_element->next;
    }

    free(last_element);
    prelast_element->next = NULL;
}
