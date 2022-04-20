/*
    Constantes reais
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    printf("1.23 - %lu bytes (double)       :%g ... %g\n", sizeof(1.23), DBL_MIN, DBL_MAX);
    printf("1.23f - %lu bytes (float)       :%g ... %g\n", sizeof(1.23f), FLT_MIN, FLT_MAX);
    printf("23.0l - %lu bytes (long double) :%Lg ... %Lg\n", sizeof(1.23l), LDBL_MIN, LDBL_MAX);

    return 0;
}