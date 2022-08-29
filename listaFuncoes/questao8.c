#include <stdio.h>
#define max 256

typedef struct {
  char nome[21];
  char dataNascimento[12];
  char cpf[16];
  char sexo;
}Cliente;

Cliente cadastrarCliente() {
  
  Cliente clienteAtual;
  printf("Digite o nome \n");
  fgets(clienteAtual.nome,max,stdin);

  printf("Digite o nascimento \n");
  fgets(clienteAtual.dataNascimento,max,stdin);

  printf("Digite o CPF \n");
  fgets(clienteAtual.cpf,max,stdin);

  printf("Digite o sexo \n");
  scanf("%c", &clienteAtual.sexo);
  getchar();

  return clienteAtual;
}

void main() {
  Cliente clienteAtual = cadastrarCliente();

  puts(clienteAtual.nome);
  puts(clienteAtual.cpf);
  puts(clienteAtual.dataNascimento);
  printf("%c", clienteAtual.sexo);
}