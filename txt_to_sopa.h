char *grelha (int l, int c, char a[l][c]){
int i=0,j=0;
char letra[20], *p;
FILE *grelha;

grelha = fopen("grelha.txt", "r");

while ((fgets (letra, 20, grelha)) != NULL){
	p = strtok(letra," ");
	j = 0;
		while (p!=NULL){
			a[i][j] = *p;
			p = strtok(NULL, " ");
			j++;
			}
	i++;
	}

fclose (grelha);
return *a;
}
