#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_sequencial.h"



 int main(){
    ListaSequencial minha_lista;
    inicializar(&minha_lista);
    char decisao[11], f[] = "encerrar";
    int opcao, valor, pos;

 do{
    printf("=======================\n");
    printf("==== MENU DA LISTA ====\n");
    printf("=======================\n ");

    exibir(&minha_lista);

    printf("1. Inserir elemento no final\n");
    printf("2. Inserir uma quantidade determinada de elementos\n");
    printf("3. Inserir elemento em posicao especifica\n");
    printf("0. sair e encerrar\n");
    printf("escolha uma opção: ");
    scanf("%d",&opcao);

    switch(opcao){
case 1:
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);
    if(inserir_final(&minha_lista, valor)){
        printf("valor inserido com sucesso!\n");
    }
    break;

case 2:
lista_sequencial(&minha_lista);
break;

case 3:
    printf("Digite o valor a ser inserido: ");
    scanf("%d",&valor);
    printf("Digite a posicao (0 a %d): ", minha_lista.tamanho);
    scanf("%d", &pos);
    if (inserir_posicao(&minha_lista, pos, valor)){
        printf("O valor inserido na posição %d com sucesso!",pos);
    }
    break;

case 0:
    printf("\nPrograma encerrado com sucesso!\n");
    break;

default:
    printf("\n Opcao invalida! tente novamente.\n");
    }
 }while(opcao != 0);


 }





