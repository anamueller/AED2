    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
     
     
    int maior_palavra(char vetor[][20],int tam){
        int i, max, c,len1;
        max = strlen(vetor[0]);
        for(i=1;i<tam;i++){
            len1=strlen(vetor[i]);
            if(len1>max){
                c=i;
                max=len1;
            }
        }
        return strlen(vetor[c]);
    }
     
    void preencher(char *palavra){ 
        int i=1, l = strlen(palavra);
        if(l < 20){
            while(i != 20-l){
                strcat(palavra, " ");
                i++;
            }
        }
    }
     
    void counting_sort(char vetorA[][20], char vetorB[][20], int tamanho, int l){ //k=27 sempre
        int i, j;
        int vetorC[27];
        for(i=0;i<27;i++){
            vetorC[i]=0; //c[0]=' ', c[1] = 'a', c[2]='b' ...
        }
        for(j=0;j<tamanho;j++){
            if(vetorA[j][l] != ' '){
                vetorC[(int)vetorA[j][l] - 96] = vetorC[(int)vetorA[j][l]-96]+1;
            }
            else{
                vetorC[0] = vetorC[0] + 1;
            }
        }
        for(i=1;i<27;i++){
            vetorC[i]=vetorC[i]+vetorC[i-1];
        }
        printf("\n");
        for(i=0;i<27;i++){
            printf("%d ", vetorC[i]);
        }
        for(j=tamanho-1;j>=0;j--){
            if(vetorA[j][l] != ' '){
                strcpy(vetorB[vetorC[(int)vetorA[j][l]-96]-1], vetorA[j]);
                vetorC[(int)vetorA[j][l]-96] = vetorC[(int)vetorA[j][l]-96]-1;
            }
            else{
                strcpy(vetorB[vetorC[0]-1], vetorA[j]);
                vetorC[0] = vetorC[0]-1;
            }
        }
        for(i=0; i < tamanho; i++){
            strcpy(vetorA[i], vetorB[i]);
        }
    }
     
    void radix_sort(char vetorA[][20], int d, char vetorB[][20], int tamanho){
        int i;
        for(i=d-1;i>=0;i--){
            counting_sort(vetorA, vetorB, tamanho, i);
        }
    }
     
    int transforma(char palavra[20]){
        int i;
        for(i=0;i<20;i++){
            palavra[i] = tolower(palavra[i]);
        }
            
    }
     
    int main(){
        int N, P, M, i;
        scanf("%d", &N); //quantidade de palavras
        char vetorA[N][20]; //vetor inicial com as palavras
        char vetorB[N][20]; //vetor q terá as palavras ordenadas
        for(i=0;i<N;i++){
            scanf("%s", vetorA[i]); //escaneando palavras
            transforma(vetorA[i]);
        }
        int d = maior_palavra(vetorA, N); //segunda saída
        scanf("%d %d", &P, &M); //escaneando onde começa a imprimir e quantas palavras
        for(i=0;i<N;i++){
            printf("%s.\n", vetorA[i]); //primeira saída
            preencher(vetorA[i]);
        }
        printf("%d", d);
        radix_sort(vetorA, d, vetorB, N);
        int j = P-1;
        for (i=0; i<M;i++){ //última saída
        printf("\n%s", vetorB[j]);
        j++;
        }
        return 0;
    }