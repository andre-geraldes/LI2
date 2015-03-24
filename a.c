#include <stdio.h>
#include "cadeias.h"

int main () {

    char a[2][30];
    char *s1;
    s1 = "Ola";
    cad_copiar(a[0], s1);
    a[0][0] = '\0';
    puts(a[0]);
    return 0;
}

