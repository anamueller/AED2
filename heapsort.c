#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b){
    char aux[21];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}

void heapify(char vetor[][21], int tamanho, int i){
    int max, esq = 2*i+1, dir = 2*i+2;
    if(esq<tamanho && strcmp(vetor[esq],vetor[i])>0){
        max = esq;
    }
    else{
        max = i;
    }
    if(dir<tamanho && strcmp(vetor[dir], vetor[max])>0 && strcmp(vetor[dir], vetor[esq])>0){
        max = dir;
    }
    if(max!=i){
        swap(vetor[i], vetor[max]);
        heapify(vetor, tamanho, max);
    }
}

void extract(char vetor[][21], int tamanho){
    swap(vetor[0], vetor[tamanho-1]);
    tamanho--;
    heapify(vetor, tamanho, 0);
}

void heapsort(char vetor[][21], int tamanho){
    int i;
    //build heap
    for(i=tamanho/2-1;i>=0;i--){
        heapify(vetor, tamanho, i);
    }
    printf("build_heap: ");
    for(i=0;i<tamanho;i++){
        printf("%s", vetor[i]);
        if(i!=tamanho-1){
            printf(" ");
        }
    }
    while(tamanho>0){
        extract(vetor, tamanho);
        tamanho--;
    }
}

int valida(char* palavra){
    int i;
    for(i=0;i<strlen(palavra);i++){
        if(!(122>=(int)palavra[i] && 97<=(int)palavra[i])){
            printf("a palavra %s eh invalida", palavra);
        	return 1;
            break;
        }
        else{
            continue;
        }
    }
    return 0;
}

int main(){
    int N, M, i, ind, j;
    scanf("%d", &N); //palavras a ser digitadas
    char vetor[N][20];
    for(i=0;i<N;i++){
        scanf("%s",vetor[i]); //palavras escaneadas
        if(valida(vetor[i])==1){
            return 0;
        };
    }
    scanf("%d", &M); //quantas palavras entram no jogo
    char jogo[M][21];
    for(i=0;i<M;i++){
        scanf("%d", &ind); //indices escolhidos para saber quais são as palavras
        strcpy(jogo[i], vetor[ind]);
    }
    heapsort(jogo, M);
    printf("\npalavras: ");
    for(i=0;i<M;i++){
        printf("%s ", jogo[i]);
    }
    return 0;
}