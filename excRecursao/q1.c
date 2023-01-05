#include <stdio.h>

int fatorial (int n) {
    
    if (n==0) {
        return 1;
    } else {
        return fatorial(n-1)*n;
    }
}

void main() {
    printf("Digite um num p calcular seu fatorial \n");
    int num; 
    scanf("%i", &num);
    printf("%i \n", fatorial(num));
}