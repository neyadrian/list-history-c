#include <stdio.h>
#include <string.h>
#include "telefone.h"

int main() {
    int opcao;

    do {
        printf("\n--- AGENDA ---\n");
        printf("1 - Inserir pessoa\n2 - Remover pessoa\n3 - Buscar por nome\n");
        printf("4 - Buscar por mes de aniversario\n5 - Buscar por dia e mes de aniversario\n");
        printf("6 - Imprimir agenda (resumo)\n7 - Imprimir agenda (completo)\n0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        getchar();
 
        if (opcao == 1) {
            Pessoa p;
            printf("Nome: ");
            fgets(p.nome, 50, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;

            printf("Email: ");
            fgets(p.email, 50, stdin);
            p.email[strcspn(p.email, "\n")] = 0;

            printf("Rua: ");
            fgets(p.endereco.rua, 50, stdin);
            p.endereco.rua[strcspn(p.endereco.rua, "\n")] = 0;

            printf("Numero: ");
            scanf("%d", &p.endereco.numero); 
            
            getchar();
        
            printf("Complemento: ");
            fgets(p.endereco.complemento, 30, stdin);
            p.endereco.complemento[strcspn(p.endereco.complemento, "\n")] = 0;

            printf("Bairro: ");
            fgets(p.endereco.bairro, 30, stdin);
            p.endereco.bairro[strcspn(p.endereco.bairro, "\n")] = 0;

            printf("CEP: ");
            fgets(p.endereco.cep, 10, stdin);
            p.endereco.cep[strcspn(p.endereco.cep, "\n")] = 0;

            printf("Cidade: ");
            fgets(p.endereco.cidade, 30, stdin);
            p.endereco.cidade[strcspn(p.endereco.cidade, "\n")] = 0;

            printf("Estado: ");
            fgets(p.endereco.estado, 20, stdin);
            p.endereco.estado[strcspn(p.endereco.estado, "\n")] = 0;

            printf("Pais: ");
            fgets(p.endereco.pais, 20, stdin);
            p.endereco.pais[strcspn(p.endereco.pais, "\n")] = 0;

            printf("DDD: ");
            scanf("%d", &p.telefone.ddd); 
            
            getchar();

            printf("Numero telefone: ");
            fgets(p.telefone.numero, 15, stdin);
            p.telefone.numero[strcspn(p.telefone.numero, "\n")] = 0;

            printf("Data aniversario (dia mes ano): ");
            scanf("%d %d %d", &p.aniversario.dia, &p.aniversario.mes, &p.aniversario.ano);

            getchar();

            printf("Observacao: ");
            fgets(p.observacao, 100, stdin);
            p.observacao[strcspn(p.observacao, "\n")] = 0;

            inserirPessoa(p);
        } else if (opcao == 2) {
            char nome[50];

            printf("Nome a remover: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;

            removerPessoa(nome);
        } else if (opcao == 3) {
            char nome[50];

            printf("Nome a buscar: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;

            buscarPorNome(nome);
        } else if (opcao == 4) {
        int mes;
            printf("Mes: ");
            scanf("%d", &mes); 
            
            getchar();
            
            buscarPorMes(mes);
        } else if (opcao == 5) {
        int dia, mes;
            printf("Dia e mes: ");
            scanf("%d %d", &dia, &mes); 
            
            getchar();
            
            buscarPorDiaMes(dia, mes);
        } else if (opcao == 6) {
            imprimirAgenda(0);
        } else if (opcao == 7) {
            imprimirAgenda(1);
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}