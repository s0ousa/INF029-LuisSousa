#include <stdio.h>

typedef struct {
  char vetor[3];
}Letras;

Letras ler3Letras() {
  
  Letras letrasUsuario;

  for(int i = 0; i<3;i++) {
    printf("Digite a %i letra \n", i+1);
    scanf("%c", &letrasUsuario.vetor[i]);
    getchar();
  }

  return letrasUsuario;
}

void main() {
  Letras letrasEntrada = ler3Letras();

  for(int j = 0; j<4; j++) {
    printf("%c \n", letrasEntrada.vetor[j]);
  }
}