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

//ira inserir um valor especifico na posição que o usuario quiser
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
    return 1;
}
//ira inserir uma unidade de numero do usuario no final da lista
   int inserir_final(ListaSequencial *lista,int valor){
       if(lista->tamanho >= TAM_MAX){
        printf("\nfalha: Lista cheia!");
        return 0;
       }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
   }

//ira inserir uma quantidade de dados desejada pelo usuario colocando no final da lista
void qtd_Numeros(ListaSequencial *lista){
    int i,Vusu, valorUsu;
    printf("\nQuantos dados voce quer inserir? \n");
    scanf("%d",&Vusu);

   if ((lista->tamanho + Vusu) >TAM_MAX){
            printf("Quantidade pretendida excede ou a lista está cheia\n");
            printf("\nVoltando ao incio.");
            return;
   }else if(Vusu <= 0){
     printf("\nO valor digitado é inferior a quantidade minima(qtd min = 1)\n ");
     printf("\nVoltando ao incio.");
     return;
   }

    for (i = 0; i < Vusu; i++){
    printf("n° da posição %d:",lista->tamanho +1);
    scanf("%d", &valorUsu);
    lista->dados[lista->tamanho] = valorUsu;
    (*lista).tamanho++;
  }
}

//ira buscar por um valor especifico
void buscar_todos(ListaSequencial *lista, int Vusu){
    int encontrados = 0;

    for(int i = 0; i < (*lista).tamanho; i++){
        if((*lista).dados[i] == Vusu){
        printf("\Valor encontrado %d na posicao %d: \n",Vusu, i);
        encontrados++;
        }
    }
   if(encontrados == 0){
    printf("\nO valor %d não está na lista.\n",Vusu);
   }else{
    printf("\nTotal de ocorrencias: %d\n", encontrados);
   }
}

int buscar_posicao(ListaSequencial *lista, int posicaoProcurada){
      for(int i = 0; i < lista->tamanho; i++){
        if (lista->dados[i] == posicaoProcurada){
            return 1;
        }
      }
return -1;
}





//ira excluir um ponto especifico do codigo
void exclusao(ListaSequencial *lista, int Vusu){
   if(Vusu < 0){
        printf("ERRO!! O valor digitado é inferior a lista.");
    return;

}else if(Vusu >= (*lista).tamanho){
       printf("ERRO!! O valor digitado é superio ou igual a lista");
       return;
 }

  for(int i = Vusu; i < lista->tamanho - 1; i++){
    lista->dados[i] = lista->dados[i+1];
  }
  lista->tamanho--;
  return;
}
//iraecluir pontos especificos do codigo
void exclusao_qtd(ListaSequencial *lista, int valorVusu){
    int Vusu;
 if(valorVusu < 0){
        printf("ERRO!! O valor digitado é inferior a lista.");
    return;
}else if(valorVusu>= (*lista).tamanho){
       printf("ERRO!! O valor digitado é superio ou igual a lista");
       return;
 }

    for (int i = 0; i < Vusu; i++){
    printf("n° da posição %d:",lista->tamanho +1);
    scanf("%d", &valorVusu);
    lista->dados[i] = lista->dados[i+1];
    (*lista).tamanho--;

   }
  return;
 }

#endif
