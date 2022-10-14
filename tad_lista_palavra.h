#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_palavra.h"

// Declarando célula para palavra
typedef struct celula_lista *apontador_lista;
typedef struct celula_lista {
    tipo_palavra item_palavra;
    apontador_lista p_prox_lista;
} tipo_celula_lista;

// Declarando uma lista de palavras
typedef struct {
    apontador_lista primeiro_lista;
    apontador_lista ultimo_lista;
} tipo_lista;

// Declarando uma estrutura para o tipo lista de palavras
// que contém uma lista encadeada com as palavras e o número de palavras
typedef struct {
    tipo_lista *lista;
    int num_palavras;
} tipo_lista_palavras;

// Função para inicializar uma lista de palavras vazia
void inicializa_lista_palavras(tipo_lista_palavras *lista_palavras);

// Função para verificar se a lista de palavras está vazia
void verifica_lista_palavras(tipo_lista_palavras *lista_palavras);

// Função para inserir uma nova palavra na lista de palavras
void insere_nova_palavra(tipo_lista_palavras *lista_palavras, tipo_palavra *palavra, int linha);

// Função para remover uma palavra específica da lista de palavras
void remove_palavra_informada(tipo_lista_palavras *lista_palavras, char *palavra_remover);

// Função para remover a palavra do final da lista de palavras
void remove_palavra_final(tipo_lista_palavras *lista_palavras);

// Função para contar o número de palavras e retornar o número de palavras
int retorna_numero_palavras(tipo_lista_palavras *lista_palavras);

// Função para contar o número de palavras e retornar o número de palavras
int verifica_pertencimento_lista_palavras(tipo_lista_palavras *lista_palavras, char *palavra_verifica);

// Função para imprimir toda a lista de palavras
void imprime_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_palavra *palavra);