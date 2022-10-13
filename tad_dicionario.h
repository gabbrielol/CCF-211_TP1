#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_lista_palavra.h"

typedef struct dicionario {
    int dicionario_num;
} tipo_dicionario;

void inicializa_dicionario_vazio(tipo_dicionario *dicionario);