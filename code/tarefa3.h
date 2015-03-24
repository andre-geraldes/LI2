typedef struct dic {
    char palavra[30];
    struct dic *esq, *dir;
} DICIONARIO;

DICIONARIO *dici[27];

DICIONARIO *addPalavra(DICIONARIO *dic, char palav[]);

int palavra_existe(DICIONARIO *dic, char palav[]);

void guardaDici();
