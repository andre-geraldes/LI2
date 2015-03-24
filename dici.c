#include <stdio.h>
#include <string.h>
#define MAXSTR 25
#define MAXPAL 100000
 
int existe(char dic[MAXPAL][MAXSTR], int numpal, char pal[MAXSTR]) {
        int encontrou=0, res, liminf = 0, limsup = numpal-1, meio;
        
		return encontrou;
}
 
int main() {
        char dicionario[MAXPAL][MAXSTR]; char palavra[MAXSTR];
        int linha = 0;
        FILE *d;
        d = fopen("dicio.txt", "r");
        if (d!=NULL) {
                while (fgets(dicionario[linha], MAXSTR, d) != NULL) {
                        dicionario[linha][strlen(dicionario[linha])-1] = '\0';
                        linha += 1;
                }
                fclose(d);
                printf("Dicionário em memória!\n");
                printf("Diga palavras:\n");
                while (fgets(palavra, MAXSTR, stdin) != NULL) {
                        palavra[strlen(palavra)-1] = '\0';
                        if (existe(dicionario, linha, palavra)) {
                                printf("%s existe\n", palavra);
                        } else {
                                printf("%s NÃO existe\n", palavra);
                        }
                }
        } else {
                printf("Sem dicionário, não brinco\n");
        }
        return 0;
}
