#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_palavra.h"

// Declarando célula para palavras
typedef struct celula_lista *apontador_lista;
typedef struct celula_lista {
    tipo_palavra item_palavra;
    apontador_lista p_prox_lista;
} tipo_celula_lista;

// Declarando lista de palavras
typedef struct lista_palavra {
    apontador_lista primeiro_lista;
    apontador_lista ultimo_lista;
} tipo_lista_palavra;

// Função para inicializar uma lista de palavras vazia
void inicializa_lista_palavra_vazia(tipo_lista_palavra *lista_palavra);

// Função para inserir uma nova palavra na lista de palavras
void insere_nova_palavra(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra);

// Função para remover uma palavra do final da lista de palavras
void remove_palavra_final(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra);

// Função para remover uma palavra específica da lista de palavras
void remove_palavra_info(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra, char *palavra_remover);

// Função para verficar se uma palavra específica está na lista de palavras
void verifica_palavra(tipo_lista_palavra *lista_palavra, tipo_palavra *palavra, char *palavra_verifica);

// Função para contar o número de palavras e retornar o número de palavras
int retorna_numero_palavra(tipo_lista_palavra *lista_palavra);

// Função para imprimir toda a lista de palavras
void imprime_lista_palavra(tipo_lista_palavra *lista_palavra);