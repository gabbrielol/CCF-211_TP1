#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_max_cadeia 100 // Define tamanho máximo para a cadeia de caracteres

// Declarando a célula para linha
typedef struct celula_linha *apontador_linha;
typedef struct celula_linha {
    int num_linha;
    apontador_linha p_prox_linha;
} tipo_celula_linha;

// Declarando a lista de linhas
typedef struct lista_linha {
    apontador_linha primeiro_linha;
    apontador_linha ultimo_linha;
} tipo_lista_linha;

// Declarando o tipo palavra, que contém uma cadeia de caracteres e
// uma lista encadeada de linhas, em que os elementos são inteiros que indicam
// as linhas em que a palavra apareceu
typedef struct palavra {
    tipo_lista_linha *lista_linha;
    char cadeia_caracteres[tam_max_cadeia];
} tipo_palavra;


// Função para inicizalizar uma palavra
void inicializa_palavra_vazia(tipo_palavra *palavra);

// Função para inicizalizar lista encadeada de linhas vazia
void inicializa_lista_linha_palavra_vazia(tipo_palavra *palavra);

// Função para preencher a cadeia de caracteres a partir de palavras
// que serão retiradas do texto (SET)
void preenche_cadeia_caracteres(tipo_palavra *palavra, char *palavra_texto);

// Função para inserir as linhas em que uma palavra aparece
void insere_linha_palavra(tipo_palavra *palavra, int linha);

// Função para retornar a cadeia de caracteres (GET)
char *retorna_cadeia_caracteres(tipo_palavra *palavra);

// Função para imprimir a cadeia de caracteres
void imprime_cadeia_caracteres(tipo_palavra *palavra);

// Função para imprimir palavra, ou seja a cadeia de caracteres e
// as linhas em que a palavra apareceu
void imprime_palavra(tipo_palavra *palavra);