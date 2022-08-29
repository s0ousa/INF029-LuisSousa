#include <stdio.h>

typedef struct {
  int vetor[4];
}numeros;

numeros ler4Numeros () {

  numeros numerosUsuario;
    
  for(int i = 0; i<4; i++) {
    printf("Digite o %i valor \n", i+1);
    scanf("%i", &numerosUsuario.vetor[i]);
    }
    
  return numerosUsuario;
}


int main()
{   
  numeros numerosEntrada = ler4Numeros();

  for(int j = 0; j<4; j++) {
    printf("%i \n", numerosEntrada.vetor[j]);
  }
    
    return 0;
}