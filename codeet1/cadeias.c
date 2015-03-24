/** Função que calcula o tamanho de uma string s.
 */
int cad_tamanho(char s[]){
int i;
for (i=0; s[i] != '\0'; i++); /** Como se trata de strings, o \0 é o fim da string.*/

return i;
}

/** Função que procura um caractere c numa string s e devolve o primeiro indice onde ele se encontra (devolve -1 se nao encontrado).
 */
int cad_procurar_car(char c ,char s[]){
int i, a = 0, ind = 0; /**Variavel a com função de flag*/

for(i=0; s[i] != '\0' && !a; i++){
	if (s[i] == c){			
	a = 1;			/** Ao encontrar a primeira ocorrencia de c*/
	ind = i;		/** coloca "a" a 1 para parar o ciclo e guarda o indice*/
	}
}
if (a) return ind;
	else return -1;
}

/**Função que conta o numero de ocorrências de um caractere c numa string s
 */
int cad_ocorrencias(char c, char s[]){
int i, n = 0;
for (i = 0; i < cad_tamanho(s); i++){
	if (s[i] == c) n++;		/** Sempre que encontra um caractere em s igual a c*/
	}						/** incrementa o contador n*/
return n;	
}

/**Função que verifica se uma string s1 é prefixo de outra string s2
 */
int cad_e_prefixo (char s1[], char s2[]){
int i, n = 0;

for (i=0; i	< cad_tamanho(s1); i++){
	if (s1[i] == s2[i]) n++;	/**Verifica se os primeiros x (tamanho de s1) elementos de s1 são iguais aos de s2, por cada igual, incrementa n*/ 
	}

	if (n == cad_tamanho(s1)) return 1;
		else return 0;
}

/**Função que devolve o primeiro indice em que uma string s1 se encontra dentro de outra string s2
 */
int cad_procurar_str(char s1[], char s2[]){
int i = 0, z = cad_tamanho(s2);

for (i = 0; i < z; i++){
	if (s1[0] == s2[0]) {
		if (cad_e_prefixo(s1,s2)) return i;
	}
	s2++;
}
return -1;
}

/**Função que verifica se uma string s1 é sufixo de outra string s2
 */
int cad_e_sufixo (char s1[], char s2[]){
int i, j, x = 0;
j = cad_tamanho(s1);

for(i=0; i < cad_tamanho(s1); i++)
	if(s1[i] == s2[cad_tamanho(s2) - j]){
	x++;
	j--;
	}
if (x == cad_tamanho(s1)) return 1;
	else return 0;
}

/** Função que veriﬁca se duas strings s1 e s2 são iguais
 */
int cad_iguais (char s1[], char s2[]){
int i, x = 0;

if (cad_tamanho(s1) != cad_tamanho(s2)) return 0;

for(i=0; i < cad_tamanho(s1); i++){
	if (s1[i] == s2[i]) x++;
}

if (x == cad_tamanho(s1)) return 1;
	else return 0;
}

/**Função que veriﬁca se uma string s1 é menor do que uma string s2 em termos alfabeticos
 */
int cad_primeiro ( char s1 [] , char s2 []){
int i;
for(i=0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);

if((s1[i] - s2[i]) < 0) return 1;
return 0;   
}

/**Função que verifica a ordem lexicográfica de duas strings
 * devolve -1, 0 ou 1 se a string s1 for menor, igual ou maior, respetivamente, do que a string s2
 */
int cad_comparar (char s1[],char s2[]){
int i;
for(i=0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);

if ((s1[i]-s2[i]) > 0) return 1;
	else if((s1[i] - s2[i]) < 0) return -1;
return 0;	
}

/**Função que procura o primeiro índice em s1 que contém um dos caracteres na string s2
 */
int cad_um_dos ( char s1 [] , char s2 []){
int i;

for(i=0; i < cad_tamanho(s1); i++)
	if (cad_procurar_car(s1[i], s2) > -1) return cad_procurar_car(s1[i], s1);

return -1;
}

/**Função que procura o primeiro índice em s1 que não contém um dos caracteres na string s2
 */
int cad_nenhum_dos ( char s1 [] , char s2 []){
int i;
 
for(i=0; i < cad_tamanho(s1); i++)
	if (cad_procurar_car(s1[i], s2) == -1) return cad_procurar_car(s1[i], s1);
 
return -1;
}

/**Função que copia para s1 a string s2
 */
int cad_copiar(char s1[] ,char s2[]){
int i;

for(i=0; i < cad_tamanho(s2); i++)
	s1[i] = s2[i];
s1[i] = '\0';

if (cad_iguais(s1, s2)) return 1;

return 0;
}

/**Função que cola s2 ao ﬁm da string s1
 */
int cad_colar ( char s1[] , char s2[]){
int i, j = cad_tamanho(s1);

for (i=0; s2[i] != '\0'; i++){
	s1[j++] = s2[i];
}
s1[j] = '\0';

return 1;
}

/**Função que move n bytes da área m2 para a área m1 (esta função deverá funcionar mesmo que m1 e m2 partilhem memória)
 */
int cad_mover (char m1[], char m2[], int n){
int i;

for(i = 0; i < n; i++)
	m1[i] = m2[i];

return 0;
}
