#include <stdio.h>
#include "utilidades.h"

int maior(int a, int b, int c) {
    int maior = 0;

    if(a > b && a > c) {
        maior = a;
    } else if(b > a && b > c) {
        maior = b;
    } else {
        maior = c;
    }

    return maior;
}

int menor(int a, int b, int c) {
    int menor = 0;

    if(a < b && a < c) {
        menor = a;
    } else if(b < a && b < c) {
        menor = b;
    } else {
        menor = c;
    }

    return menor;
}

int main() {
    int x, y, z;

    printf("Digite o primeiro numero: ");
    scanf("%d", &x);

    printf("Digite o segundo numero: ");
    scanf("%d", &y);

    printf("Digite o terceiro numero: ");
    scanf("%d", &z);

    printf("Maior numero digitado = %d\n", maior(x, y, z));
    printf("Menor numero digitado = %d\n", menor(x, y, z));

    return 0;
}