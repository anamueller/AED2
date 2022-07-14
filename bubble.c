#include <stdio.h>
#include <stdlib.h>

int n_swaps = 0;

void swap(int *a, int *b) //função que troca as duas variáveis
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}

void bubble(int *vetor, int N){ 
    int i, j;
    for(i=0;i<N-1;i++){
        for(j=0; j<N-1-i; j++){
            if (vetor[j]>vetor[j+1]){
                swap(&vetor[j], &vetor[j+1]);
                n_swaps++; //adiciona cada vez que ocorre um swap para sabermos em qual vez terminou, carlos ou marcelo
            }
        }
    }
}

int main(){
    int N, i, X;
    scanf("%d", &N);
    int *seq =(int*)malloc(N*sizeof(int)); //alocando memoria para vetor
    for (i=0; i<N; i++){
        scanf("%d", &X); 
        seq[i] = X; //adicionando os numeros no vetor
    }
    bubble(seq, N);
    for(i=0;i<N;i++){
        printf("%d", seq[i]);
        if(i<N-1){
            printf(" "); //espaço entre os números
        }
    }
    if(n_swaps%2 == 1){ //número de swaps é ímpar logo o Marcelo ganhou
        printf("\nMarcelo");
    }
    if(n_swaps%2 == 0){ //número de swaps é par logo Carlos ganhou
        printf("\nCarlos");
    }

    return 0;
}