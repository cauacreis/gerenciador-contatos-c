#include <stdio.h>
#include <string.h>
#include "contatos.h"

// Função auxiliar para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarContato(Contato *agenda, int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("Agenda lotada!\n");
        return;
    }
    
    printf("\n--- Novo Cadastro ---\n");
    printf("Nome: ");
    limparBuffer();
    fgets(agenda[*total].nome, 50, stdin);
    agenda[*total].nome[strcspn(agenda[*total].nome, "\n")] = 0; // Remove o \n final
    
    printf("Telefone: ");
    fgets(agenda[*total].telefone, 20, stdin);
    agenda[*total].telefone[strcspn(agenda[*total].telefone, "\n")] = 0;
    
    printf("E-mail: ");
    fgets(agenda[*total].email, 50, stdin);
    agenda[*total].email[strcspn(agenda[*total].email, "\n")] = 0;
    
    (*total)++; // Passagem por referência para atualizar o total na main
    printf("Contato cadastrado com sucesso!\n");
}

void listarContatos(Contato *agenda, int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    
    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < total; i++) {
        printf("[%d] Nome: %s | Tel: %s | E-mail: %s\n", i, agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
}

void buscarContato(Contato *agenda, int total) {
    char termo[50];
    int encontrou = 0;
    
    printf("Digite o nome para busca: ");
    limparBuffer();
    fgets(termo, 50, stdin);
    termo[strcspn(termo, "\n")] = 0;
    
    printf("\n--- Resultados ---\n");
    for (int i = 0; i < total; i++) {
        // strstr busca uma substring dentro de outra string (case-sensitive)
        if (strstr(agenda[i].nome, termo) != NULL) {
            printf("[%d] %s - %s - %s\n", i, agenda[i].nome, agenda[i].telefone, agenda[i].email);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum contato encontrado.\n");
}

void editarContato(Contato *agenda, int total) {
    int indice;
    listarContatos(agenda, total);
    
    if (total == 0) return;
    
    printf("Digite o numero do indice que deseja editar: ");
    scanf("%d", &indice);
    
    if (indice >= 0 && indice < total) {
        printf("Novo Nome: ");
        limparBuffer();
        fgets(agenda[indice].nome, 50, stdin);
        agenda[indice].nome[strcspn(agenda[indice].nome, "\n")] = 0;
        
        printf("Novo Telefone: ");
        fgets(agenda[indice].telefone, 20, stdin);
        agenda[indice].telefone[strcspn(agenda[indice].telefone, "\n")] = 0;
        
        printf("Novo E-mail: ");
        fgets(agenda[indice].email, 50, stdin);
        agenda[indice].email[strcspn(agenda[indice].email, "\n")] = 0;
        
        printf("Contato atualizado!\n");
    } else {
        printf("Indice invalido!\n");
    }
}

void excluirContato(Contato *agenda, int *total) {
    int indice;
    listarContatos(agenda, *total);
    
    if (*total == 0) return;
    
    printf("Digite o numero do indice que deseja excluir: ");
    scanf("%d", &indice);
    
    if (indice >= 0 && indice < *total) {
        // Desloca os contatos para preencher o espaço vazio
        for (int i = indice; i < (*total) - 1; i++) {
            agenda[i] = agenda[i + 1];
        }
        (*total)--;
        printf("Contato excluido!\n");
    } else {
        printf("Indice invalido!\n");
    }
}

// Função Recursiva: Conta quantos contatos têm um domínio de email específico
int contarDominioRecursivo(Contato *agenda, int total, int indice, char *dominio) {
    // Caso base: chegou ao final do array
    if (indice == total) {
        return 0;
    }
    
    // Verifica se o domínio está presente no email atual
    int temDominio = (strstr(agenda[indice].email, dominio) != NULL) ? 1 : 0;
    
    // Chamada recursiva para o próximo índice
    return temDominio + contarDominioRecursivo(agenda, total, indice + 1, dominio);
}
// --- PERSISTÊNCIA EM ARQUIVO TEXTO ---

void salvarContatos(Contato *agenda, int total) {
    FILE *arquivo = fopen("contatos.txt", "w"); // "w" abre para escrita (write)
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de contatos!\n");
        return;
    }
    
    // Salva no formato: Nome;Telefone;E-mail
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%s;%s;%s\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
    
    fclose(arquivo);
    printf("Contatos salvos no disco com sucesso!\n");
}

void carregarContatos(Contato *agenda, int *total) {
    FILE *arquivo = fopen("contatos.txt", "r"); // "r" abre para leitura (read)
    if (arquivo == NULL) {
        // É normal falhar na primeira vez se o arquivo "contatos.txt" ainda não existir
        return; 
    }
    
    *total = 0;
    char linha[150];
    
    // Lê linha por linha até o fim do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL && *total < MAX_CONTATOS) {
        linha[strcspn(linha, "\n")] = 0; // Remove o \n
        
        // strtok divide a string toda vez que encontra um ";"
        char *token = strtok(linha, ";");
        if (token != NULL) strcpy(agenda[*total].nome, token);
        
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(agenda[*total].telefone, token);
        
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(agenda[*total].email, token);
        
        (*total)++;
    }
    
    fclose(arquivo);
    printf("Dados carregados! %d contato(s) na memoria.\n", *total);
}