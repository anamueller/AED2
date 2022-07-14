#include <stdlib.h>
#include <stdio.h>

//RA: 148806, Aluno: Ana Clara Mueller Miranda
//regra do número primo:
//dividir o número por outros primos: 2,3,5,7,11... até que;
//divisão com resto zero = não primo
//divisão com quociente menor que o divisor e resto diferente de 0 = é primo
//fonte: https://www.somatematica.com.br/fundam/primos.php

int eh_primo(int n){ //função que retorna se um número é primo ou não
    int divisor;
    divisor = 2;
    if(n==1){ //exceção
        return 0; //não é primo
    }
    if (n==2){ //exceção
        return 1; //é primo
    }
    while(divisor<n){
        if(n/divisor<divisor && n%divisor!=0){
        return 1; //é primo
        }
        if(n%divisor==0){
            return 0; //não é primo
        }
        divisor++;
    }
}

int main(){
    int quantidade, i, num;
    scanf("%d", &quantidade); //quantos números serão digitados
    int numeros[quantidade]; //criando vetor do tamanho escolhido anteriormente
    for(i=0; i<quantidade; i++){
        scanf("%d", &num); //números a serem testados se é primo ou não
        numeros[i]=num; //adicionando ao vetor
    }
    for(i=0;i<quantidade;i++){ //for que percorre o vetor inteiro testando cada número e imprimindo seu resultado
        if(eh_primo(numeros[i])==1){ //é primo
            printf("%d 1\n", numeros[i]);
        }
        if(eh_primo(numeros[i])==0){
            printf("%d 0\n", numeros[i]);
        }
    }
    return  0;
}