#include <stdio.h>
#include <stdlib.h>

#define MILHA 1.609

int main(int argc, char *argv[]) {
    
    float ml = atof(argv[1]);
    float km = ml * MILHA;

    printf("%.2fml = %.2fkm\n", ml, km);

    return 0;
}