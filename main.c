#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

int main() {
    tipo_palavra palavra;
    tipo_numero_palavras num_palavras;
    tipo_lista_palavra lista_palavra;

    char caractere_texto;
    char palavra_texto[tam_max_cadeia];
    char linha_texto[tam_max_cadeia];
    char palavra_remover[tam_max_cadeia];
    char palavra_verifica[tam_max_cadeia];

    int linhas;

    linhas = 1;

    inicializa_lista_palavra_vazia(&lista_palavra);

    FILE *file;

    file = NULL;
    file = fopen("file.txt", "r");

    if (file == NULL) {
        printf("Erro na abertura no arquivo!\n");
    }

    while (!feof(file)) {
        fscanf(file, "%s%c", palavra_texto, &caractere_texto);
        if (caractere_texto == '\n') {
            linhas++;
        }
        strcpy(palavra_verifica, palavra_texto);
        if (verifica_palavra(&lista_palavra, &palavra, palavra_verifica) == 0) {
            inicializa_palavra_vazia(&palavra);
            preenche_cadeia_caracteres(&palavra, palavra_texto);
            insere_nova_palavra(&lista_palavra, &palavra);

        }
        if (verifica_palavra(&lista_palavra, &palavra, palavra_verifica) == 1) {
            insere_pos_linha();
        }
    }

    imprime_lista_palavra(&lista_palavra);
    printf("%d palavras no texto\n", retorna_numero_palavra(&lista_palavra, &num_palavras));

    remove_palavra_final(&lista_palavra, &palavra);
    imprime_lista_palavra(&lista_palavra);
    printf("Palavra que deseja remover:\n");
    scanf("%s", palavra_remover);
    remove_palavra_info(&lista_palavra, &palavra, palavra_remover);
    imprime_lista_palavra(&lista_palavra);
    printf("%d", linhas);
    return 0;
    // teste git_hub
}