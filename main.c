#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

int main() {
    // Declaração de variáveis, definidas em cada TAD,
    // que serão utilizadas ao longo do programa
    tipo_palavra palavra; // Tipo palavra, contém a palavra
    tipo_lista_palavras lista_palavras; // Tipo lista de palavras, contém a lista de palavras
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
    char palavra_desejada[tam_max_cadeia]; // Variável utilizada no menu para inserir uma palavra no final da lista de palavras;

    // Inicializa uma lista de palavras vazia
    inicializa_lista_palavras(&lista_palavras);

    // Processo de abertura do arquivo
    FILE *file;
    file = NULL;
    printf("Nome do arquivo que deseja abrir: ");
    scanf("%s", nome_arquivo); // Recebendo o nome do arquivo
    file = fopen(nome_arquivo, "r"); // Abrindo o arquivo em mode de leitura
    if (file == NULL) { // Verificando se a abertura do arquivo foi feita corretamente
        printf("Erro na abertura no arquivo!\n");
    }
    while (!feof(file)) {
        fscanf(file, "%s%c", palavra_texto, &caractere_texto);
        strcpy(palavra_verifica, palavra_texto);
        if (verifica_pertencimento_lista_palavras(&lista_palavras, palavra_verifica) == 0) {
            inicializa_palavra_vazia(&palavra);
            preenche_cadeia_caracteres(&palavra, palavra_texto);
            //insere_linha_palavra(&lista_palavras, &palavra, palavra_texto, linha); NÃO FUNCIONA
            insere_nova_palavra(&lista_palavras, &palavra);
            printf("Nova palavra, nova linha // %s\n", retorna_cadeia_caracteres(&palavra));

        }
        else {
            //insere_linha_palavra(&lista_palavras, &palavra, palavra_texto, linha); NÃO FUNCIONA
            printf("Nova palavra, nova linha // %s\n", retorna_cadeia_caracteres(&palavra));
        }
        if (caractere_texto == '\n') {
            linha++;
        }
    }
    imprime_lista_palavras(&lista_palavras);
    return 0;
}