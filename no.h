#include <stdio.h>
#include <stdlib.h>

//cria a estrutura do no
typedef struct no{
    int info;
    struct no* proximo;
} t_no;

t_no* constroi_no(int info);