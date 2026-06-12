#include "lista.h"

//inicia a lista
void inicia_lista(t_lista *pl){
    pl->primeiro = NULL;
}

//verifica se a lista esta vazia
int lista_vazia(t_lista *pl){
    return pl->primeiro == NULL;
}

//insere elemento, mas no inicio
void insere_inicio(int e, t_lista *pl){
    t_no* novo = constroi_no(e);
    if(!lista_vazia(pl)){
        novo->proximo = pl->primeiro;
    }
    pl->primeiro = novo;
}

//insere elemento, mas no fim
void insere_fim(int e, t_lista *pl){
    t_no *novo = constroi_no(e);
    if(lista_vazia(pl)){
        pl->primeiro = novo;
    }
    else{
        //usa o runner, já que não temos um último
        t_no * runner = pl->primeiro;
        //ele vai andando até achar o último no
        while(runner->proximo != NULL){
            runner = runner->proximo;
        }
        runner->proximo = novo;
    }
}

//remove elemento do inicio
int remove_inicio(t_lista *pl){
    //copia valor e endereço do no que vai ser removido
    int copia_valor = pl->primeiro->info;
    t_no * copia_endereco = pl->primeiro;
    pl->primeiro = pl->primeiro->proximo;
    //libera o endereço e retorna o valor
    free(copia_endereco);
    return copia_valor;
}

//remove elemento, mas do fim
//no final, nem é utilizado, já que é simulada uma fila
int remove_fim(t_lista *pl){
    if (lista_vazia(pl)) {
        return -1;
    }
    if (pl->primeiro->proximo == NULL) {
        return remove_inicio(pl);
    }
    t_no *runner = pl->primeiro;
    while (runner->proximo->proximo != NULL) {
        runner = runner->proximo;
    }
    int copia_valor = runner->proximo->info;

    runner->proximo = NULL;
    //libera o endereço e retorna o valor
    free(runner->proximo);
    return copia_valor;
}

//dá print na lista
void exibe_lista(t_lista *pl){
    //se estiver vazia
    if(lista_vazia(pl)){
        printf("Fila vazia");
    }
    //se não, o runner passa pela lista e assim vai imprimindo a info de cada no
    else{
        t_no * runner = pl->primeiro;//cópia
        while(runner != NULL){
            printf("%d-> ", runner->info);
            runner = runner->proximo;
        }
    }
}