#include <stdio.h>
#include <stdlib.h>
#include "cadeias.h"
#include "tarefa3.h"

int num = 0;

int main (){
    int k;
    char s1[30];

    guardaDici();

    while (cad_comparar(s1, "0")){
        puts("Qual a palavra em minusculas? (0 para sair)");
        k = scanf("%s", s1);
        if (cad_comparar(s1, "0") && palavra_existe(dici[s1[0] - 'a'], s1)) puts("Existe no dicionário!");
        else if (cad_comparar(s1, "0")) puts("Não existe no dicionário!");
        puts("");
    }

    if (k) {};
    return 0;
}
