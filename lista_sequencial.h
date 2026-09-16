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
   (*lista).tamanho = 0;
 }

 void inserir(){
int valor;
printf("Digite a posicao que voce quer adicionar um numero:");scanf("%d", &valor);

int inserir(ListaSequencial *lista, int posicao, int valor){
    if ((*lista).tamanho >= TAM_MAX || posicao < 0 || posicao > lista->tamanho){
            printf("Posicao invalida ou a lista esta completa");
}

    for(int i = (*lista).tamanho; i> posicao; i--){
        (*lista).dados[i] = (*lista).dados[i - 1];
}

    printf("Digite o valor que voce quer adicionar na posicao %d:", posicao);
    scanf("%d", &valor);

    (*lista).dados[posicao] = valor; (*lista).tamanho++;

   }
 }



void lista_sequencial(){

   int Vusu, i, valorUsu;
   ListaSequencial lista;
   inicializar(&lista);

   printf("Lista criada com capacidade para %d elementos. \n", TAM_MAX);
   printf("Elementos atualmente armazenados: %d\n", lista.tamanho);
   printf("\n Digite quantos dados voce quer adicionar dentro da capicadde maxima:\n");
   scanf("%d",&Vusu);


for (i = 0; i < Vusu; i++){
    printf("\n Digite o numero da posição %d: ", i+1);
    scanf("%d", &valorUsu);
    lista.dados[i] = valorUsu;
    lista.tamanho++;
    }

    printf("\nlista atual:");
    for(i = 0; i <Vusu; i++){
        printf("\nposicao %d: ",i +1);
        printf("%d", lista.dados[i]);

    }
}



#endif
