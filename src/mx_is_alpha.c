#include "libmx.h"

bool mx_is_alpha(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z') ||
           (symbol >= 'a' && symbol <= 'z');
}
