/* 
    Constante caractere
*/
#include <stdio.h>

int main() {

    char c = 78;
    char d = 'N';

    printf("O caractere '%c' tem valor %d\n", 'A', 'A');
    printf("O caractere '%c' tem valor %d\n", 77, 77);
    printf("O caractere '%c' tem valor %d\n\n", '9', '9');

    puts("Espaço na memória...\n");

    // O compilador irá entender que o valor 78 da variável c representa o caractere 'N' na tabel ASCII.
    printf("A variável c tem o caractere '%c' com valor %d: %lu bytes \n", c, c, sizeof(c));
    printf("A variável d tem o caractere '%c' com valor %d: %lu bytes \n", d, d, sizeof(d));
    printf(
            // A constante 'N' é um inteiro, por isso ocupa 4 bytes.
            "\nMas a constante '%c' ocupa %lu bytes, \n"
            "exatamente como a constante %d: %lu bytes\n\n", 'N', sizeof('N'), 78, sizeof(78)
            );

    return 0;
}