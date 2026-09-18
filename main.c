#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_sequencial.h"





 int main(){
    ListaSequencial minha_lista;
    inicializar(&minha_lista);
    int opcao, valor, pos, valorVusu, Vusu, posicaoProcurado;

 do{

    limpar_tela();

    printf("            =======================\n");
    printf("            ==== MENU DA LISTA ====\n");
    printf("            =======================\n ");
   printf("\n");
    printf("      ---------------------------------------");
    printf("\n--- Criando a sua lista sequencial numérica ---\n");
    printf("      ---------------------------------------\n");

    printf("\nO objetivo deste sistema é criar uma lista simples numérica com números inteiros,\n");
    printf("podendo realizar algumas alterações nas listas criadas, como excluir ou inserir números.\n");

    printf("\nUtilize o teclado numérico para digitar os números correspondentes às opções.");
    printf("\nEx.: opção 1 - digite o número 1 para selecionar.\n");
    printf("\n____________________________________________________________________________________________\n");
    exibir(&minha_lista);

    printf("\n1. Inserir elemento no final.\n");
    printf("2. Inserir uma quantidade determinada de elementos.\n");
    printf("3. Inserir elemento em posição específica.\n");
    printf("4. Encontrar uma posição específica através do valor que foi adicionado à posição.\n");
    printf("5. Buscar por uma posição específica.\n");
    printf("6. Excluir elemento em uma posição específica.\n");
    printf("7. Excluir elementos em posições específicas.\n");
    printf("0. Sair e encerrar.\n");
    printf("Escolha uma opção: ");
    scanf("%d",&opcao);

    switch(opcao){
case 1:
    printf("\nObs.: você deverá inserir um valor inteiro no teclado numérico para ser armazenado na última posição.\n");
    printf("\nEx.: O usuário digitou 4, ele será armazenado na posição 1, caso não tenha nenhum outro valor nessa posição.\n");
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &valor);
    if(inserir_final(&minha_lista, valor)){
        printf("Valor inserido com sucesso!\n");
    }
    pausar();
    break;

case 2:
    printf("\n1. Digite quantos números deseja inserir ao final da lista.");
    printf("\n2. Digite em cada posição um valor para ser armazenado.\n");
    printf("\nO limite de adição de números é a capacidade máxima, sendo %d.\n", TAM_MAX);
    printf("\nEx.: 1. O usuário quer adicionar 3 números, digite 3 para fazer a adição dos 3 números ->\n");
    printf("\n     posição 1: digite o valor desejado, por exemplo 34.\n");
    printf("\n     posição 2: digite o valor desejado, por exemplo 89.\n");
    printf("\n     posição 3: digite o valor desejado, por exemplo 101.\n");
    qtd_Numeros(&minha_lista);
     pausar();
break;

case 3:
    printf("\nO usuário deverá escolher uma posição específica dentro da lista para inserir um valor.\n");
    printf("\nEx.: O usuário deseja a posição 4 e quer inserir o valor 56 nela.\n");
    printf("\n1. Digite a posição em que deseja adicionar o valor: 4");
    printf("\n2. Digite o valor que será adicionado à posição 4: 78\n");
    printf("\nDigite a posição onde deseja inserir (1 a %d): ", minha_lista.tamanho + 1);
    scanf("%d", &pos);
    // Subtrai 1 para converter a posicao de usuario (1..N) para o indice do C (0..N-1)
    if (inserir_posicao(&minha_lista, pos - 1, valor)) {
        printf("O valor foi inserido na posição %d com sucesso!\n", pos);
    }
    pausar();
    break;

case 4:
    printf("\nDigite o valor armazenado na posição que você deseja encontrar para visualizar a posição:\n");
    printf("\n1. Digite o valor para descobrir a posição: 2\n");

    int i;
   if(minha_lista.tamanho == 0){
    printf("\nA lista está vazia. Por favor, insira algum valor.");
    break;
   }
    printf("\nDigite o valor a partir do qual quer visualizar a posição: ");
    scanf("%d", &Vusu);
  buscar_todos(&minha_lista,Vusu);
  pausar();
break;

case 5: {
    printf("\nVocê deverá digitar a posição que deseja ver o valor armazenado nela.\n");
    printf("\n1. Digite a posição que você quer visualizar: 2\n");


    int valorEncontrado;
    if (minha_lista.tamanho == 0) {
        printf("\nA lista está vazia. Por favor, insira algum valor.\n");
        break;
    }

    // Exibe limite correto de 1 ate o tamanho atual
    printf("\nDigite a posição que você quer consultar (1 a %d): \n", minha_lista.tamanho);
    scanf("%d", &pos);

    // Envia pos - 1 para a funcao
    if (buscar_posicao(&minha_lista, pos - 1, &valorEncontrado) != -1) {
        printf("Posição encontrada com sucesso!\n");
        printf("Na posição %d está o valor: %d\n", pos, valorEncontrado);
    } else {
        printf("A posição %d é inválida ou não existe na lista.\n", pos);
    }
    pausar();
    break;
}

case 6:
    printf("\nPara excluir uma posição específica dentro da lista ->");
    printf("\n1. Digite a posição que deseja excluir: 5");

    if (minha_lista.tamanho == 0) {
        printf("\nA lista está vazia. Por favor, insira algum valor.\n");
        break;
    }
    // Limite maximo para exclusao e a quantidade de elementos armazenados
    printf("\nDigite a posição que você quer excluir (1 a %d): ", minha_lista.tamanho);
    scanf("%d", &pos);
    exclusao(&minha_lista, pos - 1);
    pausar();
    break;

case 7:
     printf("\nPara excluir mais de uma posição no mesmo comando -> \n");
     printf("\n1. Digite quantas posições você quer excluir: 2\n");
     printf("\n2. Digite as posições que deseja excluir (somente o número): 4\n");
     printf("\n                                      Irá excluir a posição 4");
     printf("\n                                      Outra posição: \n");
     printf("\n                                      Irá excluir a posição 5");

    if (minha_lista.tamanho == 0) {
        printf("A lista está vazia! Não há elementos para excluir.\n");
        break;
    }
    printf("\nQuantas posições você deseja excluir (1 a %d)? ", minha_lista.tamanho);
    scanf("%d", &Vusu);
    // Envia a lista e a quantidade de elementos que o usuario deseja excluir
    exclusao_qtd(&minha_lista, Vusu);
    pausar();
    break;

case 0:
    printf("\nPrograma encerrado com sucesso!\n");
    break;

default:
    printf("\nOpção inválida! Tente novamente.\n");
    pausar();
    }
 }while(opcao != 0);
 }
