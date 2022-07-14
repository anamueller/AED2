#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* ordenamos os vetores porém separados em esquerda e direita, assim sempre iremos comparar
    números da esquerda com direito, então a condição de índices sempre será satisfeita, então
    caso o primeiro número da esquerda (vetor ordenado) seja maior que o último da direita * K então todos
    os outros números anteriores a ele também serão (pois são menores)*/

int Merge(int *vetor, int n, int esq, int meio, int dir, int k){ 
 	int e = esq; 
	int d = dir; 
	int index;
	int pares = 0;
	int temp[n-1];

	for(index = esq; index <= meio; index++){
  	temp[index] = vetor[index];
	}
 	for(index = meio + 1; index <= dir; index++){
  	temp[dir + meio + 1 - index] = vetor[index];
	}

	e = esq; 
	d = dir;

	for(index = esq; index <= dir; index++){ 
  	if(temp[e] > temp[d] * k){ 
   		d--; 
			pares += (meio - e + 1);
  	}else{
   		e++;
  	}
 	}

	e = esq; 
	d = dir;

	for(index = esq; index <= dir; index++){
  	if(temp[e] <= temp[d]){
   		vetor[index] = temp[e++];
  	}else{
   		vetor[index] = temp[d--]; 
		}
	}
 	return pares;
}

int MergeSort(int *vetor, int n, int esq, int dir, int k){
 	if(esq < dir){

  int meio = floor((esq + dir)/2);

  return MergeSort(vetor, n, esq, meio, k) + MergeSort(vetor, n, meio + 1, dir, k)+ Merge(vetor, n, esq, meio, dir, k);  
	}

	else{
		return 0;
	} 
}

int main(){
	int n, index, k, pares;

	scanf("%d", &n); 
	scanf("%d", &k);
	int lista[n];
	
	for(index=0; index<n; index++){
		scanf("%d", &lista[index]);
 }
	pares = MergeSort(lista, n, 0, n - 1, k);
	printf("%d", pares); 
}