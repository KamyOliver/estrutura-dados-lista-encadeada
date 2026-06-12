#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//conta quantos elementos tem na lista
int tamanho_lista(t_lista *pl) {
    int contador = 0;
    t_no *runner = pl->primeiro;
    //vai passando o runner e somando unidades para o contador
    while (runner != NULL) {
        contador++;
        runner = runner->proximo;
    }
    return contador;
}

//insere vip atras dos outros vips
void insere_vip_atras_vip(int e, t_lista *pl) {
    //se estiver com a lista vazia, apenas adiciona
    if (lista_vazia(pl)) {
        insere_inicio(e, pl);
        return;
    }

    //encontra o primeiro nao vip para adicionar o vip na frente dele//se primeiro comum
    if ((pl->primeiro->info / 100) < 1) {
        insere_inicio(e, pl); 
        return;
    }

    t_no *runner = pl->primeiro;//se ja tiver vip
  
    //leva o runner até o ultimo vip para dai adicionar o novo vip
    while (runner->proximo != NULL && (runner->proximo->info / 100) >= 1) { 
        runner = runner->proximo;
    }

    //cria o vip
    t_no *novo = constroi_no(e);//cria um novo 

    //liga ele com o resto da fila
    novo->proximo = runner->proximo;
    
    //liga ele com o resto dos vips
    runner->proximo = novo;
}

int main() {
    //adiciona a lista
    t_lista fila_atendimento;
    //cria a fila
    inicia_lista(&fila_atendimento);

    //fala que as senhas começam no 1 e as vips no 100
    int proxima_comum = 1;  
    int proxima_vip = 100; 
    //opção para o menu
    int opcao;

    //repete o menu ate escolher sair
    do {
        printf("\n=== SIMULADOR DE FILA DE ATENDIMENTO ===\n");
        printf("1. Emitir nova senha (Comum)\n");
        printf("2. Emitir senha VIP\n");
        printf("3. Chamar proximo\n");
        printf("4. Ver fila atual\n");
        printf("5. Quantas pessoas estao na fila?\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        //verifica qual opcao o usuario escolheu
        switch (opcao) {
            case 1:
                insere_fim(proxima_comum, &fila_atendimento);
                printf("Senha comum numero %d emitida com sucesso!\n", proxima_comum);
                proxima_comum++;
                printf("\n"); 
                break;
            case 2:
                insere_vip_atras_vip(proxima_vip, &fila_atendimento);
                printf("Senha VIP numero %d emitida com sucesso!\n", proxima_vip);
                proxima_vip++;
                printf("\n"); 
                break;
            case 3:
                if (!lista_vazia(&fila_atendimento)) {
                    int senha_atendida = remove_inicio(&fila_atendimento);
                    printf("Proximo cliente atendido. Senha: %d\n", senha_atendida);
                    printf("\n"); 
                } else {
                    printf("Nao ha ninguem esperando na fila.\n");
                }
                break;
            case 4:
                printf("Fila atual aguardando atendimento:\n");
                exibe_lista(&fila_atendimento);
                printf("\n"); 
                break;
            case 5:
                printf("Quantidade de pessoas aguardando atendimento: %d\n", tamanho_lista(&fila_atendimento));
                break;
            case 6:
                printf("Encerrando o atendimento...\n");
                break;
            default:
                printf("Tente novamente\n");
                break;
        }
    } while (opcao != 6);

    //remove todos os elementos restantes quando encerra o programa
    //libera o espaço tambem
    while (!lista_vazia(&fila_atendimento)) {
        remove_inicio(&fila_atendimento);
    }
    return 0;
}