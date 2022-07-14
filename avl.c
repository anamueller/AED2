#include <stdio.h>
#include <stdlib.h>

int n=0, m=0;
//altura das arvores a direita e a esquerda


struct item{
    int cod;
};

typedef struct item Item;

typedef struct no{
    Item item;
    struct no *esquerda;
    struct no *direita;
} no;

typedef struct no Node;

Node *inicia(){
    return NULL;
}

Item cria(int dado){
    Item item;
    item.cod = dado;
    return item;
}

int altura(Node *raiz) {
    int u, v;
    if (raiz == NULL){
        return -1;
    }
    u = altura(raiz->esquerda);
    v = altura(raiz->direita);
    if (u > v){
        return u+1;
    }
    else {
        return v+1;
    }        
}

int fb(Node *raiz){
    if(raiz==NULL){
        return 0;
    }
    int dif;
    int esq =altura(raiz->esquerda)+1;
    int dir = altura(raiz->direita)+1;
    dif = esq-dir;
    return dif;
}

Node *balanceia(Node *raiz){
    if(fb(raiz)>1 && fb(raiz->esquerda)>=0){ //LL
        Node *pA=raiz, *pB;
        pB = pA->esquerda;
        pA->esquerda = pB->direita;
        pB->direita = pA;
        return pB;
    }
    else if(fb(raiz)<-1 && fb(raiz->direita)<=0){ //RR
        Node *pA = raiz, *pB;
        pB = pA->direita;
        pA->direita = pB->esquerda;
        pB->esquerda = pA;
        return pB;
    }
    else if(fb(raiz)>1 && fb(raiz->esquerda)<=0){ //LR
        Node *pA = raiz, *pB, *pC;
        pB = pA->esquerda;
        pC = pB->direita;
        pB->direita = pC->esquerda;
        pC->esquerda = pB;
        pA->esquerda = pC->direita;
        pC->direita = pA;
        return pC;
    }
    else if(fb(raiz)<-1 && fb(raiz->direita)>=0){ //RL
        Node *pA = raiz, *pB, *pC;
        pB = pA->direita;
        pC = pB->esquerda;
        pB->esquerda = pC->direita;
        pC->direita = pB;
        pA->direita = pC->esquerda;
        pC->esquerda = pA;
        return pC;
    }
    return raiz;
}

Node *insere(Node *raiz, Item dado){
    if(fb(raiz)>1 || fb(raiz)<-1){
        raiz = balanceia(raiz);
    }
    if(raiz == NULL){
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = dado;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else if(dado.cod>raiz->item.cod){
        raiz->direita = insere(raiz->direita, dado);
    }
    else if (dado.cod<raiz->item.cod){
        raiz->esquerda = insere(raiz->esquerda, dado);
    }
    if(fb(raiz)>1 || fb(raiz)<-1){
        raiz = balanceia(raiz);
    }
    return raiz;
}

Node *pesquisa(Node *raiz, int dado){
    if(raiz!=NULL){
        if(raiz->item.cod == dado){
            return raiz;
        }
        else{
            if(dado> raiz->item.cod){
                return pesquisa(raiz->direita, dado);
            }
            else{
                return pesquisa(raiz->esquerda, dado);
            }
        }
    }
    return NULL;
}


Node *menor(Node *raiz){
    if(raiz!=NULL){
        Node *aux = raiz;
        while(aux->esquerda!=NULL){
            aux = aux->esquerda;
        }
        return aux;
    }
}

Node *remover(Node *raiz, int dado){
    if(raiz!=NULL){
        if(fb(raiz)>1 || fb(raiz)<-1){
            raiz = balanceia(raiz);
        }
        if(dado>raiz->item.cod){
            raiz->direita = remover(raiz->direita, dado);
        }
        else if(dado< raiz->item.cod){
            raiz->esquerda = remover(raiz->esquerda, dado);
        }
        else{
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else if(raiz->esquerda==NULL && raiz->direita!=NULL){
                Node *aux = raiz->direita;
                free(raiz);
                return aux;
            }
            else if (raiz->esquerda!= NULL && raiz->direita==NULL){
                Node *aux = raiz->esquerda;
                free(raiz);
                return aux;
            }
            else if (raiz->esquerda!=NULL && raiz->direita!=NULL){
                Node *aux = menor(raiz->direita);
                Item itemaux = aux->item;
                raiz = remover(raiz, itemaux.cod);
                raiz->item = itemaux;
            }
        }
        return raiz;
    }
    return NULL;
}



void imprimi(Node *raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->item.cod);
        imprimi(raiz->direita);
        imprimi(raiz->esquerda);
    }
}


int main(){
    Node *arvore=inicia();
    while(n>=0){ //escaneandos valores e inserindo na arvore binaria
        scanf("%d", &n);
        if(n>=0){
            arvore = insere(arvore, cria(n));
        }
    }
    int alt = altura(arvore), altesq = altura(arvore->esquerda), altdir = altura(arvore->direita);
    while(m>=0){ //escaneandos valores a serem pesquisados
        scanf("%d", &m);
        if(m>=0){
            Node *valida = pesquisa(arvore, m);
            if(valida == NULL){
                arvore = insere(arvore, cria(m));
            }
            else{
                arvore = remover(arvore, m);
            }
        }
    }
    scanf("%d", &n); //ultimo elemento a ser pesquisado
    printf("%d, %d, %d\n", alt, altesq+1, altdir+1);
    Node *tmp = pesquisa(arvore, n);
    if(tmp == NULL){
        printf("Valor nao encontrado");
    }
    else if (tmp!=NULL){
        int altmax = altura(tmp), altuesq = altura(tmp->esquerda), altudir = altura(tmp->direita);
        printf("%d, %d, %d", altmax, altuesq+1, altudir+1);
    }
    return 0;
}