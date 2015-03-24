#include <stdio.h>
#include "cadeias.h"

int main () {
char s1[1000];
char s2[1000];

scanf ("%s" , s1);
/*scanf ("%s" , s2);*/
printf ("%d\n", cad_tamanho(s1));
/*printf ("%s \n",s1);*/
return 0;
}
