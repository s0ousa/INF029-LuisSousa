#include <stdio.h>

int ler3Numeros () {
    int vetor[3];
    
    for(int i = 0; i<3; i++) {
        printf("Digite o %i valor \n", i+1);
        scanf("%i", &vetor[i]);
    }
    
   // return(vetor); nao funciona!!! , tirar duvida com o prof dpss
}


int main()
{   
    ler3Numeros();
    
    return 0;
}