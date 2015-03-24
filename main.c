#include <stdio.h>
#include <string.h>
#include "cadeias.h"
#include "txt_to_sopa.h"

int main () {
int i=0, j=0;
char a[5][5];
char *palavra;

grelha(5,5,a);

for (i=0; i<5; i++){
	for (j=0; j<5; j++){
		printf("%c", a[i][j]);
}
printf("\n");
}

return 0;
}
