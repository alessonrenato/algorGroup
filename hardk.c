#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXSTR 200
#define PURGEFILE 1 /* [1-0] habilita/desabilita relatorio de purge da memoria */

#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif
#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h>
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

typedef struct s_dados
{
    float dado;
    struct s_dados *prox;
} t_dados;

typedef struct s_padrao
{
    t_dados *dados;
    struct s_padrao *prox;
} t_padrao;
    
void readFile(char filename[MAXSTR], t_padrao **dataBase);
void insertListDados(t_dados **head, float insert);
void insertListPadrao(t_padrao **head, t_dados *insert);
void purgeMemo(t_padrao **database);

int main(void)
{
    t_padrao *database = NULL;
    readFile("diabetes.txt",&database);
    purgeMemo(&database);
    return EXIT_SUCCESS;
}

void insertListDados(t_dados **head, float insert)
{
    t_dados *pl = *head,
            *plant = NULL;    
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
        *head = pl;  
    return;
}

void insertListPadrao(t_padrao **head, t_dados *insert)
{
    t_padrao *pl = *head,
             *plant=NULL;
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
        *head = pl;  
    return;
}

void readFile(char filename[MAXSTR],t_padrao **dataBase)
{
    IFDEBUG("DEBUG: readFile begin\n");
    FILE *pfile;
    char *ch, *pchar;
    float insert;
    t_dados *head = NULL;
    t_padrao *database = *dataBase;

    if((pfile = fopen(filename,"r")) == NULL)
    {
        printf("Error, filename\n%s not found!",filename);
        exit(EXIT_FAILURE);
    }
    /* resolver */
    while( ((fgets(ch,MAXSTR,pfile))!= NULL) && (!feof(pfile)))
    {
        IFDEBUG("while t_padrao entr\n");
        ch=malloc(MAXSTR*sizeof(char));
        while((pchar=strchr(ch,' ')) != NULL)            
        {
            IFDEBUG("while t_dados entr\n");
            *pchar = '\0';
            insert = atof(ch);
            /*fscanf(ch,"%f",&insert);*/
            insertListDados(&head,insert);
            ch = pchar + sizeof(char);
            IFDEBUG("while t_dados saiu\n");
        }
        insertListPadrao(&database,head);
        head=NULL;
        IFDEBUG("while t_dados saiu\n");
        free(ch);
    }
    fclose(pfile);
    IFDEBUG("DEBUG: readFile ends\n");
    return;
}

void purgeMemo(t_padrao **database)
{
    IFDEBUG("DEBUG: purgeMemo begin\n");
    FILE *pfile;
    if(PURGEFILE) /* purge file enabled */
    {
        if((pfile = fopen("purgeFile.txt","w")) == NULL)
        {
            printf("purgefile error\n");
            exit(EXIT_FAILURE);
        }
    }
    t_padrao *pl = *database, *plprox = NULL;
    t_dados *dt = NULL, *dtprox = NULL;
    while( pl != NULL)
    {
        dt = pl->dados;
        while(dt != NULL)
        {
            dtprox = dt->prox;
            if(PURGEFILE)                
                fprintf(pfile,"%f ",dt->dado);
            free(dt);
            dt=dtprox;
        }
        if(PURGEFILE)
            fprintf(pfile,"\n");
        plprox = pl->prox;
        free(pl);
        pl=plprox;
    }
    fclose(pfile);
    IFDEBUG("DEBUG: purgeMemo ends\n");
    return;
}                   

