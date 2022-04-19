# Fundamentos da linguagem C
A linguagem C é uma linguagem:
* Compilada
    * Diferentemente de linguagens interpretadas, a linguagem C por ser compilada, o código é transformado em código de máquina("binário") e que gera um executável.
    * Basicamente um arquivo binário é escrito na forma de uma imagem exata de como o conteúdo seria carregado na memória do computador.
* De proposito geral
* Estruturada
* Imperativa
    * Basicamente representa instruções e comandos que o computador deve executar.
* Procedual
    * São procedimentos passo a passo que o computador deve seguir.
* De alto nível
* De tipagem estática
    * O tipo da variável é definido durante o tempo de compilação do programa.
* Eficiente
* Flexível
* Poderosa
* Integrada a sistemas "Unix-like"

# GCC 
Nesse tutorial iremos utilizar o compilador GCC que basicamente é um conjunto de outros compiladores.
Para compilar o nosso código em C, fazemos uso da seguinte instrução:
```bash
$ gcc -Wall <nome_arquivo.c> -o <destino> 
```
Exemplo
```bash
$ gcc -Wall hello_world.c -o hello_world
```
No exemplo acima, após a execução do comando o compilador GCC irá compilar o nosso arquivo nome_arquivo.c e gerar o arquivo binário(código de máquina) que irá se chamar hello_world.exe(que basicamente é o nosso destino). A respeito do -Wall fazemos uso desse parâmetro para exibir todos os erros e avisos.
<br>
Para executar o nosso código binário, basta fazer a seguinte instrução:
```bash
$ ./hello_world.exe
```
O hello_world.exe é o nosso arquivo compilado.

# Tipos de dados
A linguagem C fornece tipos "primitivos", "modificados" e "definidos pelo usuário". Sendo eles:

* Primitivos
    * int    - valores números do tipo inteiro
    * char   - caracteres do tipo (ASCII)
    * float  - números de ponto flutuante(decimais)
    * double - números de dupla precisão(decimais)
    * void   - tipo sem valor(vazio)

* Modificados
    * a respeito do tamanho - short e long
    * a respeito do sinal   - signed e unsigned

* Tipos definidos a partir dos tipos primitivos
    * arrays  - coleção de dados do mesmo tipo
    * strings - coleção/arrays de caracteres

* Tipos definidos pelo usuário
    * Estruturas e uniões
    * Enumerações

# Variáveis e Constantes
Na linguagem C, uma constante é um valor imutável, ou seja, não pode ser alterado. Já uma variável é um valor mutável, ou seja, pode ser alterado. Alguns exemplos de constantes são:

* Constantes
    * Representações literais de um valor
    * Constantes simbólicas
    * Arrays
    * Ponteiros
    * Estruturas
    * Uniões
    * Enumerações

* Variáveis
    * São identificadores para dados na memória do computador.
    * Precisam ser declarados.

* Identificadores
    * Contém apenas caracteres alfanuméricos e o '_'.
    * O primeiro caractere deve ser obrigatoriamente uma letra ou '_'.
    * Não pode ser uma palavra-chave.

# Operadores
Na linguagem C temos os seguintes operadores:

* Operadores de atribuição
* Operadores aritméticos
* Operadores relacionais
* Operadores lógicos
* Operadores condicionais

Além disso, há outros operadores do tipo:
* *var     - Basicamente aponta para uma variável(indireção).
* &var     - Retorna o endereço da memória de uma variável.
* sizeof() - Retorna o tamanho de uma variável.

# Instruções
As instruções na linguagem C terminam com um ponto e vírgula ';'. Em alguns casos não utilizamos ponto e vírgula, são eles:

* Funções
* Estruturas condicionais
* Estruturas de repetição
* Diretivas do pré-processador

Estruturas que tem seus blocos delimitados por chaves e precisam de ponto e vírgula:

* Funções
* Estruturas de decisão
* Estruturas de repetição
* A definição de um array
* A definição de uma estrutura(struct)
* A definição de uma união
* A definição de uma enumeração

# Funções

* Uma função é um bloco de instruções que tem como objetivo realizar uma tarefa específica.

* Todo programa em C consiste de uma ou mais funções, tendo a função main() como a principal.

* Todo programa em C é executado dentro da função main().

* A linguagem C dispõe de várias bibliotecas contendo funções e outras definições para as mais diversas finalidades.

* Os cabeçalhos são arquivos terminados com a extensão .h, para utilizarmos no nosso código devemos fazer uso da diretiva do pré-processador para incluir dentro do nosso código, vejamos:
```c
#include <nome_arquivo.h>
```

* Além disso, nós como usuários podemos criar nossas próprias funções. 

# Diretivas do pré-processador

* Antes da compilação do nosso arquivo, o compilador faz uma leitura de todo o código em busca de instruções adicionais.

* Essas instruções não fazem parte da linguagem C, apenas incluimos em nossos programas.

* As diretivas mais comuins são:
    * Diretiva #include
        * Basicamente inclui um arquivo externo, nesse caso fazemos uso para incluir cabeçalhos e utilizar funções do cabeçalho em nossos programas.
    
    * Diretiva #define
        * Basicamente define "macros", entre os quais, as constantes simbólicas que poderão ser utilizadas em qualquer parte do código.

# Estrutura de decisão

* Cláusulas if/else
    * Podem ou não ter um agrupamento de instruções.

    * Sem o agrupamento teremos apenas uma instrução.

* Cláusulas switch/case
    * É uma instrução multidirecional para lidar com decisões.
    
    * Basicamente atua comparando o valor de uma expressão com as constantes nas cláusulas 'case'.

    * Cada instrução nas cláusulas 'case' serão executadas até que seja encontrado uma instrução 'break'.

# Estrutura de repetição

* Loop while
    * Executa uma ou mais instruções enquanto dada condição for verdadeira.

    * A condição é testada antes do próximo ciclo.

* Loop do/while
    * Executa ao menos uma vez(sem testar a condição), após a primeira execução é testado a condição até que a mesma seja verdadeira.

* Loop for
    * Executa um grupo de instruções de forma controlada por três outras expressões.

    * Dado um valor inicial e uma condição, executa um ciclo de instruções, opera a terceira expressão e faz uma nova avaliação da condição para decidir se haverá outro ciclo.

Exemplo de loop for:
```c
for (int i = 0; i <= 5, i++) {
    // bloco de código
}
```

Note que temos um inicializador(int i = 0), uma condição(i <= 5) e um incrementador/decrementador(i++).


# Programas simples em C

Exemplo de código bem sucedido:
```c
int main() {
    // programa bem sucedido
    return 0;
}
```

Exemplo de programa onde apresenta erro:
```c
int main() {
    // programa mal sucedido
    return 1;
}
```

# Escrevendo um hello world!

Para imprimir um hello, world! na tela iremos fazer uso da biblioteca <stdio.h> juntamente com a diretiva de pré-processamento #include para incluir o cabeçalho stdio.h.

````c
// Inclui a biblioteca de input/output
#include <stdio.h>

int main() {
    // A função puts() imprime Hello, world! na tela.
    puts("Hello, world!");

    // Retorna 0(true) caso a execução seja bem sucedida.
    return 0;
}
```