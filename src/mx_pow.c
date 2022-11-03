#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double ans = n;

    if (pow == 0) return 1;
    while (pow > 1) {
        ans *= n;
        pow--;
    }
    return ans;
}
