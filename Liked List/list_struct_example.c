#define MAX 50 //definição do tamanho máximo que a estrutura vai ter

//deixar evidente que é uma chave do tipo INT, não um int qualquer
typedef int TIPOCHAVE; 

//colocar aqui todos os campos necessários para a resolução do problema
typedef struct {
    TIPOCHAVE chave;
    //outros campos
}REGISTRO;

typedef struct {
    REGISTRO A[MAX]; //arranjo do registro com um tamanho pré-definido
    int nroElem; //quantidade de elementos existentes
} LISTA;