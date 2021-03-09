int tamanhoFila (FILA *fila){

    if (fila->head != NULL){
        ELEMENTO *pointer = fila->head;
        fila->head = pointer->prox;
        return pointer->reg;
    }
}