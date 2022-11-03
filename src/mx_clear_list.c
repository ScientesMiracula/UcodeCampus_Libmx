#include "libmx.h"

void mx_clear_list(t_list **list, bool need_data_free) {
    t_list *list_element = *list;
    t_list *prelist_element = *list;

    while (list_element->next) {
        prelist_element = list_element;
        list_element = list_element->next;

        if (need_data_free) free(prelist_element->data);

        free(prelist_element);
    }

    if (need_data_free) free(list_element->data);

    free(list_element);
    *list = NULL;
}
