#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    
    TIPOCHAVE chave;
    /*dados armazenados vão aqui*/
    struct aux *esq;
    struct aux *dir;
  
} NO;

typedef NO *PONT; 

/* 
FUNÇÃO AUXILIAR
Busca binária não recursiva
Devolve o ponteiro do nó buscado.
Abastece o pai com o ponteiro para o nó pai deste

*/

//TIPOCHAVE -> busca um nó com uma determinada chave

PONT buscaNo (PONT raiz, TIPOCHAVE ch, PONT *pai){

    PONT atual = raiz; //cria um ponteiro auxiliar para receber a raiz
    *pai = NULL; //pai é NULL pq a raiz está NULL
    
    while(atual){ //enquanto este ponteiro for válido
        if (atual->chave == ch) //se achar, 
            return (atual); //retorna o valor desse nó
        *pai = atual; //guarda em pai o endereço do no pai desse nó que tem a chave
        if (ch < atual->chave) //se a chave for menor
            atual = atual->esq; //vai para a subárvore da esquerda
        else //se a chave for maior
            atual = atual->dir; //vai para a subárvore da direita
    }
    return (NULL); //se visitou tudo e não encontrou, retorna NULL

}

/*Considerações:
- Precisa lidar com as sub árvores
- Conservar ser uma árvore de busca 

*/

//Estratégia: Pegar o nó mais a direita da subárvore da esquerda

PONT removeNo{

    PONT pai, no, p, q; 
    no = buscaNo (raiz, ch, &pai); //pega o endereço do nó que deseja remover através da função de buscarNo

    if (no==NULL) //se o nó buscado for NULL, então o nó não estava lá
        return (raiz); //só retorna a raiz sem ter feito a remoção

    /* A partir daqui é porque encontrou quem gostaria de remover*/

    if (!no->esq || !no->dir){ //verifica se não tem descendente esquerdo ou direito 
        if(!no->esq) //se ele não tem o esquerdo
            q = no->dir; //o nó que vai substituir o nó excluido é o direito
        else //se não tiver o direito
            q = no->esq; //o nó esquerdo vai substituir o nó que será excluido
    }

    else{ //caso tenha descendente dos dois lados
        p= no;
        q = no->esq; //vai na subárvore da esquerda buscando o sub nó mais a direita
        while (q-dir){
            p=q;
            q=q->dir;
        }
        if(p!=no){ 
            p-dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no-dir;
    }

    if (!pai){ //verifica se o nó não é a raiz
        free (no);
        return (q);
    }

    //O pai do nó que for remover, apontar para o nó removido
    if (ch < pai->chave)
        pai->esq = q;
    else
        pai-dir = q;

    free(no);
    return (raiz);    
}

int main() {
  
    PONT p = removeNo(r);
    
    return 0;
}

