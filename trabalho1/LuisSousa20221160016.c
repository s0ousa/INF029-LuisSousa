
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Luis André Sousa Sousa 
//  email: las.sousa@outlook.com
//  Matrícula: 20221160016
//  Semestre: 2 

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LuisSousa20221160016.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int validaAno(int ano) {
 
  if(ano<=0 || ano>2022) {
    return 0;
  } else return 1;
}

int anoEhBissexto(int ano) {
  int anoBissexto = 0;
  if (ano%4 == 0 && ano%100 !=0) {
    anoBissexto = 1;  
  } else if (ano%4 ==0 && ano%100 ==0 && ano%400==0) {
    anoBissexto = 1;
  }

  return anoBissexto;
}

int validaMes (int mes) {
  if(mes <=0 || mes>12) {
    return 0;
  } else return 1;
}

int validaDia (int dia, int mes,int ano) {

  if(dia <=0) {
    return 0;
  }

  int mesesTrinta[] = {4,6,9,11};
  //int mesesTrintaUm[] = {1,3,5,7,8,10,12};
  int anoBissexto = anoEhBissexto(ano);

  int mesTemTrinta = 0;
 // int mesTemTrintaUm = 0;


  for(int i = 0;i<4;i++) {
    if (mesesTrinta[i] == mes) {
      mesTemTrinta = 1;
    }
  }

 /* for(int i = 0; i<7;i++) {
    if(mesesTrintaUm == mes) {
      mesTemTrintaUm = 1;
    }
  } */

  if(mes==2) {
    if( dia>28 && anoBissexto ==0) {
      return 0;
    }
    if (dia>29 && anoBissexto ==1){
      return 0;
    }
    
  } else if( mesTemTrinta ==1) {
    if (dia>30){
      return 0;
    } 
  } else if(dia>31) {
    return 0;
  }

  return 1;
}


int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno
  DataQuebrada dataQuebrada = quebraData(data);

  if(validaAno(dataQuebrada.iAno)==0) {
    datavalida= 0;
  } 

  if(validaMes(dataQuebrada.iMes)== 0) {
    datavalida = 0;
  }

  if(validaDia(dataQuebrada.iDia, dataQuebrada.iMes, dataQuebrada.iAno)== 0) {
    datavalida = 0;
  }

  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);

  return datavalida ;
}

int calculaDias(int dia, int mes, int ano) {
  int mesesTrinta[] = {4,6,9,11};
  int mesesTrintaUm[] = {1,3,5,7,8,10,12};
  
  int totalDias = 0;
  
  int diasAnos = (ano-1)*365;
  int anosBissextosDecorridos = ano/4;
  diasAnos +=anosBissextosDecorridos;

 

  for(int i = 0; i <4;i++) {
    if(mes > mesesTrinta[i]) {
      totalDias += 30;
    }
    
  }



  for(int i = 0; i <7;i++) {
    if(mes > mesesTrintaUm[i]) {
      totalDias += 31;
    }
 
  }
   

    
  if(mes>2) {
    if(anoEhBissexto(ano)==1) {
       totalDias +=29;   
    } else {
      totalDias +=28;
    }
  }

 
  totalDias += dia;
  
  totalDias += diasAnos;
 
 return totalDias; 
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    DataQuebrada dataInicialQ = quebraData(datainicial);
    DataQuebrada dataFinalQ = quebraData(datafinal);


  
  
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    int diaInicial = dataInicialQ.iDia;
    int mesInicial = dataInicialQ.iMes;
    int anoInicial = dataInicialQ.iAno;
    int diaFinal = dataFinalQ.iDia;
    int mesFinal = dataFinalQ.iMes;
    int anoFinal = dataFinalQ.iAno;
  
  
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{


            //verifique se a data final não é menor que a data inicial

        if(anoInicial>anoFinal) {
          dma.retorno = 4;
          return dma;
        }

        if(anoInicial==anoFinal && mesInicial>mesFinal) {
          dma.retorno = 4;
          return dma;
        }

        if(anoInicial==anoFinal && mesInicial==mesFinal && diaInicial> diaFinal) {
          dma.retorno = 4;
          return dma;
        }
      } 
      
      //calcule a distancia entre as datas 
      
      int totalDiasDI = calculaDias(diaInicial,mesInicial,anoInicial);
      int totalDiasDF = calculaDias(diaFinal,mesFinal,anoFinal);
  
      int diferencaEmDias = totalDiasDF - totalDiasDI;

    //funcionandoooooo
  
      int auxDias = diferencaEmDias;
  
     dma.qtdAnos = auxDias/365;
      auxDias = auxDias - (dma.qtdAnos*365);

      
      dma.qtdMeses = auxDias/30;
      auxDias = auxDias - (dma.qtdMeses*30);

      dma.qtdDias = auxDias;

 
      // setudo der certo
      dma.retorno = 1;
      return dma;
}



/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.sitive)


*/
int q3(char *texto, char c, int isCaseSen){
    int qtdOcorrencias = 0;
  
      if(isCaseSen ==1) {
        for(int i = 0; texto[i] != '\0'; i++){
            if(texto[i] == c){
            qtdOcorrencias++;
            }
           //printf("%i \n", qtdOcorrencias);
        }  
        //puts("Saiu do primeiro for");
      } else { // não for case sens
            if ( c>='A' && c<='Z') {
                c = c+32;
            }
            for(int i = 0; texto[i] != '\0'; i++){
              
                if ( texto[i]>='A' && texto[i]<='Z') {
                  texto[i] = texto[i]+32;
                }
              
                if(texto[i] == c){
                  qtdOcorrencias++;
                }
        
            }
        } 

 // printf("QUANTIDADE DE OCORRENCIAS ANTES DE SAIR DA FUNCAO  = %i \n", qtdOcorrencias);
  return qtdOcorrencias;
}
  /*


 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0;
  size_t tamStrBusca = strlen(strBusca) - 1; // 2 
  int aux = 0;
  int index = 0;
  
  for (int i = 0; strTexto[i] != '\0'; i++) {
    if (strTexto[i] == strBusca[aux]) {
      aux++;
    } else {
      aux = 0;
    }

    if (aux == tamStrBusca + 1) {
      posicoes[index] = (i + 1) - tamStrBusca; 
      posicoes[index + 1] = i + 1;             
      index += 2;
      qtdOcorrencias++;
    }
  }

  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{  
    int auxNum = num;
    int contaCasas = 0;
    
      while(auxNum%10!=0 || auxNum%100!=0) {
        auxNum = auxNum/10;
        contaCasas++;
      }


    int tamanho = contaCasas;
    //int minhasCasas[tamanho];
    auxNum = num;
    
    
    /*for(int i = 0; i<contaCasas;i++) {
        minhasCasas[i] = auxNum%10;
        auxNum = auxNum/10;
    }
    
    */
    int saida= 0;
    
    for(int i = 0; i<contaCasas;i++) {
      
        saida = saida + (auxNum%10);
        if(i+1==contaCasas) {
            return saida;
        }else {
            saida*=10;
            auxNum = auxNum/10;
        }
        
    
    }
    return saida;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int contaCasas;
    int auxNum = numerobusca;
    int baseNum = 1; //o numero q procuro eh centena, dezena?
    
    while(auxNum%10!=0 || auxNum%100!=0) {
        auxNum = auxNum/10;
        contaCasas++;
        baseNum *= 10;
    }
    
    int auxBase = numerobase;
    
    while(auxBase>0) {
        if(auxBase%baseNum==numerobusca){
            qtdOcorrencias++;
        }
        auxBase = auxBase/10;
      
        
    }
    
   
    return qtdOcorrencias;
}
