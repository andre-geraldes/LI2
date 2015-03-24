#include <stdio.h>
#include <stdlib.h>

/**Função que recebe uma sopa de letras a e um array b de coordenadas e escreve em s os caracteres das coordenadas.*/
void descobrir(char **a, int b[], int N, char s[]){
int i, j = 0;
int tam = N/2;
int e, d;

for (i=0; i < tam; i++){
	e = b[j]-1;
	d = b[j+1]-1;
	s[i] = a[e][d];
	if (i != N-2) j += 2;
	}
	s[i] = '\0';
}


int main () {

int nl, nc, nl1, n, i = 0, j, *coord, k;
char palavra[100];
char *linha, **sopa;

k = scanf("%d %d", &nl, &nc);
nl1 = nl;
linha = (char *) malloc(nc * sizeof(char));

/**Memoria da matriz:*/
sopa = (char **) malloc(nl * sizeof(char*));
for(j=0; j < nl; j++)
    sopa[j] = (char *) malloc(nc*sizeof(char));

/**Guardar cada linha inserida, na matriz:*/
while(nl1 > 0){
	k = scanf("%s", linha);
	for (j=0; j < nc; j++)
		sopa[i][j] = linha[j];
	nl1--;
	i++;
	}

/**Tratamento das coordenadas*/
k = scanf("%d", &n);
coord = malloc(n*2*sizeof(int));
for(i = 0; i < n*2; i++)
	k = scanf("%d", &coord[i]);
	
descobrir(sopa, coord, n*2, palavra);

printf("String: %s\n", palavra);

if (k) {};
return 0;
}
