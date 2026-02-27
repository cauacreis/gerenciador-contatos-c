#include <stdio.h>
#include "contatos.h"

int main() {
    Contato agenda[MAX_CONTATOS]; 
    int totalContatos = 0;
    int opcao;

    // 1. CARREGA OS DADOS SALVOS ASSIM QUE O PROGRAMA ABRE
    carregarContatos(agenda, &totalContatos);
    do {
        printf("\n=== GERENCIADOR DE CONTATOS ===\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Buscar por nome\n");
        printf("4. Editar\n");
        printf("5. Excluir\n");
        printf("6. Estatisticas (Recursiva)\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarContato(agenda, &totalContatos);
                break;
            case 2:
                listarContatos(agenda, totalContatos);
                break;
            case 3:
                buscarContato(agenda, totalContatos);
                break;
            case 4:
                editarContato(agenda, totalContatos);
                break;
            case 5:
                excluirContato(agenda, &totalContatos);
                break;
            case 6: {
                char dominio[20];
                printf("Digite o dominio de email para contar (ex: @gmail.com): ");
                scanf("%s", dominio);
                int quantidade = contarDominioRecursivo(agenda, totalContatos, 0, dominio);
                printf("Existem %d contato(s) com o dominio '%s'.\n", quantidade, dominio);
                break;
            }
            case 7:
                // Agora sim ele salva os dados no arquivo contatos.txt antes de fechar!
                salvarContatos(agenda, totalContatos); 
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}