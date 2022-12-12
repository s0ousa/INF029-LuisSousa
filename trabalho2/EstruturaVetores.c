#include <stdio.h>
#include <stdlib.h>

#define TAM 10

#include "EstruturaVetores.h"

Principal vetorPrincipal[TAM];

// se posição é um valor válido {entre 1 e 10}
int posicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;
}

void getDadosAux(int tam, int vetorAux[], int posicao){
  
  for (int i = 0; i < tam; i++)
    vetorAux[i] = vetorPrincipal[posicao].aux[i];
}

void insertion(int vetor[], int tam){
  for (int i = 1; i < tam; i++){
			
			int aux = vetor[i];
			int j = i;
			
			while ((j > 0) && (vetor[j-1] > aux)){
				vetor[j] = vetor[j-1];
				j -= 1;
			}
			vetor[j] = aux;

		}
  
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
  int retorno = 0;
  if (tamanho < 1)
    return TAMANHO_INVALIDO;

  if (posicaoValida(posicao))
    return POSICAO_INVALIDA;

  posicao--; // o vetor vai de 0 - 9

  if (vetorPrincipal[posicao].aux != NULL)
    return JA_TEM_ESTRUTURA_AUXILIAR;

  vetorPrincipal[posicao].aux = (int *)malloc(
      tamanho * sizeof(int)); // AUXILIAR É UM PONTEIRO(VETOR) DO TIPO INTEIRO

  if (vetorPrincipal[posicao].aux == NULL)
    return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao].tamanhoAux = tamanho;

  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
   if (posicaoValida(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (vetorPrincipal[posicao].aux == NULL )
        return SEM_ESTRUTURA_AUXILIAR;
    
    int qtd = vetorPrincipal[posicao].qtd; //quantidade de elemento nessa posicao

    if (qtd >= vetorPrincipal[posicao].tamanhoAux)//quantidade de elementos permitido
      return SEM_ESPACO;

    vetorPrincipal[posicao].aux[qtd] = valor;
    vetorPrincipal[posicao].qtd++; 
  
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica Rertono
(int) SUCESSO - excluido com sucesso ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno = SUCESSO;

  if (posicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if (vetorPrincipal[posicao].qtd == 0) {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  vetorPrincipal[posicao].qtd--;

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int retorno = SUCESSO;
  int existe = 0;

  if (posicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  posicao--;

  if (vetorPrincipal[posicao].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if (vetorPrincipal[posicao].qtd == 0) {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }


  int tam = vetorPrincipal[posicao].qtd;
  int aux;

  if (tam == 1 && vetorPrincipal[posicao].aux[0] == valor) {
    existe = 1;

  } else {
    for (int i = 0; i < tam - 1; i++) {
      // Quando o valor for encontrado, ele  será empurrador até a ultima posicao para no final ser deletado
      if (vetorPrincipal[posicao].aux[i] == valor) {
        aux = vetorPrincipal[posicao].aux[i];
        vetorPrincipal[posicao].aux[i] =
            vetorPrincipal[posicao]
                .aux[i + 1]; // elemento procurado recebe o prox elemento
        vetorPrincipal[posicao].aux[i + 1] = aux;
        existe = 1;
      }
    }
  }

  if (existe == 0)
    return NUMERO_INEXISTENTE;
  else
    vetorPrincipal[posicao].qtd--;

  return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/


int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  if(posicaoValida(posicao) == POSICAO_INVALIDA)
    return POSICAO_INVALIDA;

  posicao--;
    
  if(vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  int qtd = vetorPrincipal[posicao].qtd;
  
  getDadosAux(qtd,vetorAux,posicao);
  
 
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux Rertono (int) SUCESSO -
recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  
 int retorno = SUCESSO;
  if(posicaoValida(posicao) == POSICAO_INVALIDA)
    return POSICAO_INVALIDA;

  posicao--;
    
  if(vetorPrincipal[posicao].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;

  int qtd = vetorPrincipal[posicao].qtd;

  
  getDadosAux(qtd,vetorAux,posicao);
  insertion(vetorAux,qtd);
  
 
  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/

int estruturasAuxVazias(){
   //Verificar se a as estruturas estao vazias
  int vazia = 0;
    int i;

    for (i = 0; i < TAM; i++)
        if (vetorPrincipal[i].qtd == 0)
            vazia++;
    
    if (vazia == TAM)
        return 1;

    return 0;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
   if(estruturasAuxVazias())
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    int i, j;
    int qtd;
    int k = 0;

    for (i = 0; i < TAM; i++){

        if (vetorPrincipal[i].aux != NULL){
            qtd = vetorPrincipal[i].qtd;
        
            for (j = 0; j < qtd; j++, k++)
                 vetorAux[k] = vetorPrincipal[i].aux[j];
        }
    }

    return SUCESSO;
  }
/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/


int ContaTodasAuxiiares(){ 

    int i,j;
    int contador = 0;

    for (i = 0; i < TAM; i++)
        if (vetorPrincipal[i].aux != NULL)
            contador += vetorPrincipal[i].qtd;

    return contador;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

   if(estruturasAuxVazias()){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }

    getDadosDeTodasEstruturasAuxiliares(vetorAux);

    int conta = ContaTodasAuxiiares();

    insertion(vetorAux, conta);

    return SUCESSO;
 
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1 Rertono (int) SUCESSO - foi modificado corretamente o tamanho da
estrutura auxiliar SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (posicaoValida(posicao))
        return POSICAO_INVALIDA;
    
    posicao -= 1;

    if (vetorPrincipal[posicao].aux == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    novoTamanho += vetorPrincipal[posicao].tamanhoAux;

    if (novoTamanho < 1)
        return NOVO_TAMANHO_INVALIDO;

    vetorPrincipal[posicao].aux = (int*)realloc(vetorPrincipal[posicao].aux, novoTamanho * sizeof(int));

    if (vetorPrincipal[posicao].aux == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].tamanhoAux = novoTamanho;

    int qtd = vetorPrincipal[posicao].qtd;

    if (qtd > novoTamanho)
        vetorPrincipal[posicao].qtd = novoTamanho;
    else
        vetorPrincipal[posicao].qtd = qtd;
    
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'. Retorno (int) POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

if (posicaoValida(posicao))
        return POSICAO_INVALIDA;
    
    posicao -= 1;

    if (vetorPrincipal[posicao].aux == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int qtd = vetorPrincipal[posicao].qtd;

    return qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas. Retorno (No*) NULL, caso não tenha nenhum número nas
listas No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() { return NULL; }

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].tamanhoAux = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar() {
  int i;
  for (i = 0; i < TAM; i++)
    free(vetorPrincipal[i].aux);
}
