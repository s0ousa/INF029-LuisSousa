#include <stdio.h>
#define TAM 256

int main()
{
    struct pessoa {
        char nome[TAM];
        char cpf[15];    
        int idade ;
        char sexo ;
    };
    
    struct pessoa pessoas[5];
    
    for (int i = 0; i <5; i++) {    
    
        printf("Nome da %ia pessoa : \n", i+1);
        fgets(pessoas[i].nome,TAM,stdin);
    
        printf("Cpf da %ia pessoa : \n", i+1);
        fgets(pessoas[i].cpf,TAM,stdin);
    
        printf("Idade da %ia pessoa : \n", i+1);
        scanf("%i", &pessoas[i].idade);
        getchar();
        
        printf("Sexo(M ou F) da %ia pessoa : \n", i+1);
        scanf("%c", &pessoas[i].sexo);
        getchar();
        
       
        
    }

    for (int j = 0 ; j<5 ; j++) {
         printf( "====== Cadastro da %i pessoa ===== \n ", j+1);
         printf("Nome: %s\n CPF: %s\n Idade:%i\n Sexo: %c\n " , pessoas[j].nome, pessoas[j].cpf, pessoas[j].idade, pessoas[j].sexo );
    }
    

    return 0;
}