#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_sequencial.h"




 int main(){
    ListaSequencial minha_lista;
    inicializar(&minha_lista);
    char decisao[11], f[] = "encerrar";
    int opcao, valor, pos, valorVusu, Vusu;

 do{
    printf("            =======================\n");
    printf("            ==== MENU DA LISTA ====\n");
    printf("            =======================\n ");
   printf("\n");
    printf("      ---------------------------------------");
    printf("\n--- Criando a sua lista sequencial numerica ---\n");
    printf("      ---------------------------------------\n");

    printf("\nUtilize o teclado numerico para digitar os numeros correspondentes as opções.");
    printf("\nEx.: opcao 1 - digite o numero 1 para selecionar.\n");

    exibir(&minha_lista);

    printf("\n1. Inserir elemento no final.\n");
    printf("2. Inserir uma quantidade determinada de elementos.\n");
    printf("3. Inserir elemento em posicao especifica.\n");
    printf("4. Buscar valor em posicões especificas.\n");
    printf("5. Buscar uma posicao especifica.\n");
    printf("6. Excluir elemento em posicao especifica.\n");
    printf("7. Excluir elementos em posicões especificas.\n");
    printf("0. sair e encerrar.\n");
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
    qtd_Numeros(&minha_lista);


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

case 4:
    ListaSequencial *lista;
    int i;
    printf("Digite a posicao que quer visualizar a partir do valor:",minha_lista.tamanho -1);
    scanf("%d", &Vusu);
  buscar_todos(&minha_lista,Vusu);

break;

case 5:
    int posicao_encotrada;

printf("\nDigite a posicao que voce quer encontrar o valor: ");
scanf("%d", posicaoProcurada)
buscar_posicao(&minha_lista, posicaoProcurada);

posicao_encotrada = buscar_posicao(&minha_lista, posicaProcurada);

if(posicao_encontrada != -1){
 printf("\nSucesso: a posicao  tem o valor  da lista", );
}else{
  printf("\nAtenção: a posicao   não existe");
}
break;

case 6:
    printf("Digite a posicão que voce quer excluir de (0 a %d): ", minha_lista.tamanho -1);
    scanf("%d", &pos);
    exclusao(&minha_lista, pos);
    break;

case 7:
  printf("Digite quantas posicoes voce quer excluir de (0 a %d): ", minha_lista.tamanho -1);
    scanf("%d",&valorVusu);
  exclusao_qtd(&minha_lista, pos);
  break;

case 0:
    printf("\nPrograma encerrado com sucesso!\n");
    break;

default:
    printf("\n Opcao invalida! tente novamente.\n");
    }
 }while(opcao != 0);

 }


