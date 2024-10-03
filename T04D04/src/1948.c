#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int largest_prime_divisor(int a) {
    if (a < 0) a = -a;
    int largest_divisor = 1;
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0 && is_prime(i)) {
            largest_divisor = i;
        }
    }
    return largest_divisor;
}

int main() {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a\n");
        return 0;
    }
    int result = largest_prime_divisor(a);
    if (result == 1) {
        printf("n/a\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}