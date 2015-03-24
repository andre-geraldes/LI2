#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadeias.h"
#include "tarefa3.h"
#include <ctype.h>

char *palSopa[30], **a, string[30]; /**Variavel a é onde fica guardada a sopa de letras*/
int k = 0, nc = 0, nl = 0, n = 0, tipo = 1, *coord, pontos = 0; /**Variavel k serve de indice para as palavras guardadas do movimento tradicional, nc e nl sao numero de colunas e linhas respetivamente, n é o numero de pares de coordenadas inseridas. */

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
	char letra[20], *p;
	FILE *grelha;

	grelha = fopen("t30.in", "r");

	while ((fgets (letra, 20, grelha)) != NULL){
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

/**Função que verifica se uma palavra b existe num array bidimensional*/
int repetida(char *a[], char b[]){
    int i;
    for (i=0; i < k; i++)
        if (cad_comparar(a[i], b) == 0) return 1;
    return 0;
}


/**Função que retira da sopa todas as palavras válidas no método tradicional*/
void retiraPalavrasTrad (char **sopa){
    int i=0, j=0, i1 = 0, j1 = 0, x=0, l = nl, c = nc;
    char buff[30];

    for(i=0; i < l; i++){
        for(j=0; j < c; j++){

        /*Retirar direcção N*/
            x=0;
            for(i1 = i; i1 >= 0; i1--){
                buff[x++] = sopa[i1][j];
                buff[x] = '\0';
                tomin(buff);
                
                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
                }
            buff[0] = '\0';
        
        /*Retirar direcção S*/
            x=0;
            for(i1=i; i1 < l; i1++){
                buff[x++] = sopa[i1][j];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        
        /*Retirar direcção O*/    
            x=0;
            for(j1=j; j1 >= 0; j1--){
                buff[x++] = sopa[i][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        /*Retirar direcção E*/
            x=0;
            for(j1=j; j1 < c; j1++){
                buff[x++] = sopa[i][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        /*Retirar direcção SE*/
            x=0;
            for(j1=j, i1 = i; j1 < c && i1 < l; j1++, i1++){
                buff[x++] = sopa[i1][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        /*Retirar direcção NE*/
            x=0;
            for(j1=j, i1 = i; j1 < c && i1 >=0; j1++, i1--){
                buff[x++] = sopa[i1][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        /*Retirar direcção NO*/
            x=0;
            for(j1=j, i1 = i; j1 >= 0 && i1 >= 0; j1--, i1--){
                buff[x++] = sopa[i1][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        /*Retirar direcção SO*/
            x=0;
            for(j1=j, i1 = i; j1 >= 0 && i1 < l; j1--, i1++){
                buff[x++] = sopa[i1][j1];
                buff[x] = '\0';
                tomin(buff);

                if (palavra_existe(dici[buff[0] - 'a'], buff) && !repetida(palSopa, buff)){
                    palSopa[k] = malloc(cad_tamanho(buff));
                    cad_copiar(palSopa[k++], buff);
                }
            }
        }
    }
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
			printf("%c ", a[i][j]);
	    }
	printf("\n");
	}
}

/**Função que verifica se as coordenadas dadas são válidas*/
int verificaCoord(int a[], int N){
    int i;
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
    puts("1 - Tradicional");
    puts("2 - Serpente");
    puts("3 - Cavalo");
    puts("4 - Sair");
    puts("");
    x = scanf("%d", &tipo);
    while (tipo != 1 && tipo != 2 && tipo != 3 && tipo != 4) {
        puts("Movimento inválido, tente outra vez.");
        x = scanf("%d", &tipo);
    }   
    if (x){};
}

/**Função que trata da opção escolhida pelo utilizador*/
void trataOpcoes(){
    switch(tipo){
    case 1: {
                retiraPalavrasTrad(a); 
                pedeCoord();
                descobrir(a, coord);
                printf("Palavra inserida: %s \n\n", string);
                tomin(string);
                if (repetida(palSopa, string)) {
                    puts("Palavra válida! Ganhou 10 pontos!");
                    pontos += 10;
                    printf("\nPontuação: %d\n", pontos);
                }
                    else {
                        puts("Palavra inválida! Perdeu 5 pontos!\n");
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
    case 3:{
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
    case 4: break;
    default: break;
    }
}

int main () {
    int r;
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

    /**Imprimir sopa*/
	imprimeSopa();

    puts("");

    /**Escolher tipo de movimento*/
    while (tipo != 4){
        opcoes();
        trataOpcoes();
        puts("");
        r = system("clear");
        if (tipo != 4){
            printf("Pontuação atual: %d pontos\n", pontos);
            imprimeSopa();
        }
        puts("");
    }

    if (r){}; /**Problemas com warnings*/

    printf("Pontuação final: %d pontos\n", pontos);
    puts("\nObrigado por jogar!\n");
    return 0;
}
