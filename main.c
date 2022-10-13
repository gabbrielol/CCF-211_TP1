#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

int main() {
    // Declaração de variáveis, definidas em cada TAD,
    // que serão utilizadas ao longo do programa
    tipo_palavra palavra; // Tipo palavra, contém a palavra
    tipo_lista_palavra lista_palavra; // Tipo lista de palavras, contém a lista de palavras
    tipo_dicionario dicionario; // Tipo dicionário, contém a coleção de listas de palavras em ordem alfabética

    // Declaração de variáveis gerais, que serão utilizadas ao longo do programa
    char nome_arquivo[tam_max_cadeia]; // Variável que recebe o nome do arquivo para processor no prgrama
    char caractere_texto; // Variável que recebe o caractere '\n' contida no texto e auxilia no número da linha
    char palavra_texto[tam_max_cadeia]; // Variável que recebe cada palavra contida no texto
    char palavra_verifica[tam_max_cadeia]; // Variável utilizada no processo de verificar a inserção/pertencimento de uma palavra
    char palavra_remover[tam_max_cadeia]; // Variável utilizada para remover uma determinada palavra do texto
    int linha; linha = 1; // Variável utilizada para contar linhas e auxiliar na identificação da linha
    int loop; loop = 1; // Variável utilizada no menu
    int option; // Variável utilizada no menu
    char letra_desejada; // Variável utilizada no menu para mostrar palavras que iniciam com determinada letra

    // Início do programa com chamada de funções e abertura do arquivo de texto

    // Processo de abertura do arquivo
    FILE *file;
    file = NULL;
    printf("Nome do arquivo que deseja abrir: ");
    scanf("%s", nome_arquivo); // Recebendo o nome do arquivo
    file = fopen(nome_arquivo, "r"); // Abrindo o arquivo em mode de leitura
    if (file == NULL) { // Verificando se a abertura do arquivo foi feita corretamente
        printf("Erro na abertura no arquivo!\n");
    }

    // Chamada de funções essenciais para o prosseguimento do programa
    inicializa_lista_palavra_vazia(&lista_palavra); // Inicia uma lista de palavras vazia
    inicializa_dicionario_vazio(&dicionario); // Inicia um dicionário vazio

    while (loop) {
        printf("\n-------------------- DICIONÁRIO DE TEXTOS --------------------\n");
        printf("Opções do dicionário:\n");
        printf("1. Gerar arquivo dicionário do texto\n");
        printf("2. Exibir lista de palavras do texto\n");
        printf("3. Exibir lista de palavras de determinada letra\n");
        printf("4. Exibir número de palavras únicas do texto\n");
        printf("5. Inserir nova palavra no final da lista de palavras\n");
        printf("6. Remover palavra do final da lista de palavras\n");
        printf("7. Remover palavra específica da lista de palavras\n");
        printf("8. Verificar se uma palavra está na lista de palavras\n");
        printf("9. Sair do programa\n");
        printf("--------------------------------------------------------------\n");
        printf("Opção desejada: ");
        scanf("%d", &option);
        system("cls || clear");
        switch (option) {
        case 1 :
            while (!feof(file)) {
                fscanf(file, "%s%c", palavra_texto, &caractere_texto);
                inicializa_palavra_vazia(&palavra);
                inicializa_lista_linha_palavra_vazia(&palavra);
                preenche_cadeia_caracteres(&palavra, palavra_texto);
                insere_linha_palavra(&palavra, linha);
                strcpy(palavra_verifica, palavra_texto);
                if (verifica_palavra_insere(&lista_palavra, &palavra, palavra_verifica) == 1) {
                    insere_linha_palavra(&palavra, linha);
                }
                else {
                    insere_nova_palavra(&lista_palavra, &palavra);
                }
                if (caractere_texto == '\n') {
                    linha++;
                }
            }
            break;
        case 2 :
            imprime_lista_palavra(&lista_palavra);
            break;
        case 4 :
            printf("%d palavras únicas no texto\n", retorna_numero_palavra(&lista_palavra));
            break;
        case 9 :
            loop = 0;
            break;
        default:
            system("clear");
        }
    }

    return 0;
}