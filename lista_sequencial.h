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
void exibir(const ListaSequencial *lista){
    if(lista->tamanho == 0){
     printf("\nA lista está vazia\n");
        return;
    }
    printf("\nA lista contem (%d/%d)", lista->tamanho, TAM_MAX);
    for(int i = 0; i < lista->tamanho; i++){
        printf("n° da posição %d: %d",i+1, lista->dados[i]);
    }
}


int inserir_posicao(ListaSequencial *lista, int posicao, int valor){
    if ((*lista).tamanho >= TAM_MAX || posicao < 0 || posicao > lista->tamanho){
            printf("Posicao invalida ou a lista esta completa");
            return 0;
}

    for(int i = (*lista).tamanho; i> posicao; i--){
        (*lista).dados[i] = (*lista).dados[i - 1];
}

    printf("Digite o valor que voce quer adicionar na posicao %d:", posicao);
    scanf("%d", &valor);

    (*lista).dados[posicao] = valor; (*lista).tamanho++;

   }

   int inserir_final(ListaSequencial *lista,int valor){
       if(lista->tamanho >= TAM_MAX){
        printf("\nfalha: Lista cheia!");
        return 0;
       }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
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
