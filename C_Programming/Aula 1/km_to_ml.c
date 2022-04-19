#include <stdio.h>
#include <stdlib.h>

// Constante simbólica
#define MILHA 0.6213

int main(int argc, char *argv[]) {

    // A função atof(array to float) converte um array do tipo string para o tipo float.
    float km = atof(argv[1]);
    float ml = km * MILHA;

    // Após passar o valor(km) pelo terminal, teremos o resultado impresso.
    printf("%.2fkm = %.2f milhas\n", km, ml);


    return 0;
}