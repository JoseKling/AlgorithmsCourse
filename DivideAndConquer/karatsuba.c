#include <stdio.h>

int karatsuba(int x, int y, int n) {
    int m = n >> 1;
    if ((x >> 1 == 0) || (y >> 1 == 0)) {
        if ((x == 0) || (y == 0)) {
            return 0;
        } else {
            if (x == 1) {
                return y;
            } else {
                return x;
            }
        }
    } else {
        int x1 = x >> m;
        int x0 = x - (x1 << m);
        int y1 = y >> m;
        int y0 = y - (y1 << m);
        int z0 = karatsuba(x0, y0, m);
        int z2 = karatsuba(x1, y1, n - m);
        int z3 = karatsuba((x0 + x1), (y0 + y1), m + 1);
        int z1 = z3 - z2 - z0;
        return (z2 << (m << 1)) + (z1 << m) + z0;
    }
}

int main() {
    int x;
    int y;
    printf("Type the first number to be multiplied \n");
    scanf("%d", &x);
    printf("Type the second number to be multiplied \n");
    scanf("%d", &y);
    int n = 0, x_shift = x, y_shift = y;
    while ((x_shift > 0) || (y_shift > 0)) {
        x_shift = x_shift >> 1;
        y_shift = y_shift >> 1;
        n = n + 1;
    }
    int result = karatsuba(x, y, n);
    printf("%d x %d = %d\n", x, y, result);
    return 0;
}