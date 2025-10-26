#include <stdio.h>
#include <math.h>
#include "meusutilitarios.h"

int operacoesMat(int a, int b, int op) {
    if (op == 1) {
        return printf("\nResultado da Soma = %d + %d = %d\n", a, b, a + b);
    } else if (op == 2) {
        return printf("\nResultado da Subtracao = %d - %d = %d\n", a, b, a - b);
    } else if (op == 3) {
        return printf("\nResultado da Multiplicacao = %d x %d = %d\n", a, b, a * b);
    } else if (op == 4) {
        return printf("\nResultado da Divisao = %d / %d = %d\n", a, b, a / b);
    } else {
        return printf("Opcao invalida!\n");
    }
}

float conversoes(float temp, int op) {
    if (op == 1) {
        float celsius = (temp - 32) / 1.8;
        return printf("%.1f°C\n", celsius);
    } else if (op == 2) {
        float fahrenheit = 1.8 * temp + 32;
        return printf("%.1f°F\n", fahrenheit);
    } else {
        return printf("Opcao invalida!\n");
    }
}

int contarVogais(char texto[]) {
    int cont = 0, i;

    for(i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            cont++;
        }
    }

    return cont;
}

void inverterString(char texto[]) {
    int inicio = 0, fim = 0;
    char temp;

    while(texto[fim] != '\0') {
        fim++;
    }

    fim--;

    while(inicio < fim) {
        temp = texto[inicio];
        texto[inicio] = texto[fim];
        texto[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    int opcaoMenu = 0, opcaoOperacao = 0;
    int x, y;
    float temperatura;
    char frase[100];

    printf("\n=== ESCOLHA UMA OPCAO ABAIXO ===\n");
    printf("1 - Operacoes Matematicas\n2 - Conversoes de Temperatura\n3 - Manipulacao de Texto\n--- Opcao: ");
    scanf("%d", &opcaoMenu);

    if (opcaoMenu == 1) {
        printf("\n=== ESCOLHA UMA OPERACAO ===\n");
        printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n--- Opcao: ");
        scanf("%d", &opcaoOperacao);
        printf("\nDigite o primeiro valor: ");
        scanf("%d", &x);
        printf("Digite o segundo valor: ");
        scanf("%d", &y);
        operacoesMat(x, y, opcaoOperacao);
    } else if (opcaoMenu == 2) {
        printf("\n=== ESCOLHA UMA CONVERSAO ===\n");
        printf("1 - Fahrenheit para Celsius\n2 - Celsius para Fahrenheit\n--- Opcao: ");
        scanf("%d", &opcaoOperacao);
        printf("\nDigite a temperatura: ");
        scanf("%f", &temperatura);
        conversoes(temperatura, opcaoOperacao);
    } else if (opcaoMenu == 3) {
        printf("\n=== ESCOLHA UMA MANIPULCACAO ===\n");
        printf("1 - Contar vogais\n2 - Converter frase\n--- Opcao: ");
        scanf("%d", &opcaoOperacao);

        getchar();

        printf("\nDigite uma frase: ");
        fgets(frase, sizeof(frase), stdin);

        if (opcaoOperacao == 1) {
            printf("\nNumero de vogais: %d\n", contarVogais(frase));
        } else if (opcaoOperacao == 2) {
            inverterString(frase);
            printf("\nFrase invertida: %s\n", frase);
        } else {
            printf("Opcao invalida!\n");
        }
    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}