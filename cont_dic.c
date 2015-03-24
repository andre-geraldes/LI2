int contida_dici (char *a){
int i;
char palavra[30];
FILE *dicionario;

dicionario = fopen("wordlist.txt", "r");
while ((fgets (palavra, 30, dicionario)) != NULL){
	for (i=0; i < tamanho(palavra) ; i++)
		if (palavra[i] == '\n') palavra[i] = '\0';
	if (compara(palavra, a)) return 1;
}

fclose (dicionario);
return 0;
}
