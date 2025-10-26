#include <stdio.h>
#include "matematica.h"

int soma(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multiplica(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    return a / b;
}

int main() {
    int x, y;

    printf("Digite o primeiro numero: ");
    scanf("%d", &x);

    printf("Digite o segundo numero: ");
    scanf("%d", &y);

    printf("%d + %d = %d\n", x, y, soma(x, y));
    printf("%d - %d = %d\n", x, y, sub(x, y));
    printf("%d x %d = %d\n", x, y, multiplica(x, y));
    printf("%d / %d = %d\n", x, y, divisao(x, y));

    return 0;
}