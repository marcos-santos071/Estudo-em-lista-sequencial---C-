#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_sequencial.h"



 int main(){
     char decisao[11];
     char f[] = "encerrar";
     int i;
     do {
    printf("=======================\n");
    printf("==== MENU DA LISTA ====\n");
    printf("=======================\n ");

lista_sequencial();

printf("\n digite encerrar para finalizar o programa ou digite continuar para repetir a ordem: ");
    scanf("%10s", decisao);


   }while(strcmp(decisao,f)!= 0);

   printf("programa encerrado");
    return 0;
 }





