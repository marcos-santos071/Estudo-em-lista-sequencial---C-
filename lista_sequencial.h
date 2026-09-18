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
        printf("\nn° da posição %d: %d\n",i +1, lista->dados[i]);
    }
}

//ira inserir um valor especifico na posição que o usuario quiser
int inserir_posicao(ListaSequencial *lista, int pos, int valor){
    if ((*lista).tamanho >= TAM_MAX || pos < 0 || pos > lista->tamanho){
            printf("Posicao invalida ou a lista esta completa");
            return 0;
}

    for(int i = lista->tamanho; i> pos; i--){
        (*lista).dados[i] = (*lista).dados[i - 1];
}
    (*lista).dados[pos] = valor;
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
    int i,Vqtd, valorUsu;
    printf("\nQuantos dados voce quer inserir? \n");
    scanf("%d",&Vqtd);

   if ((lista->tamanho + Vqtd) >TAM_MAX){
            printf("Quantidade pretendida excede ou a lista está cheia\n");
            printf("\nVoltando ao incio.");
            return;
   }else if(Vqtd <= 0){
     printf("\nO valor digitado é inferior a quantidade minima(qtd min = 1)\n ");
     printf("\nVoltando ao incio.");
     return;
   }

    for (i = 0; i < Vqtd; i++){
    printf("n° da posição %d:",lista->tamanho + 1);
    scanf("%d", &valorUsu);
    lista->dados[lista->tamanho] = valorUsu;
    (*lista).tamanho++;
  }
}

//ira buscar por um valor especifico
void buscar_todos(ListaSequencial *lista, int Vusu) {
    int encontrados = 0;

    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == Vusu) {
            // Imprime i + 1 para bater com a escala exibida no menu
            printf("\nValor encontrado %d na posicao %d.\n", Vusu, i + 1);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("\nO valor %d nao esta na lista.\n", Vusu);
    } else {
        printf("\nTotal de ocorrencias: %d\n", encontrados);
    }
}
//ira buscar por uma posicao especifca
int buscar_posicao(ListaSequencial *lista, int pos, int *valorEncontrado) {
    if (pos< 0 || pos >= lista->tamanho) {
        return -1; // Posicao invalida
    }
    *valorEncontrado = lista->dados[pos]; // Salva o valor no ponteiro
    return 1; // Sucesso
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
// Função para excluir uma quantidade (Vqtd) de posições informadas pelo usuário
void exclusao_qtd(ListaSequencial *lista, int Vqtd) {
    int pos_usuario;

    // Valida se a quantidade pedida faz sentido
    if (Vqtd <= 0 || Vqtd > lista->tamanho) {
        printf("\nERRO: Quantidade invalida para exclusao.\n");
        return;
    }

    // Executa a exclusao a quantidade de vezes solicitada
    for (int i = 0; i < Vqtd; i++) {
        printf("Digite a posicao que deseja excluir (1 a %d): ", lista->tamanho);
        scanf("%d", &pos_usuario);

        // Valida se a posicao digitada existe na lista atual
        if (pos_usuario < 1 || pos_usuario > lista->tamanho) {
            printf("Posicao invalida! Operacao cancelada para este item.\n");
            i--; // Decrementa para repetir esta tentativa do loop
            continue;
        }

        // Utiliza a funcao de exclusao simples reajustando para o indice do C (pos - 1)
        exclusao(lista, pos_usuario - 1);
        printf("Posicao removida com sucesso!\n");
    }
}

#endif
