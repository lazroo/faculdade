#include <iostream>
#include <clocale>
using namespace std;

// SIMULADOR PARA ÁRVORES BINÁRIAS
// https://www.cs.usfca.edu/~galles/visualization/BST.html

// ESTRUTURAS

struct TItem{
    int chave;
    string nome;
    //...
};

struct TNo{
    TItem item;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{ // frescura!!! Brincadeiras à parte, essa struct não é essencial. Eu a uso para colocar campos complementares.
    string nomeArvore;
    int contItens;
    TNo *raiz;
};

// OPERAÇÕES
void criarArvoreBinVazia(TArvoreBin &a, string n){
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserir(TArvoreBin &a, TNo *&no, TItem i){
    if (no == NULL){ // CASO BASE/PARADA
        no = new TNo;
        no->item = i;
        no->esquerda = NULL;
        no->direita = NULL;
        a.contItens++;
        if (a.raiz == NULL){
            a.raiz = no;
        }
    }
    else{
        if (i.chave < no->item.chave){ // chamada recursiva ESQ
            inserir(a,no->esquerda,i);
        }
        else{
            if (i.chave > no->item.chave){ // chamada recursiva DIR
                inserir(a,no->direita,i);
            }
            else{
                if (i.chave == no->item.chave){
                    cout << "Não posso inserir. Item já existe!" << endl;
                 }
            }
        }

    }
}

void percorrerINOrdem(TNo *&no){
    if(no!=NULL){
        percorrerINOrdem(no->esquerda);
        cout << no->item.chave << ", "; // operação a ser realizada! É o que conseguimos perceber na saída.
        percorrerINOrdem(no->direita);
    }
}

void percorrerPreOrdem(TNo *&no){
    if(no!=NULL){
        cout << no->item.chave << ", ";
        percorrerPreOrdem(no->esquerda);
        percorrerPreOrdem(no->direita);
    }
}

void percorrerPosOrdem(TNo *&no){
    if(no!=NULL){
        percorrerPosOrdem(no->esquerda);
        percorrerPosOrdem(no->direita);
        cout << no->item.chave << ", ";
    }
}


// aula de 13/Nov            // poderia ser só a chave de busca
//void pesquisar(TArvoreBin a, TItem i, TNoh *&n){
void pesquisar(TArvoreBin a, int c, TNo *&n){
    if (n == NULL){
        cout << "Registro não localizado na árvore" << endl;
    }
    else {
        if (c < n->item.chave){
            pesquisar(a, c, n->esquerda);
        }
        else {
            if (c > n->item.chave){
                pesquisar(a, c, n->direita);
            }
            else{
                // aqui vc faz o que precisar!!!
                cout << "Achei o item: " << n->item.chave << endl;
            }
        }
    }

}

void pegarAnterior(TNo *q, TNo *&r){

    if (r->direita != NULL){
        pegarAnterior(q, r->direita);
    }
    else{
        q->item = r->item;
        q = r;
        r = r->esquerda;
        delete q;
    }
}

//void retirar(TItem i, TNoh *&p){
void retirar(int c, TNo *&p){
TNo *aux;

    if (p == NULL){
        cout << "Registro não encontrado" << endl;
    }
    else{
        if (c < p->item.chave){
            retirar(c, p->esquerda);
        }
        else{
            if (c > p->item.chave){
                retirar(c, p->direita);
            }
            else{
                if (p->direita == NULL){
                    aux = p;
                    //exemplo de "debug manual" para ajudar a entender o código
                    //cout << "Passada Dir: " << aux->item.valor << endl;
                    p = p->esquerda;
                    delete aux;
                }
                else{
                    if (p->esquerda != NULL){
                        pegarAnterior(p, p->esquerda);
                    }
                    else{
                        aux = p;
                        p = p->direita;
                        delete aux;
                    }
                }
            }
        }
    }
}


int main(){
    setlocale(LC_ALL,"Portuguese");

    TArvoreBin arvore1;
    criarArvoreBinVazia(arvore1,"Teste");

    TItem iAux;
    iAux.chave = 7;
    iAux.nome = "Gab";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 5;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 9;
    iAux.nome = "Doido";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 3;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 6;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 8;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    iAux.chave = 10;
    iAux.nome = "Lala";
    inserir(arvore1,arvore1.raiz,iAux);

    cout << "IN ORDEM: " << endl;
    percorrerINOrdem(arvore1.raiz);
    cout << endl;
    cout << "PRE ORDEM: " << endl;
    percorrerPreOrdem(arvore1.raiz);
    cout << endl;
    cout << "POS ORDEM: " << endl;
    percorrerPosOrdem(arvore1.raiz);
    cout << endl;


    pesquisar(arvore1,7,arvore1.raiz);
    pesquisar(arvore1,5,arvore1.raiz);

    //retirar(5,arvore1.raiz);
    retirar(7,arvore1.raiz);

    cout << "IN ORDEM: " << endl;
    percorrerINOrdem(arvore1.raiz);
    cout << endl;
    cout << "PRE ORDEM: " << endl;
    percorrerPreOrdem(arvore1.raiz);
    cout << endl;
    cout << "POS ORDEM: " << endl;
    percorrerPosOrdem(arvore1.raiz);
    cout << endl;

    return 0;
}
