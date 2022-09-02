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
  fflush(stdin);
  fgets(clienteAtual.nome,21,stdin);

  printf("Digite o nascimento \n");
  fflush(stdin);
  fgets(clienteAtual.dataNascimento,12,stdin);

  printf("Digite o CPF \n");
  fflush(stdin);
  fgets(clienteAtual.cpf,16,stdin);

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