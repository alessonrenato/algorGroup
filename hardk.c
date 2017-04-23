#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXSTR 100

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
    
void readFile(char filename[MAXSTR]);
void insertListDados(t_dados **head, float insert);
void insertListPadrao(t_padrao **head, t_dados insert);

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

void readFile(char filename[MAXSTR])
{
    FILE *pfile;
    char ch[MAXSTR], *pchar;
    float insert;
    t_dados *head = NULL;
    t_padrao *database = NULL;

    if((pfile = fopen(filename)) == NULL)
    {
        printf("Error, filename\n%s not found!",filename);
        exit(EXIT_FAILURE);
    }
    while( ((fgets(ch,MAXSTR,pfile))!= NULL) && (!feof(pfile)))
    {
        while((pchar=strchr(ch,' ')) != NULL)
        {
            *pchar = '\0';
            fscanf(ch,"%f",&insert);
            insertListDados(&head,insert);
            ch = pchar + sizeof(char);
        }
        insertListPadrao(&database,head);
        head=NULL;
    }
    return;
}





