#include <stdio.h>

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }

int main() { int n, m;

printf("n m: ");
scanf("%d %d", &n, &m);

if (n <= 0 || m <= 0) {
    printf("Ошибка\n");
    return 0;
}

int res = (n * m) / gcd(n, m);
printf("НОК = %d\n", res);

return 0;
}