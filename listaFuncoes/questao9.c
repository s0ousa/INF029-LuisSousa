#include <stdio.h>
#define max 256

typedef struct {
  char nome[21];
  char dataNascimento[12];
  char cpf[16];
  char sexo;
}Cliente;

int validarNome(char nome[]) {
  int i = 0;
  while(nome[i]!='\0') {
     i++; 
  }
  if(i>20) {
    return 0;
  }else return 1;
      

}


Cliente cadastrarCliente() {
  
  Cliente clienteAtual;
  
  int nomeValido = 0;
  int cpfValido = 0 ; 
  int sexoValido = 0;
  int nascValido= 0;
  
  while(nomeValido!=1) {
    printf("Digite o nome \n");
    fflush(stdin);
    fgets(clienteAtual.nome,21,stdin); // projeeto escola, procurar por isso
  if(validarNome(clienteAtual.nome)==1) {
    nomeValido = 1;
    printf("Nome válido! \n");
  } else {
    printf("Nome inválido, o nome se limita a 20 caracteres \n");
    }
  }
  

  

  
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