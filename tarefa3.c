#include <stdio.h>
#include "cadeias.h"
#include <stdlib.h>
#include "tarefa3.h"

int numpal = 0;

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

int palavra_existe(DICIONARIO *dic, char palav[]){
    if (dic == NULL) return 0;
    if (cad_comparar(palav, dic->palavra) == 0) return 1;
    else if (cad_comparar(palav, dic->palavra) < 0)
        return palavra_existe(dic->esq, palav);
    else return palavra_existe(dic->dir, palav);
    return 0;
}



void guardaDici(){
    FILE * dicio;
    char linha[40];
    int i, maior = 0;

    for (i=0; i<27; i++)
        dici[i] = NULL;

    dicio = fopen("dicio.txt", "r");
    
    while (fgets(linha, 40, dicio) != NULL){
        if (cad_tamanho(linha) > maior) maior = cad_tamanho(linha);
        for (i=0; linha[i] != '\n'; i++);
        linha[i] = '\0';
      
        dici[linha[0] - 'a'] = addPalavra(dici[linha[0] - 'a'], linha);
    }
    printf("Foram guardadas %d palavras.\n", numpal);
    printf("Tamanho: %d\n", maior);
    fclose(dicio);
}

