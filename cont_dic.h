int contida_dici (char *a){
int i;
char palavra[30];
FILE *dicionario;

dicionario = fopen("dicio.txt", "r");
while ((fgets (palavra, 30, dicionario)) != NULL){
	for (i=0; i < cad_tamanho(palavra) ; i++)
		if (palavra[i] == '\n') palavra[i] = '\0';
	if (cad_comparar(palavra, a) == 0) return 1;
}

fclose (dicionario);
return 0;
}
