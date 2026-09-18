#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_sequencial.h"




 int main(){
    ListaSequencial minha_lista;
    inicializar(&minha_lista);
    int opcao, valor, pos, valorVusu, Vusu, posicaoProcurada;

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
    printf("Digite a posicao onde deseja inserir (1 a %d): ", minha_lista.tamanho + 1);
    scanf("%d", &pos);
    // Subtrai 1 para converter a posicao de usuario (1..N) para o indice do C (0..N-1)
    if (inserir_posicao(&minha_lista, pos - 1, valor)) {
        printf("O valor foi inserido na posição %d com sucesso!\n", pos);
    }
    break;

case 4:
    int i;
   if(minha_lista.tamanho == 0){
    printf("A lista esta vazia, peço que insira alguma valor");
    break;
   }
    printf("Digite a posicao que quer visualizar a partir do valor:");
    scanf("%d", &Vusu);
  buscar_todos(&minha_lista,Vusu);


break;

case 5: {
    int valorEncontrado;
    if (minha_lista.tamanho == 0) {
        printf("A lista esta vazia, peço que insira algum valor.\n");
        break;
    }

    // Exibe limite correto de 1 ate o tamanho atual
    printf("\nDigite a posicao que voce quer consultar (1 a %d): ", minha_lista.tamanho);
    scanf("%d", &pos);

    // Envia pos - 1 para a funcao
    if (buscar_posicao(&minha_lista, pos - 1, &valorEncontrado) != -1) {
        printf("Posicao encontrada com sucesso!\n");
        printf("Na posicao %d esta o valor: %d\n", pos, valorEncontrado);
    } else {
        printf("Posicao %d e invalida ou nao existe na lista.\n", pos);
    }
    break;
}

case 6:
    if (minha_lista.tamanho == 0) {
        printf("A lista esta vazia, peço que insira algum valor.\n");
        break;
    }

    // Limite maximo para exclusao e a quantidade de elementos armazenados
    printf("Digite a posicao que voce quer excluir (1 a %d): ", minha_lista.tamanho);
    scanf("%d", &pos);
    exclusao(&minha_lista, pos - 1);
    break;

case 7:
    if (minha_lista.tamanho == 0) {
        printf("A lista esta vazia! Nao ha elementos para excluir.\n");
        break;
    }
    printf("Quantas posicoes voce deseja excluir (1 a %d)? ", minha_lista.tamanho);
    scanf("%d", &Vusu);
    // Envia a lista e a quantidade de elementos que o usuario deseja excluir
    exclusao_qtd(&minha_lista, Vusu);
    break;

case 0:
    printf("\nPrograma encerrado com sucesso!\n");
    break;

default:
    printf("\n Opcao invalida! tente novamente.\n");
    }
 }while(opcao != 0);

 }


