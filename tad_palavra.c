#include "tad_palavra.h"

void inicializa_palavra_vazia(tipo_palavra *palavra) {
    palavra = (tipo_palavra*) malloc(sizeof(tipo_palavra));
}

void inicializa_lista_linha_palavra_vazia(tipo_palavra *palavra) {
    palavra -> lista_linha = (tipo_lista_linha*) malloc(sizeof(tipo_lista_linha));
    palavra -> lista_linha -> primeiro_linha = (apontador_linha) malloc(sizeof(tipo_celula_linha));
    palavra -> lista_linha -> ultimo_linha = palavra -> lista_linha -> primeiro_linha;
    palavra -> lista_linha -> primeiro_linha -> p_prox_linha = NULL;
}

void preenche_cadeia_caracteres(tipo_palavra *palavra, char *palavra_texto) {
    strcpy(palavra -> cadeia_caracteres, palavra_texto);
}

void insere_linha_palavra(tipo_palavra *palavra, int linha) {
    palavra -> lista_linha -> ultimo_linha -> p_prox_linha = (apontador_linha) malloc(sizeof(tipo_celula_linha));
    palavra -> lista_linha -> ultimo_linha = palavra -> lista_linha -> ultimo_linha -> p_prox_linha;
    palavra -> lista_linha -> ultimo_linha -> num_linha = linha;
    palavra -> lista_linha -> ultimo_linha -> p_prox_linha = NULL;
}

char *retorna_cadeia_caracteres(tipo_palavra *palavra) {
    return palavra -> cadeia_caracteres;
}

void imprime_cadeira_caracteres(tipo_palavra *palavra) {
    printf("%s\n", retorna_cadeia_caracteres(palavra));
}

/*
void imprime_palavra(tipo_palavra *palavra) {
    printf("%s ", retorna_cadeia_caracteres(palavra));
    tipo_celula_linha *p_aux;
    p_aux = palavra -> lista_linha -> primeiro_linha -> p_prox_linha;
    while (p_aux != NULL) {
        printf("%d ", p_aux -> num_linha);
        p_aux = p_aux -> p_prox_linha;
    }
}
*/