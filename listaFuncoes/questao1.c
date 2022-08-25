#include <stdio.h>

int soma(int a, int b) {
    return a+b;
}

int main()
{
    int valor1,valor2;
    
    printf("Digite dois valores a serem somados \n");
    scanf("%i %i", &valor1, &valor2);
    
    printf("%i", soma(valor1,valor2));

    return 0;
}