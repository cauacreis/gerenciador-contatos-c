#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 100

// Definição da estrutura do contato
typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

// Declaração das funções (Modularização)
void cadastrarContato(Contato *agenda, int *total);
void listarContatos(Contato *agenda, int total);
void buscarContato(Contato *agenda, int total);
void editarContato(Contato *agenda, int total);
void excluirContato(Contato *agenda, int *total);

// Função recursiva exigida pelo projeto
int contarDominioRecursivo(Contato *agenda, int total, int indice, char *dominio);

#endif