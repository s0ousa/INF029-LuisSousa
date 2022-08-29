#include <stdio.h>
#define MAX 256

typedef struct {
  char palavra[MAX];
}Palavras;

typedef struct {
  Palavras palavra1;
  Palavras palavra2;
  Palavras palavra3;
}palavrasUsuario;

palavrasUsuario lerPalavras() {

  palavrasUsuario entrada;

  printf("Digite as 3 palavras \n");
  fgets(entrada.palavra1.palavra,MAX,stdin);
  fgets(entrada.palavra2.palavra,MAX,stdin);
  fgets(entrada.palavra3.palavra,MAX,stdin);

  return entrada;
}

void main() {

  palavrasUsuario entradaUsuario = lerPalavras();

  puts(entradaUsuario.palavra1.palavra);
  puts(entradaUsuario.palavra2.palavra);
  puts(entradaUsuario.palavra3.palavra);
}