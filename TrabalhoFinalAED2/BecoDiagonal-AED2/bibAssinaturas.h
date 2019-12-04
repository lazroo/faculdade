#ifndef BIBASSINATURAS_H_INCLUDED
#define BIBASSINATURAS_H_INCLUDED

using namespace std;

struct TItem{
    string nome;
    int chave, preco;

};

struct TNo{
    TItem item;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{ //estrutura para abrigar campos complementares
    string nomeArvore;
    int contItens;
    TNo *raiz;
};

void menu();

#endif // BIBASSINATURAS_H_INCLUDED
