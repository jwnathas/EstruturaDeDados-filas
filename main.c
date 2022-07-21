#include "filaDeProcessos.h"

int main(void){

    No *remove;
    Fila *fila; //incia uma variavel do tipo fila
    unsigned int id = 0; //id dos processos
    int opcao;

    criarFila(&fila); //mandando o endereço da fila


    do{
        printf("\n");
        printf("\t0 - Sair\n\t1 - Inserir processo\n\t2 - Remover processo\n\t3 - Imprimir\n");
        printf("\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inserirProcessos(&fila, id++); //inserir na fila vai receber o end da fila e vai incrimentar no id
                //toda vez que chamar um processo
                break;
            case 2:
                remove = removerProcesso(&fila);
                free(remove);
                break;
            case 3:
                imprimir(&fila);
                break;
            default:
                if(opcao != 0){
                    printf("\nOpcao invalida!\n");
                }
        }

    }while(opcao != 0);

    return 0;
}
