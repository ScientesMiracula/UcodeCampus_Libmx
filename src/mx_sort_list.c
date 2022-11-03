#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    int size = mx_list_size(list);
    t_list *list_head = list;
    t_list *previous_element;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(list->data, list->next->data)) {
                if (list == list_head) {
                    list_head = list->next;
                }
                else {
                    previous_element = list_head;
                    while (previous_element->next != list) {
                        previous_element++;
                    }
                    previous_element->next = list->next;
                }
                list->next->next = list;
                list->next = list->next->next;
            }
            else {
                list = list->next;
            }
        }
        list = list_head;
    }

    return list_head;
}
