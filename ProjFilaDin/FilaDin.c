#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini��o do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Defini��o do N� Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}


Fila* copialibera_Fila(Fila* fi){
    Fila * filaCopia= cria_Fila();
    Elem* el = (Elem*) malloc(sizeof(Elem));
    while(!Fila_vazia(fi)){
        consulta_Fila(fi,el);
        remove_Fila(fi);
        insere_Fila(filaCopia,el->dados);

    }

return filaCopia;
}


int inverte_Fila(Fila* fi){
    Elem *el = (Elem*) malloc(sizeof(Elem));
    Fila * aux= cria_Fila();
    Fila *filaFinal = cria_Fila();
    int tamanhoParaCont = tamanho_Fila(fi);
    int i=tamanhoParaCont;
    int j=0;

    while(tamanhoParaCont>0){
        if(i>1){
            
            consulta_Fila(fi,el);
            remove_Fila(fi);
            insere_Fila(aux,el->dados);
            i--;
            printf("\n");
            imprime_Fila(aux);
            printf("\n");
            
        }
        else if(j<tamanhoParaCont){
           
            // printf ("\nj=");
            // printf("%d",j);
            // printf ("\n");
            // printf("%d",i);
            // imprime_Fila(aux);



            if(j==0){
                consulta_Fila(fi,el);
                insere_Fila(filaFinal,el->dados);
                // printf("\nElemento copiado=  ");
                // imprime_Fila(fi);
                remove_Fila(fi);
                // printf("primeiro elemento aux=  ");
                // imprime_Fila(aux);
                
            }
            
            consulta_Fila(aux,el);
            insere_Fila(fi,el->dados);
            remove_Fila(aux);
            j++;

           
            //printf("%d",j);
        }
        else{
            // imprime_Fila(filaFinal);
            // printf("\n\n");
            tamanhoParaCont--;
            i=tamanhoParaCont;
            j=0;
         
        }
    }
    
    return filaFinal;
}
