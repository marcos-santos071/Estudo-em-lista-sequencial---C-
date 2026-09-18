#ifndef lista_sequencial_h
#define lista_sequencial_h
#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100


void limpar_tela(){
#ifdef _WIN32
     sytem("cls");
 #else
 system("clear");
 #endif
}

void pausar(){
   printf("\nPressione ENTER para continuar e limpar a tela...\n");
   getchar();
   getchar();
}
void voltar(){
   return;
}


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
     printf("\nA lista está vazia.\n");
        return;
    }
    printf("\nA lista contém (%d/%d)\n", lista->tamanho, TAM_MAX);
    for(int i = 0; i < lista->tamanho; i++){
        printf("\nN.º da posição %d: %d\n", i + 1, lista->dados[i]);
    }
}

//ira inserir um valor especifico na posição que o usuario quiser
int inserir_posicao(ListaSequencial *lista, int pos, int valor){
    if ((*lista).tamanho >= TAM_MAX || pos < 0 || pos > lista->tamanho){
            printf("Posição inválida ou a lista está cheia.");
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
        printf("\nFalha: Lista cheia!");
        return 0;
       }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
   }

//ira inserir uma quantidade de dados desejada pelo usuario colocando no final da lista
void qtd_Numeros(ListaSequencial *lista){
    int i,Vqtd, valorUsu;
    printf("\nQuantos dados você quer inserir? \n");
    scanf("%d",&Vqtd);

   if ((lista->tamanho + Vqtd) >TAM_MAX){
            printf("Quantidade pretendida excede o limite ou a lista está cheia.\n");
            printf("\nVoltando ao início.");
            return;
   }else if(Vqtd <= 0){
     printf("\nO valor digitado é inferior à quantidade mínima (qtd. mín. = 1).\n");
     printf("\nVoltando ao início.");
     return;
   }

    for (i = 0; i < Vqtd; i++){
    printf("N.º da posição %d: ", lista->tamanho + 1);
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
            printf("\nValor %d encontrado na posição %d.\n", Vusu, i + 1);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("\nO valor %d não está na lista.\n", Vusu);
    } else {
        printf("\nTotal de ocorrências: %d\n", encontrados);
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
        printf("ERRO!! O valor digitado é inferior ao tamanho da lista.");
    return;

}else if(Vusu >= (*lista).tamanho){
       printf("ERRO!! O valor digitado é superior ou igual ao tamanho da lista.");
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
        printf("\nERRO: Quantidade inválida para exclusão.\n");
        return;
    }

    // Executa a exclusao a quantidade de vezes solicitada
    for (int i = 0; i < Vqtd; i++) {
        printf("Digite a posição que deseja excluir (1 a %d): ", lista->tamanho);
        scanf("%d", &pos_usuario);

        // Valida se a posicao digitada existe na lista atual
        if (pos_usuario < 1 || pos_usuario > lista->tamanho) {
            printf("Posição inválida! Operação cancelada para este item.\n");
            i--; // Decrementa para repetir esta tentativa do loop
            continue;
        }

        // Utiliza a funcao de exclusao simples reajustando para o indice do C (pos - 1)
        exclusao(lista, pos_usuario - 1);
        printf("Posição removida com sucesso!\n");
    }
}

#endif
