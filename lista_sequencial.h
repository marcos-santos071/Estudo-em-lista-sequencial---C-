#ifndef lista_sequencial_h
#define lista_sequencial_h

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

 typedef struct {
  int dados[TAM_MAX]; //onde sera armazenado a quantidade de elementos
  int tamanho; //quantidade de elementos existentes
 }ListaSequencial;

 //define que a lsita ira começar com 0 elementos

 void inicializar(ListaSequencial *lista) {
   (*lista).tamanho = 0;
 }

 void ListaSequencial_1(){


   ListaSequencial lista;
   int i, Vusu;
   inicializar(&lista);

   printf("Lista criada com capacidade para %d elementos. \n", TAM_MAX);
   printf("Elementos atualmente armazenados: %d\n", lista.tamanho);
   printf("\n Digite quantos dados voce quer adicionar dentro da capicadde maxima:\n");
   scanf("%d",&Vusu);

   lista.tamanho = Vusu;// define o tamanho a quantidade de dados que srão armazenados

   if (lista.tamanho > TAM_MAX || lista.tamanho <0){
       printf("O tamanho digitado está fora dos paramentros");

       }

   for (i = 0; i < lista.tamanho; i++){
    printf("\n Digite o numero da posição %d: ", i+1);
    scanf("%d", &lista.dados[i]);
   }

   printf("\nlista atual: ");

   for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.dados[i]);
    }
 }
#endif
