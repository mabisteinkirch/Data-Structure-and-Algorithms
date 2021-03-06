typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
} NO;

typedef struct tree{
    NO *pont;
} Tree;