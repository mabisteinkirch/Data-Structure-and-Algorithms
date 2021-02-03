#include <stdio.h>

int main(){

    int x = 25; 
    int y = &x; //recebe o endereço onde está a variável x
    *y = 30;
    printf("Valor atual de x: %i \n", x);
    return 0;
}