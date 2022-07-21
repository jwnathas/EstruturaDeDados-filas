//arquivo que implementa o conteudo do cabeçalho
#include "filaDeProcessos.h"

//Processos
struct no{
    int endereco; //id
    No *proximo; //ponteiro para o prox processo
};

struct fila {
    No *prim;
    No *fim;
    int tam;
};

//função que cria a fila de processos
void criarFila(Fila *fila){
    fila->prim = NULL; //acabou de criar a fila, então é nulo
    fila->fim = NULL; //e o ultimo tambem é nulo
    fila->tam = 0;
}

//inserir processos na fila
void inserirProcessos(Fila *fila, int id){
    No *aux, *novo = malloc(sizeof(No)); //aloca a memoria suficiente
    //conferir se a memoria foi alocada
    if(novo){
        novo->endereco = id; //altera o valor do endereço
        novo->proximo = NULL; //pq insere no final, por isso nulo
        //inserção no nó:
        if(fila->prim == NULL){ //se o primeiro da fila for nulo, então a fila está vazia
            fila->prim = novo; //o conteudo de fila recebe o novo processo que criamos
            fila->fim = novo;
            printf("\nLista de processos iniciada!\n");
        }else { //se já nao houver apenas um processo, ou seja, não for vazia
            fila->fim->proximo = novo; //chega no ultimo no e esse ultimo no linka para o proximo
            fila->fim = novo; //seta o que tava no fim e coloca o novo nó
            printf("\nProcesso adicionado!\n");
        }
        fila->tam++;
    } else {
        printf("\nErro ao alocar memoria!!\n");
    }
}

//remover processos na fila
//função que retorna um ponteiro para o nó
No* removerProcesso(Fila *fila){
    No *remover = NULL;

    if(fila->prim){//condicional pra saber se tem alguem na fila, prim =! null
    //precisamos criar um ponteiro para o primeiro processo da fila
        remover = fila->prim; //ponteiro pro primeiro elemento da fila
        fila->prim = remover->proximo; //esse primeiro elemento recebe o proximo e dimui a fila
        fila->tam--; //diminuindo o tamanho da fila
        printf("\tProcesso removido.\n");
    } else {
        printf("\tFila de processos está vazia.\n");
    }
    return remover; //retorna o nó removido
}

void imprimir(Fila *fila){
    No *aux = fila->prim; //cria um ponteiro aux para o primeiro no da fila
    printf("\t------ FILA DE PROCESSOS ------\n");
    while(aux){ //enquanto aux for diferente de null
    //vai percorrer a fila de processos
        printf("Processo %d ", aux->endereco); //imprime o conteudo do endereco
        aux = aux->proximo; //quando chegar em nulo para
    }
    printf("\n\t------ FIM FILA ------\n");
}
