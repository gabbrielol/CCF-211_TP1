#include "tad_palavra.h"

void inicializa_palavra_vazia(tipo_palavra *palavra) {
    palavra = (tipo_palavra*) malloc(sizeof(tipo_palavra));
    palavra -> lista_linha = (tipo_lista_linha*) malloc(sizeof(tipo_lista_linha));
}

void preenche_cadeia_caracteres(tipo_palavra *palavra, char *palavra_texto) {
    strcpy(palavra -> cadeia_caracteres, palavra_texto);
}

char *retorna_cadeia_caracteres(tipo_palavra *palavra) {
    return palavra -> cadeia_caracteres;
}

void imprime_cadeia_caracteres(tipo_palavra *palavra) {
    printf("%s ", retorna_cadeia_caracteres(palavra));
}

void imprime_palavra(tipo_palavra *palavra, tipo_lista_linha *lista_linha) {
    imprime_cadeia_caracteres(palavra);
    imprime_linha(lista_linha);
}