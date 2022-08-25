#include <stdio.h>

int subtrai(int a, int b, int c) {
    return a-b-c;
}

int main()
{
    int valor1,valor2,valor3;
    
    printf("Digite três valores a serem subtraidos \n");
    scanf("%i %i %i", &valor1, &valor2,&valor3);
    
    printf("%i", subtrai(valor1,valor2,valor3));

    return 0;
}