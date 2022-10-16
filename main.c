#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/tad_dicionario.h"

int main() {
    tipo_dicionario dicionario;

    int loop; loop = 1;
    int option;
    char letra_desejada;
    char nome_arquivo[256];

    printf("Nome do arquivo: "); 
    scanf("%s", nome_arquivo);

    while (loop) {
        printf("\n-------------------- DICIONÁRIO DE AEDS --------------------\n");
        printf("Opções do dicionário:\n");
        printf("1. Construir o dicionário do texto\n"); // Constrói o dicionário
        printf("2. Exibir lista de palavras de determinada letra\n"); // Exibe a lista de palavras de uma determinada letra
        printf("3. Exibir toda a lista de palavras do texto\n"); // Exibe toda a lista de palavras do texto
        printf("4. Sair do programa\n"); // Encerrta o programa
        printf("--------------------------------------------------------------\n");
        printf("Opção desejada: ");
        scanf("%d", &option);
        system("cls || clear");
        // Implementação do menu de operações do programa
        switch (option) {
            case 1 :
                constroi_dicionario(&dicionario, nome_arquivo);
                break;
            case 2 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                imprime_dicionario_letra(&dicionario, letra_desejada);
                break;
            case 3 :
                imprime_dicionario_completo(&dicionario);
                break;
            case 4 :
                loop = 0;
                break;
            default :
                printf("Erro: opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}