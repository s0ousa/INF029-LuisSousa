#include <stdio.h>

typedef struct {
  int vetor[3];
}numeros;

numeros ler3Numeros () {

  numeros numerosUsuario;
    
  for(int i = 0; i<3; i++) {
    printf("Digite o %i valor \n", i+1);
    scanf("%i", &numerosUsuario.vetor[i]);
    }
    
  return numerosUsuario;
}


int main()
{   
  numeros numerosEntrada = ler3Numeros();

  for(int j = 0; j<3; j++) {
    printf("%i \n", numerosEntrada.vetor[j]);
  }
    
    return 0;
}