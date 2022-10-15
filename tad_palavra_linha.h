#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarando a célula para linha
typedef struct celula_linha *apontador_linha;
typedef struct celula_linha {
    int num_linha;
    apontador_linha p_prox_linha;
} tipo_celula_linha;

// Declarando a lista de linhas
typedef struct {
    apontador_linha primeiro_linha;
    apontador_linha ultimo_linha;
    int aux_linha;
} tipo_lista_linha;

// Função para inicizalizar uma lista encadeada de linhas vazia
void inicializa_lista_linha(tipo_lista_linha *lista_linha);

// Função para verificar se a lista de linhas está vazia
void verifica_lista_linha(tipo_lista_linha *lista_linha);

// Função para verificar se a lista de linhas está vazia
void insere_linha(tipo_lista_linha *lista_linha, int linha);

// Função para imprimir a lista de linhas
void imprime_linha(tipo_lista_linha *lista_linha);