#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadeias.h"
#include "tarefa3.h"
#include <ctype.h>

char *palSopa[30], **a, string[30]; /**Variavel a é onde fica guardada a sopa de letras*/
int ind=0, nc = 0, nl = 0, n = 0, tipo = 1, *coord[50]; /**Variaveis nc e nl sao numero de colunas e linhas respetivamente, n é o numero de pares de coordenadas inseridas, tipo serve para o menu, *coord é o array onde sao guardadas as coordenadas */

/**Função que converte uma string para minusculas*/
char *tomin(char a[]){
    int i;
    for(i=0; a[i] != '\0'; i++)
        a[i] = tolower(a[i]);
    a[i] = '\0';
    return a;
}

/**Função que le um ficheiro e guarda a sopa de letras numa matriz*/
void guardaSopa (){
	int i=0,j=0, fl = 1;
	char letra[250], *p;
	FILE *grelha;

	grelha = fopen("t01.in", "r");

	while ((fgets (letra, 250, grelha)) != NULL){
        if (isdigit(letra[0]) && fl){
            p = strtok(letra, " ");
            nc = atoi(p);
            while (p != NULL){
                nl = atoi(p);
                p = strtok(NULL, " ");
            }
            fl = 0;
            /**Memoria da matriz:*/
            a = (char **) malloc(nl * sizeof(char*));
            for(j=0; j < nl; j++)
                a[j] = (char *) malloc(nc*sizeof(char)); 
        }
        else { 
        for(j=0; j < nc && letra[j] != '\n'; j++)
            a[i][j] = letra[j];
        i++;
        }
	}
    
	fclose (grelha);
}


void retiraSerpente(){
    int i, j;
    for (i=1; i <= nl; i++){
        for (j = 0; j < nc; j++){
            coord[ind] = malloc(sizeof(int));
            coord[ind][0] = i;
            coord[ind++][1] = j+1;
        }
    }
    
    for (i=0; i < nl; i++){
        for (j=0; j < nc; j++){
        
        }
    }

}


void retiraCavalo(){


}


/**Função que verifica se as coordenadas respeitam o movimento de serpente*/
int verificaSerpente(int a[], int N){
    int i, conta = 0;
    
    for (i=0; i < N; i++)
        a[i] = a[i] - 1;

    for (i=0; i < N - 2; i += 2){
        if ( ((a[i] + 1) == a[i+2]) && (a[i+1] == a[i+3])) 
            conta += 2;
        else if (((a[i] - 1) == a[i+2]) && (a[i+1] == a[i+3]))
            conta += 2;
        else if (((a[i+1] + 1) == a[i+3]) && (a[i] == a[i+2]))
            conta += 2;
        else if (((a[i+1] - 1) == a[i+3]) && (a[i] == a[i+2]))
            conta += 2;
        else if ( ((a[i] + 1) == a[i+2]) && ((a[i+1] + 1) == a[i+3]))
            conta += 2;
        else if  ( ((a[i] + 1) == a[i+2]) && ((a[i+1] - 1) == a[i+3])) 
            conta += 2;
        else if  ( ((a[i] - 1) == a[i+2]) && ((a[i+1] + 1) == a[i+3]))
            conta += 2;
        else if ( ((a[i] - 1) == a[i+2]) && ((a[i+1] - 1) == a[i+3]))
            conta += 2;
        else return 0;
    }
    if (conta == N - 2) return 1;
        else return 0;
}

/**Função que verifica se as coordenadas respeitam o movimento de cavalo*/
int verificaCavalo(int a[], int N){
    int i, conta = 0;

    for (i=0; i < N; i++)
        a[i] = a[i] - 1;

    for (i=0; i < N - 2; i += 2){
        if ( ((a[i] + 2) == a[i+2]) && ((a[i+1] - 1) == a[i+3])) 
            conta += 2;
        else if (((a[i] + 2) == a[i+2]) && ((a[i+1] + 1) == a[i+3]))
            conta += 2;
        else if (((a[i] - 2) == a[i+2]) && ((a[i+1] - 1) == a[i+3]))
            conta += 2;
        else if (((a[i] - 2) == a[i+2]) && ((a[i+1] + 1) == a[i+3]))
            conta += 2;
        else if ( ((a[i] + 1) == a[i+2]) && ((a[i+1] + 2) == a[i+3]))
            conta += 2;
        else if  ( ((a[i] + 1) == a[i+2]) && ((a[i+1] - 2) == a[i+3])) 
            conta += 2;
        else if  ( ((a[i] - 1) == a[i+2]) && ((a[i+1] + 2) == a[i+3]))
            conta += 2;
        else if ( ((a[i] - 1) == a[i+2]) && ((a[i+1] - 2) == a[i+3]))
            conta += 2;
        else return 0;
    }
    if (conta == N - 2) return 1;
        else return 0;
}

/**Função que imprime a sopa de letras*/
void imprimeSopa(){
    int i, j;
    for (i=0; i<nc; i++){
        printf(" ");;
		for (j=0; j<nl; j++){
			printf("%c  ", a[i][j]);
	    }
	printf("\n");
	}
}

int main () {
    int r, i;
    /**Ler sopa de um ficheiro e carregar dicionario*/
	guardaSopa();
    guardaDici();
    
    retiraSerpente();
    /**Escolher tipo de movimento*/
    /*while (tipo != 3){
        opcoes();
        trataOpcoes();
        puts("");
        r = system("clear");
        if (tipo != 3){
            imprimeSopa();
        }
        puts("");
    }*/

    if (r){}; /**Problemas com warnings*/

    /**Libertar memória*/
    for(i=0; i < nl; i++)
        free(a[i]);
    free(a);

    return 0;
}
