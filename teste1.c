#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

 typedef struct {
  int dados[TAM_MAX]; //onde sera armazenado a quantidade de elementos=
  int tamanho; //quantidade de elementos existentes
 }ListaSequencial;

 //define que a lsita ira começar com 0 elementos

 void inicializar(ListaSequencial *lista) {
   (*lista).tamanho = 0;
 }

 int main(){


   ListaSequencial lista;
   int i;
   inicializar(&lista);

   printf("Lista criada com capacidade para %d elementos. \n", TAM_MAX);
   printf("Elementos atualmente armazenados: %d\n", lista.tamanho);

   printf("\n Digite 3 valores");
   for (i = 0; i < lista.dados; i++){
    scanf("%d", &lista.dados[i]);
   }

   printf("lista atual: ");
   for (i = 0; i < lista.tamanho; i++){
    printf("%d", lista.dados[i]);
    lista.tamanho ++;
   }

 return (0);
 }


 /*
     int x = 10;
     int*p = &x;
     printf("%p \n", &x); ira imprimir o valor armazenado em x
     printf("%d", *p); ira imprimir o valor refereniciado a x
*/
