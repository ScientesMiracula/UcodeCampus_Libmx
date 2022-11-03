#include "libmx.h"

static int bin_search(long int left, long int right, int target) {
    int diffinition = right - left;

    if (diffinition < 2) {
        int ans = 0;

        if (left * left == target) {
            ans = left;
        }
        else if (right * right == target) {
            ans = right;
        }

        return ans;
    }

    long int center = left + diffinition / 2;

    if (center * center <= target) {
        return bin_search(center, right, target);
    }
    else {
        return bin_search(left, center - 1, target);
    }
}

int mx_sqrt(int x) {
    if (x == 1) return 1;
    if (x <= 3) return 0;

    return bin_search(2, x / 2, x);
}
