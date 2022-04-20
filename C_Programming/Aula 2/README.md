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

## Exemplo utilizando o tipo float

```c
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
```

Ao executar o código acima utilizando o compilador TCC, temos:

```
$ tcc -run tipo-float.c

1.23 - 8 bytes (double)       :2.22507e-308 ... 1.79769e+308  
1.23f - 4 bytes (float)       :1.17549e-38 ... 3.40282e+38    
23.0l - 16 bytes (long double) :3.3621e-4932 ... 1.18973e+4932
```

Note que ao deixarmos explicito os valores como sendo double, float e long double, temos os tamanhos dobrados e a precisão cada vez maior.


# O tipo double(ponto flutuante com precisão dupla)

* Como foi dito acima, o tipo double tem dupla precisão e ocupa cerca de 8 bytes na memória.

## Vejamos um exemplo utilizando o tipo double:

```c
/******************************************************
Precisão dos tipos reais...
******************************************************/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    
    printf("\nPrecisão do tipo 'float'      : %d\n", FLT_DIG);
    printf("Precisão do tipo 'double'     : %d\n", DBL_DIG);
    printf("Precisão do tipo 'long double': %d\n\n", LDBL_DIG);


    puts("               0     6       15 18");
    puts("               |.....|........|..|");
    printf("5.0f / 3.0f = %.20f\n", 5.0f / 3.0f);
    printf("5.0 / 3.0   = %.20f\n", 5.0 / 3.0);
    printf("5.0l / 3.0l = %.21Lg\n\n", 5.0l / 3.0l);
    
    return 0;
}
```

Ao executar o programa com o compilador TCC, teremos:

```
$ tcc -run tipo-double.c

Precisão do tipo 'float'      : 6   
Precisão do tipo 'double'     : 15  
Precisão do tipo 'long double': 18  

               0     6       15 18  
               |.....|........|..|  
5.0f / 3.0f = 1.66666662693023681641
5.0 / 3.0   = 1.66666666666666674068
5.0l / 3.0l = 1.66666666666666666663
```

Note que temos a precisão que varia de 6 a 18 casas decimais.


## Exemplo geral sobre os tipos

```c
/******************************************************
Determinando o tamanho e a faixa dos tipos...
******************************************************/

#include <stdio.h>
#include <limits.h> // Precisamos das constantes dos limites
#include <float.h>  // Limites dos tipos float e double

int main() {
    
    printf(
        "%-19s %s %25s %s\n\n"

        "(signed) int        %3ld   %25d %d\n"
        "unsigned int        %3ld   %25d %u\n"
        "(signed) short int  %3ld   %25d %d\n"
        "unsigned short int  %3ld   %25d %d\n"
        "(signed) long int   %3ld   %25ld %ld\n"
        "unsigned long int   %3ld   %25d %lu\n\n"
        
        "(signed) char       %3ld   %25d %d\n"
        "unsigned char       %3ld   %25d %d\n\n"
        
        "float               %3ld   %25e %e\n"
        "double              %3ld   %25e %e\n"
        "long double         %3ld   %25Le %Le\n\n",
        
        "TIPO", "BYTES", "MIN", "MAX",
        
        sizeof(int), INT_MIN, INT_MAX,
        sizeof(unsigned int), 0, UINT_MAX,
        sizeof(short int), SHRT_MIN, SHRT_MAX,
        sizeof(unsigned short int), 0, USHRT_MAX,
        sizeof(long int), LONG_MIN, LONG_MAX,
        sizeof(unsigned long int), 0, ULONG_MAX,
        
        sizeof(char), CHAR_MIN, CHAR_MAX,
        sizeof(unsigned char), 0, UCHAR_MAX,
        
        sizeof(float), FLT_MIN, FLT_MAX,
        sizeof(double), DBL_MIN, DBL_MAX,
        sizeof(long double), LDBL_MIN, LDBL_MAX
    );

    return 0;
}
```

Usando o compilador TCC e executando, temos:

```
$ tcc -run limites.c

TIPO                BYTES                       MIN MAX

(signed) int          4                 -2147483648 2147483647
unsigned int          4                           0 4294967295
(signed) short int    2                      -32768 32767
unsigned short int    2                           0 65535
(signed) long int     8        -9223372036854775808 9223372036854775807 
unsigned long int     8                           0 18446744073709551615

(signed) char         1                        -128 127
unsigned char         1                           0 255

float                 4                1.175494e-38 3.402823e+38
double                8               2.225074e-308 1.797693e+308
long double          16              3.362103e-4932 1.189731e+4932
```

# O tipo booleano

* Na linguagem C, qualquer valor inteiro diferente de zero é considerado verdadeiro.

* A declaração de uma variável do tipo '_Bool' faz com que valores verdadeiros sejam "traduzidos" para o valor 1 e os falsos para o valor 0, ambos com 1 byte de tamanho.

* Fazendo uso do cabeçalho 'stdbool.h' podemos escrever constantes booleanas como 'tru' e 'false', ambas com 4 bytes de tamanho.

* Além disso, o cabeçalho 'stdbool.h' fornece um 'alias' para a palavra-chave '_Bool': 'bool'.

## Exemplo de código utilizando o tipo bool

```c
/******************************************************
Tipo booleano...
******************************************************/
#include <stdio.h>
#include <stdbool.h>

int main() {
    
    bool a = 123;
    bool b = 0;
    
    printf("Tamanho do tipo 'bool': %lu bytes\n\n", sizeof(bool));
    
    printf("O valor de 'a' é: %d (%lu bytes)\n", a, sizeof(a));
    printf("O valor de 'b' é: %d (%lu bytes)\n\n", b, sizeof(b));
    
    printf("Tamanho de 'true' : %lu\n", sizeof(true));
    printf("Tamanho de 'false': %lu\n\n", sizeof(false));
        
    return 0;
}
```

Executando com o compilador TCC, temos:

```
$ tcc -run tipo-bool.c

Tamanho do tipo 'bool': 1 bytes

O valor de 'a' é: 1 (1 bytes)
O valor de 'b' é: 0 (1 bytes)

Tamanho de 'true' : 4
Tamanho de 'false': 4
```

Note que temos true e false pesando 4 bytes cada um, isso se deve porque eles são valores inteiros.

Além disso, qualquer valor diferente de 0 é considerado verdadeiro, como dito acima.