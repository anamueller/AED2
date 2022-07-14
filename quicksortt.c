#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int j, i = (low - 1);
    for (j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int k){
    if (low < high){
        int pi = partition(arr, low, high);
        if(pi>k){
            quickSort(arr, low, pi - 1, k);
        }
        if(pi<k){
            quickSort(arr, pi + 1, high, k);    
        }
        else{
            return;
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