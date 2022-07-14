#include <stdio.h>
#include <stdlib.h>
int nrecursao=0;

void insertion_sort(int *vetor, int n){
    int j, i=1;
    if(n<=1){ //caso base
        return;
    }
    nrecursao++; //calculando o nivel de recursão
    insertion_sort(vetor, n-1);
    int ult = vetor[n-1];
    printf("%d", nrecursao);
    nrecursao--;
    j = n-2;
    while(j>=0 && vetor[j]>ult){ //colocando no lugar certo
        vetor[j+1] = vetor[j];
        j--;
    }
    vetor[j+1]=ult; //lugar correto do número
    printf(" %d %d\n", ult, j+1);
}


int main(){
    int i, tamanho, numero;
    scanf("%d", &tamanho);
    int *seq =(int*)malloc(tamanho*sizeof(int)); //alocando memoria para vetor
    for(i=0; i<tamanho;i++){
        scanf("%d", &numero);
        seq[i] = numero; //adicionando os numeros no vetor
    }
    insertion_sort(seq, tamanho);
    for(i=0; i<tamanho;i++){
        printf("%d ", seq[i]); //imprimindo sequencia em ordem
    }
    return 0;
}