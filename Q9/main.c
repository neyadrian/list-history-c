#include <stdio.h>
#include <math.h>
#include "financeiro.h"

float calcularJurosSimples(float capital, float taxa, float tempo) {
    float jurosSimples;

    jurosSimples = capital * taxa * tempo;

    return jurosSimples;
}

float calcularJurosCompostos(float capital, float taxa, float tempo) {
    float mont;

    mont = capital * pow((1 + taxa), tempo);

    return mont - capital;
}

int main() {
    float cap, tx, tmp;

    printf("Digite o capital: ");
    scanf("%f", &cap);
    printf("Digite a taxa: ");
    scanf("%f", &tx);
    printf("Digite o tempo: ");
    scanf("%f", &tmp);

    printf("Juros Simpes = %.2f\n", calcularJurosSimples(cap, tx, tmp));
    printf("Juros Compostos = %.2f\n", calcularJurosCompostos(cap, tx, tmp));

    return 0;
}