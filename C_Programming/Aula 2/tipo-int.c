/* 
    Trabalhando com constantes inteiras.
*/
#include <stdio.h>
#include <limits.h>

void printInfo();

int main() {
    // Nota: INT_MIN, INT_MAX e por ai vai, são constantes simbólicas(macros).

    // Valores para o int "normal"
    printf("23    - %lu bytes: %d ... %d\n", sizeof(23), INT_MIN, INT_MAX);
    // Valores para o int sem sinal
    printf("23u   - %lu bytes: %u ... %u\n", sizeof(23u), 0, UINT_MAX);
    // Valores para o long int
    printf("23l   - %lu bytes: %ld ... %ld\n", sizeof(23l), LONG_MIN, LONG_MAX);
    // Valores para o long int sem sinal.
    printf("23ul  - %lu bytes: %u ... %lu\n", sizeof(23ul), 0, ULONG_MAX);

    printf("\nLiteral: %lu - %lu bytes\n", 922, sizeof(922));
    printInfo();

    return 0;
}

void printInfo() {
    // Imprime o resultado do programa acima.
    puts("Apenas um rascunho do que o programa na função main faz.");
    puts("23    - 4 bytes: -2147483648 ... 2147483647");
    puts("23u   - 4 bytes: 0 ... 4294967295");
    puts("23l   - 8 bytes: -9223372036854775808 ... 9223372036854775807");
    puts("23ul  - 8 bytes: 0 ... 18446744073709551615");
    puts("Literal: 922 - 4 bytes");
}