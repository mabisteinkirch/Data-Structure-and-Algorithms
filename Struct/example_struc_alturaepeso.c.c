#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct{
    int peso;
    int altura;
} PesoAltura;

in main(){

    PesoAltura *pessoal = (PesoAltura*) malloc (sizeof (PesoAltura));
    pessoal->peso = 80;
    pessoal->altura = 185;

}