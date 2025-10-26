#include <stdio.h>
#include "stringutils.h"

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
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Numero de vogais: %d\n", contarVogais(frase));
    inverterString(frase);
    printf("Frase invertida: %s\n", frase);

    return 0;
}