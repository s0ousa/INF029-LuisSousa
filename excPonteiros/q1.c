#include <stdio.h>

void main() {
    int meuInt;
    char minhaString[10];
    float meuFloat;
    double meuDouble;

    int *pntInt = &meuInt;
    //char *pntString = &minhaString;
    float *pntFloat = &meuFloat;
    double *pntDouble = &meuDouble;

    printf("Digite o valor do inteiro \n");
    scanf("%i",&meuInt);

   /* printf("Digite o valor do string \n");
    scanf("%[^\n]s", minhaString);
    fflush(stdin);
     */
    
    printf("Digite o valor do double \n");
    scanf("%d",&meuDouble);
    
    printf("Digite o valor do float \n");
    scanf("%f",&meuFloat);
    
    puts("printando....");

    printf("%i\n", *pntInt);
    puts(*pntString);
    printf("%d\n", *pntDouble);
    printf("%f\n", *pntFloat);
    
    
}