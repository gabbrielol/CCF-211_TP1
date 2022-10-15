#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_lista_palavra.h"

// Declarando célula para dicionário
typedef struct celula_dicionario *apontador_dicionario;
typedef struct tipo_celula_dicionario {
    tipo_lista_palavras *lista_dicionario;
    apontador_dicionario p_prox_dicio;
} tipo_celula_dicionario;

// Declarando célula para 
typedef struct {
    apontador_dicionario primeiro_dicio;
    apontador_dicionario ultimo_dicio;
} tipo_dicionario;

void incializa_dicionario(tipo_dicionario *dicionario);