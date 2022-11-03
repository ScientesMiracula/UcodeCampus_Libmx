#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *ans = malloc(sizeof(t_list));

    if (!ans) return NULL;

    ans->data = data;
    ans->next = NULL;

    return ans;
}
