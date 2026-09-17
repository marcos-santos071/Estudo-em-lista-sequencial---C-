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
    printf("\nA lista contem (%d/%d)\n", lista->tamanho, TAM_MAX);
    for(int i = 0; i < lista->tamanho; i++){
        printf("\nn° da posição %d: %d\n",i, lista->dados[i]);
    }
}


int inserir_posicao(ListaSequencial *lista, int posicao, int valor){
    if ((*lista).tamanho >= TAM_MAX || posicao < 0 || posicao > lista->tamanho){
            printf("Posicao invalida ou a lista esta completa");
            return 0;
}

    for(int i = lista->tamanho; i> posicao; i--){
        (*lista).dados[i] = (*lista).dados[i - 1];
}

    (*lista).dados[posicao] = valor;
    (*lista).tamanho++;

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


void lista_sequencial(ListaSequencial *lista){
    int i,Vusu, valorUsu;

    printf("\nQuantos dados voce quer inserir? \n");
    scanf("%d",&Vusu);

   if ((lista->tamanho + Vusu) >TAM_MAX){
            printf("Quntidade pretendida excede ou a lista está cheia\n");
            return;
   }else if(Vusu <= 0){
     printf("\nO valor digitado é inferior a quantidade minima(qtd min = 1)\n ");
     return;
   }

for (i = 0; i < Vusu; i++){
    printf("n° da posição %d:", i+1);
    scanf("%d", &valorUsu);
    lista->dados[lista->tamanho] = valorUsu;
    lista->tamanho++;
}



    }

#endif
