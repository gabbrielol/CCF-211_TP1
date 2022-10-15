#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_palavra.h"

// Declarando célula para palavra
typedef struct celula_lista_palavras *apontador_lista_palavras;
typedef struct celula_lista_palavras {
    tipo_palavra item_palavra;
    apontador_lista_palavras p_prox_lista;
} tipo_celula_lista_palavras;

// Declarando uma lista de palavras
typedef struct {
    apontador_lista_palavras primeiro_lista;
    apontador_lista_palavras ultimo_lista;
    int numero_palavras; // Variável com função de armazenar o número de palavras da lista de palavras
} tipo_lista_palavras;

// Função para inicializar uma lista de palavras vazia
void inicializa_lista_palavras(tipo_lista_palavras *lista_palavras);

// Função para verificar se a lista de palavras está vazia
void verifica_lista_palavras(tipo_lista_palavras *lista_palavras);

// Função para inserir uma nova palavra na lista de palavras
void insere_nova_palavra(tipo_lista_palavras *lista_palavras, tipo_palavra *palavra);

// Função para remover uma palavra específica da lista de palavras
void remove_palavra_informada(tipo_lista_palavras *lista_palavras, char *palavra_remover);

// Função para remover a palavra do final da lista de palavras
void remove_palavra_final(tipo_lista_palavras *lista_palavras);

// Função para contar o número de palavras e retornar o número de palavras
int retorna_numero_palavras(tipo_lista_palavras *lista_palavras);

// Função para contar o número de palavras e retornar o número de palavras
int verifica_pertencimento_lista_palavras(tipo_lista_palavras *lista_palavras, char *char_palavra);

// Função para imprimir toda a lista de palavras
void imprime_lista_palavras(tipo_lista_palavras *lista_palavras);