#include <stdio.h>
#include <stdlib.h>

int troca = 0;
//função recursiva que recebe os quantidade de vales e troca e retorna quantidade de livros que se compra com estes
int quantos_livros(int vales){
    if(vales/troca<=0){
        return 0;
    }
    //quantidade de vales é superior ao do valor de troca
    return quantos_livros(vales/troca + vales%troca)+vales/troca;
    //vales/troca = livros comprados e quantidade de vales ganhos
}

int main(){
    int i, qntd_vales, t, dinheiro, preco, casos_teste;
    //cada livro comprado te da um vale
    //troca = quantidade de vales necessários pra trocar por um livro
    scanf("%d", &casos_teste);
    int livros_final [casos_teste]; 
    for(i=0; i<casos_teste; i++){
        scanf("%d %d %d", &dinheiro, &preco, &t);
        if(dinheiro==0){
            livros_final[i] = 0;
        }
        troca = t;
        qntd_vales = dinheiro/preco; //quantos vales ganho com a primeira compra
        livros_final[i] = quantos_livros(qntd_vales); //chamando função
        livros_final[i] = livros_final[i] + qntd_vales; //livros comprados com o dinheiro
    }
    for(i=0; i<casos_teste; i++){
        printf("%d",livros_final[i]);
        printf("\n");
    }
    return 0;
}