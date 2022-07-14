#include <stdio.h>
#include <stdlib.h>

//merge_sort divide os vetores recursivamente
//merge junta os vetores e conta os pares
//feito com ajuda da aluna Beatriz (149418)
int pares = 0;
int i, j, h;

void vetor_temp(int *vetor, int *temp, int esq, int meio, int dir){
    //criando o vetor temporário
    for(i=esq;i<=meio;i++){
        temp[i] = vetor[i];
    }
    for(j=meio+1; j<=dir; j++){
        temp[dir+meio+1-j] = vetor[j];
    }
}

void ordena(int *vetor, int *temp, int esq, int meio, int dir){
    //ordenando o vetor
    i = esq;
    j = dir;
    
    vetor_temp(vetor, temp, esq, meio, dir);

    for(h=esq;h<=dir;h++){
        if(temp[i]<=temp[j]){
            vetor[h]=temp[i];
            i++;
        }
        else{
            vetor[h] = temp[j];
            j--;
        }
    }
}

int merge(int *vetor, int *temp, int esq, int meio, int dir, int K){
    //contando os pares
    i = esq;
    j = dir;
    /* ordenamos os vetores porém separados em esquerda e direita, assim sempre iremos comparar
    números da esquerda com direito, então a condição de índices sempre será satisfeita, então
    caso o primeiro número da esquerda (vetor ordenado) seja maior que o último da direita * K então todos
    os outros números anteriores a ele também serão (pois são menores)*/
    vetor_temp(vetor, temp, esq, meio, dir);

    for(h=esq; h<=dir;h++){
        if(temp[i]>temp[j]*K){
            i++;
        }
        else{
            j--;
            pares += (meio-i+1);
        }
    }
    ordena(vetor, temp, esq, meio, dir);
    return pares;
}

int merge_sort(int *vetor, int *temp, int esq, int dir, int K){ //utilizando parte da função dada em aula
    int final;
    if(esq>=dir){
        return;
    }
    int meio = (esq+dir)/2;
    pares = merge_sort(vetor, temp, esq, meio, K);+ merge_sort(vetor, temp, meio+1, dir, K);+ merge(vetor, temp, esq, meio, dir, K);    
}

int main(){
    int i, n, K, numero;
    scanf("%d", &n);
    scanf("%d", &K);
    int *seq =(int*)malloc(n*sizeof(int)); //alocando memoria para vetor
    int *temp [n-1];
    for(i=0; i<n; i++){
        scanf("%d", &numero);
        seq[i] = numero;
    }
    merge_sort(seq, temp, 0, n-1, K);
    printf("%d", pares);
    return 0;
}