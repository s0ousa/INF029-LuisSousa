
#include <stdio.h>

int main() {

  int valores[10];

  for (int i = 0; i < 10; i++) {
    printf("Digite um número \n");
    scanf("%i", &valores[i]);
  }

  int somaPrimos = 0;
  int valorAtual;
  int divisoresAtual;

  for (int i = 0; i < 10; i++) {
    valorAtual = valores[i];
    divisoresAtual = 0;
    for (int j = valorAtual; j > 0; j--) {
      if (valorAtual % j == 0) {
        divisoresAtual++;
      }
    }
    if (divisoresAtual == 2) {
      printf("O %i tem  %i divisores e portanto é primo! \n ", valorAtual,
             divisoresAtual);
      somaPrimos += valorAtual;
    }
  }

  printf("A soma dos Primos é %i", somaPrimos);

  return 0;
}