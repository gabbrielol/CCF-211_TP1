#include "tad_lista_palavra.h"

void inicializa_lista_palavras(tipo_lista_palavras *lista_palavras) {
    lista_palavras -> lista -> primeiro_lista = (apontador_lista) malloc(sizeof(tipo_celula_lista));
    lista_palavras -> lista -> ultimo_lista = lista_palavras -> lista -> primeiro_lista;
    lista_palavras -> lista -> ultimo_lista -> p_prox_lista = NULL;
}

void verifica_lista_palavras(tipo_lista_palavras *lista_palavras) {
    if (lista_palavras -> lista -> primeiro_lista == lista_palavras -> lista -> ultimo_lista) {
        printf("Lista de palavras vazia!\n");
    }
}

void insere_nova_palavra(tipo_lista_palavras *lista_palavras, tipo_palavra *palavra, int linha) {
    insere_linha(palavra -> lista_linha, linha);
    lista_palavras -> lista -> ultimo_lista -> p_prox_lista = (apontador_lista) malloc(sizeof(tipo_celula_lista));
    lista_palavras -> lista -> ultimo_lista = lista_palavras -> lista -> ultimo_lista -> p_prox_lista;
    lista_palavras -> lista -> ultimo_lista -> item_palavra = *palavra;
    lista_palavras -> lista -> ultimo_lista -> p_prox_lista = NULL;
}

void remove_palavra_informada(tipo_lista_palavras *lista_palavras, char *palavra_remover) {
    apontador_lista aux;
    apontador_lista aux_remover;
    verifica_lista_palavras(lista_palavras);
    aux = lista_palavras -> lista -> primeiro_lista; // JEITO DE FILHA DA PUTA
    while (aux -> p_prox_lista != NULL) {
        if (!strcmp(aux -> p_prox_lista -> item_palavra.cadeia_caracteres, palavra_remover)) {
            aux_remover = aux -> p_prox_lista;
            aux -> p_prox_lista = aux -> p_prox_lista -> p_prox_lista;
            free(aux_remover);
            if (aux -> p_prox_lista == NULL) {
                break;
            }
        }
        aux = aux -> p_prox_lista;
    }
}

void remove_palavra_final(tipo_lista_palavras *lista_palavras) {
    apontador_lista aux_ultimo;
    apontador_lista aux_novo_ultimo;
    verifica_lista_palavras(lista_palavras);
    aux_ultimo = lista_palavras -> lista -> primeiro_lista -> p_prox_lista;
    aux_novo_ultimo = lista_palavras -> lista -> primeiro_lista;
    while (aux_novo_ultimo != NULL) {
        aux_ultimo = aux_ultimo -> p_prox_lista;
        aux_novo_ultimo = aux_novo_ultimo -> p_prox_lista;
    }
    aux_novo_ultimo -> p_prox_lista = aux_ultimo -> p_prox_lista;
    free(aux_ultimo);
}

int retorna_numero_palavras(tipo_lista_palavras *lista_palavras) {
    apontador_lista aux_percorre;
    aux_percorre = lista_palavras -> lista -> primeiro_lista -> p_prox_lista;
    verifica_lista_palavras(lista_palavras);
    while (aux_percorre != NULL) {
        lista_palavras -> num_palavras++;
        aux_percorre = aux_percorre -> p_prox_lista;
    }
    return lista_palavras -> num_palavras;
}

int verifica_pertencimento_lista_palavras(tipo_lista_palavras *lista_palavras, char *palavra_verifica) {
    apontador_lista aux_percorre;
    aux_percorre = lista_palavras -> lista -> primeiro_lista -> p_prox_lista;
    while (aux_percorre != NULL) {
        if (!strcmp(aux_percorre -> item_palavra.cadeia_caracteres , palavra_verifica)) {
            return 1;
        }
        aux_percorre = aux_percorre -> p_prox_lista;
    }
    return 0;
}

void imprime_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_palavra *palavra) {
    apontador_lista aux_percorre;
    aux_percorre = lista_palavras -> lista -> primeiro_lista -> p_prox_lista;
    while (aux_percorre != NULL) {
        imprime_palavra(palavra);
    }
    aux_percorre = aux_percorre -> p_prox_lista;
}