#include <stdio.h>
#include "cadeias.h"

int main () {
    char s1[1000];
    char s2[1000];
    char tmp[1000];
    int k;

    puts("Insira duas strings:");
    k = scanf ("%s" , s1);
    k = scanf ("%s" , s2);
    
    printf("Tamanho de s1: %d Tamanho de s2: %d\n", cad_tamanho(s1), cad_tamanho(s2));

    if (cad_e_prefixo(s1, s2)) puts("s1 é prefixo de s2");
    else puts("s1 não é prefixo de s2");

    if (cad_e_sufixo(s1, s2)) puts("s1 é sufixo de s2");
    else puts("s1 não é sufixo de s2");
    
    if (cad_procurar_str(s1, s2) != -1) printf("s1 encontra-se contida em s2, no indice: %d\n", cad_procurar_str(s1, s2));
    
    if (cad_iguais(s1, s2)) puts("s1 e s2 são iguais");
    else puts("s1 e s2 são diferentes");

    if (cad_primeiro(s1,s2)) puts("s1 é menor que s2 alfabeticamente");
    else puts("s1 é maior que s2 alfabeticamente");

    if (cad_um_dos(s1,s2) != -1) printf("s1 contém no indice %d um caractere de s2\n", cad_um_dos(s1,s2));
    else puts("s1 não contém nenhum caractere de s2");
    
    puts("Cópia de s2 para s1:");
    cad_copiar(tmp, s1);
    cad_copiar(s1, s2);
    printf("s1: %s s2: %s\n", s1, s2);

    cad_copiar(s1, tmp);

    puts("Função que cola s2 no fim de s1:");
    cad_colar(s1, s2);
    printf("s1: %s s2: %s\n", s1, s2);

    if (k){};
    return 0;
}
