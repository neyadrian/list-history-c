#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telefone.h"

Pessoa agenda[1000];
int total = 0;

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\nEmail: %s\nEndereco: %s, %d, %s, %s, %s, %s, %s,%s\n",
    p.nome, p.email, p.endereco.rua, p.endereco.numero,
    p.endereco.complemento, p.endereco.bairro, p.endereco.cep,
    p.endereco.cidade, p.endereco.estado, p.endereco.pais);
    printf("Telefone: (%d) %s\n", p.telefone.ddd, p.telefone.numero);
    printf("Aniversario: %02d/%02d/%04d\n", p.aniversario.dia,
    p.aniversario.mes, p.aniversario.ano);
    printf("Observacao: %s\n-----------------------\n", p.observacao);
}

void imprimirResumo(Pessoa p) {
    printf("Nome: %s | Telefone: (%d) %s | Email: %s\n",
    p.nome, p.telefone.ddd, p.telefone.numero, p.email);
}

void inserirPessoa(Pessoa p) {
    if (total >= 1000) {
        printf("Agenda cheia!\n");
        return;
    }

    int i = total - 1;

    while (i >= 0 && strcmp(agenda[i].nome, p.nome) > 0) {
        agenda[i + 1] = agenda[i];
        i--;
    }

    agenda[i + 1] = p;
    total++;
    printf("Pessoa inserida com sucesso!\n");
}

void removerPessoa(char *nome) {
    int i, j, encontrado = 0;

    for (i = 0; i < total;) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            for (j = i; j < total - 1; j++)
            agenda[j] = agenda[j + 1];
            total--;
            encontrado = 1;
        } else i++;
    }
    if (encontrado)
        printf("Pessoa(s) removida(s)!\n");
    else
        printf("Nenhuma pessoa encontrada.\n");
}

void buscarPorNome(char *nome) {
    int encontrado = 0;

    for (int i = 0; i < total; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            imprimirPessoa(agenda[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhuma pessoa encontrada.\n");
}

void buscarPorMes(int mes) {
    int encontrado = 0;

    for (int i = 0; i < total; i++) {
        if (agenda[i].aniversario.mes == mes) {
            imprimirPessoa(agenda[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhuma pessoa faz aniversario nesse mes.\n");
}

void buscarPorDiaMes(int dia, int mes) {
    int encontrado = 0;

    for (int i = 0; i < total; i++) {
        if (agenda[i].aniversario.dia == dia &&
            agenda[i].aniversario.mes == mes) {
            imprimirPessoa(agenda[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhuma pessoa faz aniversario nesse dia e mes.\n");
}

void imprimirAgenda(int completa) {
    for (int i = 0; i < total; i++) {
        if (completa)
            imprimirPessoa(agenda[i]);
        else
            imprimirResumo(agenda[i]);
    }
}