#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadeias.h"
#include "tarefa3.h"
#include <ctype.h>

char **a, string[30], ficheiro[50]; /**Variavel a é onde fica guardada a sopa de letras*/
int nc = 0, nl = 0, n = 0, tipo = 1, *coord, pontos = 0; /**Variaveis nc e nl sao numero de colunas e linhas respetivamente, n é o numero de pares de coordenadas inseridas, tipo serve para o menu, *coord é o array onde sao guardadas as coordenadas */

/**Função que converte uma string para minusculas*/
char *tomin(char a[]){
    int i;
    for(i=0; a[i] != '\0'; i++)
        a[i] = tolower(a[i]);
    a[i] = '\0';
    return a;
}

/**Função que retira de uma sopa de letras a palavra nas coordenadas recebidas*/
void descobrir(char **a, int b[]){
int i, j = 0;
int e, d;

for (i=0; i < n; i++){
	e = b[j]-1;
	d = b[j+1]-1;
	string[i] = a[e][d];
	if (i != n-1) j += 2;
	}
	string[i] = '\0';
}

/**Função que le um ficheiro e guarda a sopa de letras numa matriz*/
void guardaSopa (){
	int i=0,j=0, fl = 1;
	char letra[250], *p;
	FILE *grelha;

	grelha = fopen(ficheiro, "r");

	while ((fgets (letra, 250, grelha)) != NULL){
        if (isdigit(letra[0]) && fl){
            p = strtok(letra, " ");
            nl = atoi(p);
            while (p != NULL){
                nc = atoi(p);
                p = strtok(NULL, " ");
            }
            fl = 0;
            /**Memoria da matriz:*/
            a = (char **) malloc(nl * sizeof(char*));
            for(j=0; j < nl; j++)
                a[j] = (char *) malloc(nc*sizeof(char)); 
        }
        else { 
        for(j=0; j < nc && letra[j] != '\n'; j++){
            a[i][j] = letra[j];
        }
        i++;
        }
	}
    
	fclose (grelha);
}

/**Função que verifica se as coordenadas respeitam o movimento de serpente*/
int verificaSerpente(int a[], int N){
    int i, conta = 0;
    
    for (i=0; i < N; i++) /** Ciclo for que serve para converter as coordenadas, ex input de 1 1 corresponde a 0 0 */
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
    for (i=0; i < nl; i++){
        printf(" ");;
		for (j=0; j < nc; j++){
			printf("%c  ", a[i][j]);
	    }
	printf("\n");
	}
    printf("\n");
}

/**Função que verifica se as coordenadas dadas são válidas*/
int verificaCoord(int a[], int N){
    int i, j;

    for (i=0; i <= N - 2; i += 2)
        for(j=0 ; j <= N - 2; j += 2)
            if(j != i && a[i] == a[j] && a[i+1] == a[j+1]) return 0;

    for(i=0; i < N - 1; i++)
        if (a[i] > nl || a[i] < 0 || a[i+1] > nc || a[i+1] < 0) {
            return 0;   
        }
    return 1;
}

/**Função que pede ao utilizador as coordenadas e as guarda num array*/
void pedeCoord(){
    int i, x;
    puts("Quantos pares de coordenadas?");
    x = scanf("%d", &n);
    coord = malloc(n*2*sizeof(int));
    puts("");
    puts("Insira as coordenadas:");
    for(i=0; i < n*2; i++)
        x = scanf("%d", &coord[i]);
    
    while (!verificaCoord(coord, n*2)){
            puts("Coordenadas inválidas! Por favor insira coordenadas válidas!");
            for(i=0; i < n*2; i++)
                x = scanf("%d", &coord[i]);
            }
    puts("");
    if(x){}; /**Utilização da variavel x para tratar de warnings do scanf*/
}

/**Função que funciona como menu*/
void opcoes(){
    int x;
    puts("Qual o tipo de movimento?");
    puts("1 - Serpente");
    puts("2 - Cavalo");
    puts("3 - Sair");
    puts("");
    x = scanf("%d", &tipo);
    while (tipo != 1 && tipo != 2 && tipo != 3) {
        puts("Movimento inválido, tente outra vez.");
        x = scanf("%d", &tipo);
    }   
    if (x){};
}

/**Função que trata da opção escolhida pelo utilizador*/
void trataOpcoes(){
    switch(tipo){
    case 1:{
               pedeCoord();
               descobrir(a, coord);
               printf("Palavra inserida: %s \n\n", string);
               tomin(string);
               
               if (verificaSerpente(coord, n*2) && palavra_existe(dici[string[0] - 'a'], string)){
                   puts("Palavra válida! Ganhou 10 pontos!");
                   pontos += 10;
                   printf("\nPontuação: %d\n", pontos);
               }
                   else {
                       puts("Palavra inválida! Perdeu 5 pontos!");
                       pontos -= 5;
                       printf("\nPontuação: %d\n", pontos);
                   }
               printf("\nEnter para continuar.\n");
               while (getchar() != '\n');
               while (getchar() != '\n');
           }
        break;
    case 2:{
               pedeCoord();
               descobrir(a, coord);
               printf("Palavra inserida: %s \n\n", string);
               tomin(string);
               
               if (verificaCavalo(coord, n*2) && palavra_existe(dici[string[0] - 'a'], string)){
                   puts("Palavra válida! Ganhou 10 pontos!");
                   pontos += 10;
                   printf("\nPontuação: %d\n", pontos);
               }
                   else {
                       puts("Palavra inválida! Perdeu 5 pontos!");
                       pontos -= 5;
                       printf("\nPontuação: %d\n", pontos);
                   }
               printf("\nEnter para continuar.\n");
               while (getchar() != '\n');
               while (getchar() != '\n');
           }
        break;
    case 3: break;
    default: break;
    }
}

int main () {
    int r, i;
    puts("Insira o nome do ficheiro que contém a sopa");
    r = scanf("%s", ficheiro);
    puts("A carregar dicionário...");
    printf("A ler %s...\n", ficheiro);

    /**Ler sopa de um ficheiro e carregar dicionario*/
	guardaSopa();
    guardaDici();
 
    /**Saudação inicial*/
    r = system("clear");
    puts("\nBem vindo ao jogo da sopa de letras.");
    puts("\nPontuações:");
    puts("10 pontos por palavra válida");
    puts("-5 pontos por palavra inválida");
    puts("");
    puts("Boa sorte!");
    puts("");

	imprimeSopa();

    puts("");

    /**Escolher tipo de movimento*/
    while (tipo != 3){
        opcoes();
        trataOpcoes();
        puts("");
        r = system("clear");
        if (tipo != 3){
            printf("Pontuação atual: %d pontos\n\n", pontos);
            imprimeSopa();
        }
    }

    if (r){}; /**Problemas com warnings*/
    
    printf("Pontuação final: %d pontos\n", pontos);
    puts("\nObrigado por jogar!\n");

    /**Libertar memória*/
    free(coord);
    for(i=0; i < nl; i++)
        free(a[i]);
    free(a);

    return 0;
}
