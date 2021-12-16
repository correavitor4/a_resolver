#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main(){
    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Fila* fi = cria_Fila();
    int i;
    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);
        if(Fila_vazia(fi))
            printf("Erro!!!!!!\n");
    }

    imprime_Fila(fi);

    printf("\n\nCópia da fila:\n");
    Fila* copia_fi=copialibera_Fila(fi);
    imprime_Fila(copia_fi);
    
    printf("\n\n\n\n");

    //printf("\n\nFila Invertida:\n");    
    inverte_Fila(copia_fi);
    //imprime_Fila(copia_fi);


    libera_Fila(copia_fi);
    return 0;
}


