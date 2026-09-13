#ifndef lista_sequencial_h
#define lista_sequencial_h

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100


 typedef struct {
  int dados[TAM_MAX]; //onde sera armazenado a quantidade de elementos
  int tamanho; //quantidade de elementos existentes
 }ListaSequencial;

 //define que a lsita ira começar com 0 elemento

 void inicializar(ListaSequencial *lista) {
   (*lista).tamanho = 1;
 }


void lista_sequencial(){

   ListaSequencial lista;
   int i, Vusu;
   inicializar(&lista);

   printf("Lista criada com capacidade para %d elementos. \n", TAM_MAX);
   printf("Elementos atualmente armazenados: %d\n", lista.tamanho);
   printf("\n Digite quantos dados voce quer adicionar dentro da capicadde maxima:\n");
   scanf("%d",&Vusu);

   lista.tamanho = Vusu;// define o tamanho a quantidade de dados que srão armazenados

for (i = 0; i < lista.tamanho; i++){
    printf("%d ", lista.dados[i]); }
   printf("\nlista atual: ");


     printf("Digite a posicao que voce quer adicionar um numero:");scanf("%d", &Vusu);
    int inserir(ListaSequencial *lista, int posicao, int Vusu){
    if ((*lista).tamanho >= TAM_MAX || posicao < 0 || posicao > lista->tamanho){
     exit(1);
    }
    for(int i = (*lista).tamanho; i> posicao; i--){
        (*lista).dados[i] = (*lista).dados[i - 1];
    }

(*lista).dados[posicao] = valor; (*lista).tamanho++;
}




 }
#endif
