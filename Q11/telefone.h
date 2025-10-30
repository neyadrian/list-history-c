#ifndef TELEFONE_H
#define TELEFONE_H

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int ddd;
    char numero[15];
} Telefone;

typedef struct {
    char rua[50];
    int numero;
    char complemento[30];
    char bairro[30];
    char cep[10];
    char cidade[30];
    char estado[20];
    char pais[20];
} Endereco;

typedef struct {
    char nome[50];
    char email[50];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
    char observacao[100];
} Pessoa;

void inserirPessoa(Pessoa p);
void removerPessoa(char *nome);
void buscarPorNome(char *nome);
void buscarPorMes(int mes);
void buscarPorDiaMes(int dia, int mes);
void imprimirPessoa(Pessoa p);
void imprimirResumo(Pessoa p);
void imprimirAgenda(int completa);

#endif