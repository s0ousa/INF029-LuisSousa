#include <stdio.h>

void main() {
  int *vetor, tamanho;

  puts("Digite o tamanho do vetor");
  scanf("%i", &tamanho);

  vetor = (int*) malloc(tamanho*sizeof(int));

  for(int i = 0; i<tamanho;i++) {
    vetor[i] = i+1;
    printf("%i", vetor[i]);
    if(i<tamanho-1) {
      puts(",");
    }  
  }

  free(vetor);
}