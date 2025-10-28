
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b;
    char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    printf("Сколько паролей? ");
    scanf("%d", &a);

    printf("Длина пароля? ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Ошибка: число должно быть положительным\n");
        return 1;
    }

    srand(time(0));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%c", chars[rand() % 62]);
        }
        printf("\n");
    }
    return 0;
}
