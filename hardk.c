#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_dados
{
    float dado;
    struct s_dados *prox = NULL;
} t_dados;

typedef struct s_padrao
{
    t_dados dados;
    struct s_padrao *prox = NULL;
} t_padrao;
    

int main(void)
{
    return EXIT_SUCCESS;
}

void insertListDados(t_dados **head, float insert)
{
    t_dados *pl = *head;
    t_dados *pl = NULL;
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_dados));
    pl->dado = insert;
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        head = pl;  
    return;
}

void insertListPadrao(t_padrao **head, t_dados insert)
{
    t_padrao *pl = *head;
    t_padrao *pl = NULL;
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_padrao));
    pl->dados = insert;
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        head = pl;  
    return;
}



