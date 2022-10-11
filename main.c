#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

int main() {
    tipo_lista_linha lista_linha;
    tipo_palavra palavra, item_palavra;
    tipo_lista_palavra lista_palavra;

    char palavra_texto[tam_max_cadeia];
    char palavra_remover[tam_max_cadeia];
    char palavra_verifica[tam_max_cadeia];
    int linhas;

    inicializa_palavra_vazia(&palavra);
    inicializa_lista_palavra_vazia(&lista_palavra);

    for (int i = 0; i < 5; i++) {
        printf("Digite uma palavra:\n");
        scanf("%s", palavra_texto);
        preenche_cadeia_caracteres(&palavra, palavra_texto);
        insere_nova_palavra(&lista_palavra, &palavra);
    }
    
    imprime_lista_palavra(&lista_palavra);
    remove_palavra_final(&lista_palavra, &palavra);
    imprime_lista_palavra(&lista_palavra);
    printf("Número de palavras:\n");
    printf("%d\n", retorna_numero_palavra(&lista_palavra));
    printf("Palavra que deseja remover:\n");
    scanf("%s", palavra_remover);
    remove_palavra_info(&lista_palavra, &palavra, palavra_remover);
    imprime_lista_palavra(&lista_palavra);
    printf("Palavra que deseja verificar:\n");
    while (scanf("%s", palavra_verifica) != EOF) {
        verifica_palavra(&lista_palavra, &palavra, palavra_verifica);
    }

    return 0;
}
