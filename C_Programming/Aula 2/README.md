# Tipos primitivos

Como vimos anteriormente, a linguagem C trabalha com 4 tipos primitivos, sendo eles:

* Inteiros(int)
* Números de ponto flutuante(float)
* Números de dupla precisão(double)
* Caracteres(char)

Mas o que eles tem em comum? Simples, todos os tipos são números, incluindo o próprio char.

O tipo caractere(char) pode ser exibido como um caractere da tabela ASCII ou como o seu valor(inteiro) na tabela ASCII. O compilador ver o tipo char como sendo um inteiro de 1 byte.

## Tabela ASCII e seus caracteres representados por números inteiros.
![Tabela ASCII](https://dkrn4sk0rn31v.cloudfront.net/uploads/2020/05/ascii-8bits-v2.png)


# O tipo Inteiro(int)

* O tipo inteiro representa valores positivos e negativos, assim como na matemática.

* O seu tamanho na memória em arquiteturas x84_64 é:
    * 4 bytes

* Limites:
    * MIN: -2147483648
    * MAX:  2147483647

* Constante 'int' (literal):
    * Sâo quaisquer valores do tipo inteiro decimal, octal ou hexadecimal que estão dentro dos limites do tipo int.

    * Não possuem ponto(.) nem expoente(e/E).

    * Está sujeita a "promoção", por exemplo, podemos modificar o tamanho e o sinal do tipo inteiro fazendo uso do long/short ou signed/unsigned. NOTA: Caso utilizemos unsigned long int, teremos o limite(int) dobrado, ou seja, a representação de valores ficarão o dobro.

    * Pode ter uma terminação com letras 'l/L', 'u,U' ou ambas, elas servem para explicitar a faixa de valores.

## Exemplos utilizando o tipo inteiro e os modificadores short/long, signed/unsigned

```c
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

    return 0;
}
```

No exemplo abaixo foi utilizado o compilador TCC.
```bash
$ tcc -run tipo-int.c

23    - 4 bytes: -2147483648 ... 2147483647
23u   - 4 bytes: 0 ... 4294967295
23l   - 8 bytes: -9223372036854775808 ... 9223372036854775807
23ul  - 8 bytes: 0 ... 18446744073709551615

Literal: 922 - 4 bytes
```

# O tipo char(famoso inteiro de 1 byte)

* Caracteres da tabela ASCII.

* O compilador ente um caractere como sendo sempre um inteiro de 1 byte.

* Tamanho na memória (Arquitetura x86_64):
	* 1 byte

* Limites:
	* MIN: -128

	* MAX:  127

* Constante 'char' (literal):
	* Qualquer caractere da tabela ASCII entre aspas simples.
	
	* Uma constante caractere sempre será vista como uma constante inteira e terá o tamanho de 4 bytes.

	* Nesse sentido, qualquer inteiro que esteja na faixa de valores da tabela ASCII pode ser usado para representar uma constante caractere.


## Exemplo utilizando o tipo char e o seu valor inteiro na tabela ASCII

```c
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
```

Ao rodar o programa usando o TCC, temos:

```bash
$ tcc -run tipo-char.c

O caractere 'A' tem valor 65
O caractere 'M' tem valor 77
O caractere '9' tem valor 57

Espaço na memória...

A variável c tem o caractere 'N' com valor 78: 1 bytes 
A variável d tem o caractere 'N' com valor 78: 1 bytes 

Mas a constante 'N' ocupa 4 bytes,
exatamente como a constante 78: 4 bytes
```

O 'N' tem 4 bytes pois ele é basicamente um inteiro.


# O tipo float(números de ponto flutuante)

* Possuem casas decimais que são separadas por ponto.

* Podem ser expressas com a notação de expoente.

* Tamanho na memória (Arquitetura x86_64):
	* 4 bytes

* Limites:
	* MIN: 1.175494e-38

	* MAX: 3.402823e+38

* Constante 'float' (literal):
	* Devem ter ao menos um dígito.

	* Deve ter um ponto decimal.

	* Expoente deve ser seguido de ao menos um dígito.

* Por padrão, as constantes 'float' são identificadas com sendo do tipo 'double'.

* Para especificar que estamos utilizando um 'float', fazemos uso da letra(constante) 'f/F'.

* A terminação 'l/L' fará com que uma constante com ponto flutuante seja reconhecida como do tipo 'long double'.


