#include <stdio.h>

int fibonacci(int n) {

  if (n == 1 || n == 2) {
    return(1);
  }
    
  return fibonacci(n-1) + fibonacci(n-2);

}

void main() {
    printf("Digite um num p calcular seu fibonnaci \n");
    int num; 
    scanf("%i", &num);
    
    for (int i = 1; i <= num; i++) {
    printf("%i ", fibonacci(i));
  }
}