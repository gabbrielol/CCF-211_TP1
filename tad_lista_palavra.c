#include "tad_lista_palavra.h"

void inicializa_lista_palavra_vazia(tipo_lista_palavra *lista_palavra) {
    lista_palavra -> primeiro_lista = (apontador_lista) malloc(sizeof(tipo_celula_lista));
    lista_palavra -> ultimo_lista = lista_palavra -> primeiro_lista;
    lista_palavra -> primeiro_lista -> p_prox_lista = NULL;
}

void insere_nova_palavra(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra) {
    lista_palavra -> ultimo_lista -> p_prox_lista = (apontador_lista) malloc(sizeof(tipo_celula_lista));
    lista_palavra -> ultimo_lista = lista_palavra -> ultimo_lista -> p_prox_lista;
    lista_palavra -> ultimo_lista -> item_palavra = *palavra;
    lista_palavra -> ultimo_lista -> p_prox_lista = NULL;
}

void remove_palavra_final(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra) {
    tipo_celula_lista *aux_ultimo;
    tipo_celula_lista *aux_novo_ultimo;
    if (lista_palavra -> primeiro_lista == lista_palavra -> ultimo_lista) {
        printf("Lista vazia!\n");
    }
    else {
        aux_ultimo = lista_palavra -> primeiro_lista -> p_prox_lista;
        aux_novo_ultimo = lista_palavra -> primeiro_lista;
        while (aux_ultimo -> p_prox_lista != NULL) {
            aux_novo_ultimo = aux_novo_ultimo -> p_prox_lista;
            aux_ultimo = aux_ultimo -> p_prox_lista;
        }
        aux_novo_ultimo -> p_prox_lista = aux_ultimo -> p_prox_lista;
        free(aux_ultimo);
        printf("A última palavra da lista de palavra foi removida com sucesso!\n");
    }
}
void remove_palavra_info(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra, char *palavra_remover) {
    tipo_celula_lista *verifica_celula;
    tipo_celula_lista *p_aux;
    tipo_celula_lista *p_remover;
    verifica_celula = lista_palavra -> primeiro_lista;
    while ((verifica_celula -> p_prox_lista != NULL) && (verifica_celula -> p_prox_lista -> item_palavra.cadeia_caracteres != palavra -> cadeia_caracteres)) {
        verifica_celula = verifica_celula -> p_prox_lista;
    }
    p_aux = lista_palavra -> primeiro_lista;
    while (p_aux -> p_prox_lista != NULL) {
        if (!strcmp(p_aux -> p_prox_lista -> item_palavra.cadeia_caracteres, palavra_remover)) {
            p_remover = p_aux -> p_prox_lista;
            p_aux -> p_prox_lista = p_aux -> p_prox_lista -> p_prox_lista;
            free(p_remover);
            if (p_aux -> p_prox_lista == NULL) {
                break;
            }
        }
        p_aux = p_aux -> p_prox_lista;
    }
}

void verifica_palavra(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra, char *palavra_verifica) {
    tipo_celula_lista *p_aux;
    int pos = 0, cont = 0;
    p_aux = lista_palavra -> primeiro_lista -> p_prox_lista;
    while (p_aux != NULL) {
        pos++;
        if (!strcmp(p_aux -> item_palavra.cadeia_caracteres, palavra_verifica)) {
            printf("O elemento <%s> está na %d posicao da lista!\n", palavra_verifica, pos);
            cont++;
        }
        p_aux = p_aux -> p_prox_lista;
    }
    if (cont == 0) {
        printf("O elemento <%s> não está na lista!\n", palavra_verifica);
    }
}

int verifica_palavra_insere(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra, char *palavra_verifica) {
    tipo_celula_lista *p_aux;
    int cont;
    cont = 0;
    p_aux = lista_palavra -> primeiro_lista -> p_prox_lista;
    while (p_aux != NULL) {
        if (!strcmp(p_aux -> item_palavra.cadeia_caracteres, palavra_verifica)) {
            cont++;
            return 1;
        }
        p_aux = p_aux -> p_prox_lista;
    }
    if (cont == 0) {
        return 0;
    }
}

int retorna_numero_palavra(tipo_lista_palavra *lista_palavra, tipo_numero_palavras *numero_palavras) {
    numero_palavras -> num_palavras = 0;
    apontador_lista p_aux;
    p_aux = lista_palavra -> primeiro_lista -> p_prox_lista;
    while (p_aux != NULL) {
        numero_palavras -> num_palavras++;
        p_aux = p_aux -> p_prox_lista;
    }
    return numero_palavras -> num_palavras;
}

void imprime_lista_palavra(tipo_lista_palavra* lista_palavra) {
    apontador_lista p_aux;
    p_aux = lista_palavra -> primeiro_lista -> p_prox_lista;
    if (lista_palavra -> primeiro_lista == lista_palavra -> ultimo_lista) {
        printf("Lista vazia! Nada para mostrar!\n");
    }
    while (p_aux != NULL){
        printf("%s\n", p_aux -> item_palavra.cadeia_caracteres);
        p_aux = p_aux -> p_prox_lista;
    }
}