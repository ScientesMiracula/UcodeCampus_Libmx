#include "libmx.h"

bool mx_is_alpha(char symbol) {
    return (symbol >= '\a' && symbol <= '\r') || symbol == ' ';
}
