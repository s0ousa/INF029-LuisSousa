#include <stdio.h>

int fatorial(int a) {
    
    int fat=1;
    
    if(a<0) {
        printf("Impossivel calcular. \n");
        return(-1);
    }else {
        
        for(int i = a-1;i>0;i--) {
            fat+=fat*i;
        }
    }
        
        
    
    return fat;
}

int main()
{   
    int valor;
    
    printf("Digite um valor para calcular o fatorial \n");
    scanf("%i", &valor);
    
    printf("%i", fatorial(valor));

    return 0;
}