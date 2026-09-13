#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"



 int main(){
     int encerrar;
     do {
    printf("\n======================= \n");
    printf("==== MENU DA LISTA ====\n");
    printf("=======================\n ");

lista_sequencial();


printf("\n digite -1 para encerrar o programa: ");

    scanf("%d", &encerrar);



     }while(encerrar != -1);
      return 0;
}

