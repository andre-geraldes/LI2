#include <stdio.h>
#include <stdlib.h>
#include "cadeias.h"
#include "tarefa3.h"

int numpal = 0; /** Variavel numpal serve como contador do número de palavras guardadas na estrutura */

/** Função que adiciona uma palavra a estrutura */
DICIONARIO *addPalavra (DICIONARIO *dic, char palav[]){
    if (dic == NULL){
        dic = (DICIONARIO*) malloc(sizeof(struct dic));
        cad_copiar(dic->palavra, palav);
        numpal++;
        dic->esq = NULL;
        dic->dir = NULL;
    }
    else if (cad_comparar(palav, dic->palavra) < 0)
        dic->esq = addPalavra(dic->esq, palav);
    else dic->dir = addPalavra(dic->dir, palav);

    return dic;
}

/** Função que verifica se uma dada palavra existe no dicionário */
int palavra_existe(DICIONARIO *dic, char palav[]){
    if (palav[0] >= '0' && palav[0] <= '9') return 0;
    if (dic == NULL) return 0;
    if (cad_comparar(palav, dic->palavra) == 0) return 1;
    else if (cad_comparar(palav, dic->palavra) < 0)
        return palavra_existe(dic->esq, palav);
    else return palavra_existe(dic->dir, palav);
    return 0;
}


/** Função que le o dicionário do dicio.txt e o guarda na estrutura de dados*/
void guardaDici(){
    FILE * dicio;
    char linha[40];
    int i;

    for (i=0; i<27; i++)
        dici[i] = NULL;

    dicio = fopen("dicio.txt", "r");
    
    while (fgets(linha, 40, dicio) != NULL){
      
        for (i=0; linha[i] != '\n'; i++);
        linha[i] = '\0';
      
        dici[linha[0] - 'a'] = addPalavra(dici[linha[0] - 'a'], linha);
    }
    printf("Foram guardadas %d palavras.\n", numpal);
    fclose(dicio);
}

