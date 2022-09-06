#include <stdio.h>
#define max 256

typedef struct {
  int dia;
  int mes;
  int ano;
}Data;

typedef struct {
  char nome[21];
  Data nascimento;
  char cpf[12];
  char sexo;
}Cliente;




int validarNome(char nome[]) { 
  if(strlen(nome)>20){
    return 0;
  } else {
    return 1;
  }
}



int validarNascimento(Data nascimentoUsuario) {
  if(nascimentoUsuario.ano<=0 || nascimentoUsuario.ano>2022) {
    printf("Ano inválido. Tente novamente. \n");
    return 0;
  }
  if (nascimentoUsuario.mes <=0 || nascimentoUsuario.mes>12) {
    printf("Mês inválido. Tente novamente. \n");
    return 0;
  }

  if(nascimentoUsuario.mes ==2) {
    if(nascimentoUsuario.dia <=0 || nascimentoUsuario.dia >29) {
      printf("Dia inválido para o mês de fevereiro. Tente novamente. \n");
      return 0;
    } else {
      return 1;
    }
 
  } else if( nascimentoUsuario.dia<=0 || nascimentoUsuario.dia>30){
    return 0;
  } else return 1; 
}



int validarSexo(char sexo) {
  char sexoValidos[6] =  {'M', 'F','O','o','m', 'f'};
  for(int i = 0; i < 6; i++) {
    if (sexoValidos[i]== sexo) {
      return 1;
    }
  }
  return 0;
}



int validarCpf(char cpf[]) {
  int cpfInt[11];
  for (int i = 0; i<11; i++) {
    cpfInt[i] = cpf[i] - 48;
  }

  int digVerif1 = cpfInt[9];
  int digVerif2 = cpfInt[10];
  int digVerif1Correto ;
  int digVerif2Correto;

  
  int aux = 10;
  int produtos = 0;
  for (int i = 0; i<9; i++, aux--) {
    produtos = produtos + (cpfInt[i]*aux); 
  }

  int quocProd = produtos/11;
  int restoProd = produtos%11;

  if(restoProd<2){
    digVerif1Correto = 0;
  } else {
    digVerif1Correto = 11 - restoProd;
  }

   if(digVerif1!=digVerif1Correto) {
      printf("Cpf inválido, erro no primeiro digito verificador \n");
      return 0;
    }  

  // cálculo do seg digito 

  aux = 11;
  produtos = 0;
  for (int i = 0; i<10; i++, aux--) {
    produtos = produtos + (cpfInt[i]*aux); 
  }
  
  quocProd = produtos/11;
  restoProd = produtos%11;

  if(restoProd<2){
    digVerif2Correto = 0;
  } else {
    digVerif2Correto = 11 - restoProd;
  }

  if(digVerif1==digVerif1Correto && digVerif2 == digVerif2Correto) {
    printf("Digitos verificadores corretos. CPF válido. \n");
    return 1;
  } else{
    printf("Cpf inválido, erro no último digito verificador \n");
    return 0;
  } 

  
}



Cliente cadastrarCliente() {
  
  Cliente clienteAtual;
  
  int nomeValido = 0;
  int cpfValido = 0 ; 
  int sexoValido = 0;
  int nascValido= 0;
  
  while(nomeValido!=1) {
    printf("Digite o nome \n");
    
    scanf("%s", clienteAtual.nome);
    getchar();
    
    if(validarNome(clienteAtual.nome)==1) {
      printf("Nome válido! \n");
      nomeValido = 1;
    } else {
      printf("Nome inválido \n O limite de caracteres é 20. Pf digite um nome válido. \n");
    }
    
  }
  
  while (sexoValido !=1) {
    printf("Digite o sexo \n");
    scanf("%c", &clienteAtual.sexo);
    getchar();

    if(validarSexo(clienteAtual.sexo)==1) {
      printf("Sexo válido! \n");
      sexoValido = 1;
    } else {
      printf(" Inválido \n Digite uma das opções válidas.\n Masculino : M ou m\n Feminino: F ou f\n Outro : O ou o \n");
    }
  }
  

  printf("Agora vamos cadastrar a data de nascimento \n");

  while(nascValido !=1) {
    printf("Digite o ANO do nascimento \n");
    scanf("%i", &clienteAtual.nascimento.ano); 
    
    
    printf("Digite o MÊS do nascimento \n");
    scanf("%i", &clienteAtual.nascimento.mes);
  
    
    printf("Digite o DIA do nascimento \n");
    scanf("%i", &clienteAtual.nascimento.dia);
   
    
    if(validarNascimento(clienteAtual.nascimento)==1) {
      printf("Nascimento cadastrado com sucesso! \n");
      nascValido = 1;
    } else {
      printf("Erro ao cadastrar nascimento.\n");
    }
  }



  while(cpfValido !=1) {
    printf("Digite o CPF sem pontos e tracos. \n");
    scanf("%s", &clienteAtual.cpf);
    getchar();
    
    if (validarCpf(clienteAtual.cpf)==1){
      cpfValido =1;
    }
  }
 


  return clienteAtual;
}

void main() {
  Cliente clienteAtual = cadastrarCliente();

  printf("======Ficha do cliente====== \n");
  
  printf("Nome : %s\n",clienteAtual.nome);
  printf("CPF: %s \n", clienteAtual.cpf);
  printf("Nascimento : %i/%i/%i\n", clienteAtual.nascimento.dia,clienteAtual.nascimento.mes,clienteAtual.nascimento.ano);
  printf("Sexo : %c", clienteAtual.sexo);
}