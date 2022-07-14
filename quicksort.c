#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int particao (int vetor[], int comeco, int fim){
    int pivot = vetor[fim];
    int j, i = comeco;
    for (j = comeco; j < fim; j++){
        if (vetor[j] <= pivot){
            swap(&vetor[i], &vetor[j]);
            i++;
        }
    }
    swap(&vetor[i], &vetor[fim]);
    return i;
}

void quickSort(int vetor[], int comeco, int fim, int k){
    if (comeco < fim){
        int pivo = particao(vetor, comeco, fim);
        if(k-1==pivo){
            return;
        }
        else if(k-1<pivo){
            quickSort(vetor, comeco, pivo-1, k);
        }
        else{
            quickSort(vetor, pivo+1, fim, k);
        }
    }
}

int main(){
    int i, k, n, numero;
    scanf("%d", &k);
    scanf("%d", &n);
    int *seq =(int*)malloc(n*sizeof(int)); //alocando memoria para vetor
    for(i=0; i<n;i++){
        scanf("%d", &numero);
        seq[i] = numero; //adicionando os numeros no vetor
    }
    quickSort(seq, 0, n-1, k);
    printf("%do menor elemento eh o %d\n", k, seq[k-1]);
    for(i=0;i<n;i++){
        printf("%d ", seq[i]);
    }
    return 0;
}