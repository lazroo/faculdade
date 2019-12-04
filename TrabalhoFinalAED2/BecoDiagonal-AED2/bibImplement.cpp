#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include "bibAssinaturas.h"
using namespace std;



// operações da arvore binária
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
    }else{
        if (i.chave < no->item.chave){ // chamada recursiva ESQ
            inserir(a,no->esquerda,i);
        }
        else{
            if (i.chave > no->item.chave){ // chamada recursiva DIR
                inserir(a,no->direita,i);
            }
            else{
                cout << "Não posso inserir. Item já existe!" << endl;
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

//procedimento para exibir arte inicial
void titulo(){
cout << endl;
cout << "   _-_ _,,                          -_____                                     ,, "<<endl;
cout << "      |/  )                           ' | -,   '   _     _                 _   || "<<endl;
cout << "     ~||_<    _-_   _-_ ./'\\\\        /| |  |` \\\\  < \,  / \\\\  /'\\\\ \\\\/\\\\  < \\\\, || "<<endl;
cout << "      || \\\\  || \\\\ ||   || ||        || |==|| ||  /-|| || || || || || ||  /-|| || "<<endl;
cout << "      ,/--|| ||/   ||   || ||       ~|| |  |, || (( || || || || || || || (( || || "<<endl;
cout << "     _--_-'  \\\\,/  \\\\,/ \\\\,/         ~-____,  \\\\  \\\\/\\\ \\\\_-| \\\\,/  \\\\ \\\\   \/\\\\ \\\\ "<<endl;
cout << "    (                               (                   /  \                      "<<endl;
cout << "                                                       '----`                     "<<endl;
cout << "                      --==Bem vindo ao Beco Diagonal!!==--"<<endl;
cout << "            --==O lugar perfeito para encontrar todos os artigos==--"<<endl;
cout << "            --==mágicos necessários para seus feitiços e poções!!==--"<<endl;
cout << endl;
}

//procedimento para exibir nomes das lojas
void lojas(){
cout << "                        --==Qual loja deseja visitar?==--"<<endl;
cout << "         _______________________________________________________________"<<endl;
//Olivaras
cout << "    --==||                   .    __                                  ||==--"<<endl;
cout << "    --==||                  /| _ /  \\|.   _  _ _  _                   ||==--"<<endl;
cout << "    --==||                   |   \\__/||\\/(_|| (_|_)                   ||==--"<<endl;
//Floreios o Borrões
cout << "    --==||       __     __                     __                     ||==--"<<endl;
cout << "    --==||        _) _ |_ | _  _ _. _  _   _  |__) _  _ _ ~  _ _      ||==--"<<endl;
cout << "    --==||       /__   |  |(_)| (-|(_)_)  (-  |__)(_)| | (_)(-_)      ||==--"<<endl;
//Farmácia Mullpeppers
cout << "    --==||   __     __                                                ||==--"<<endl;
cout << "    --==||    _) _ |__ _  _ _  ,  _. _   |\\/|   || _  _ _  _  _ _ _   ||==--"<<endl;
cout << "    --==||   __)   |  (_|| |||(_|(_|(_|  |  ||_||||_)(-|_)|_)(-| _)   ||==--"<<endl;
cout << "    --==||________________________________________|____|__|___________||==--"<<endl<<endl;
cout << "                      --==4-Para sair do Beco Diagonal==--"<<endl<<endl;
}

// LENDO DO ARQUIVO E UTILIZANDO NA MEMÓRIA
int lendoArq(string nomeArq, TArvoreBin &p){

    //fstream arq(nomeArq,ios::out);// instanciando e abrindo o arquivo
    fstream arq("dados.txt");// instanciando e abrindo o arquivo

    if (arq.is_open()){
        string registro, token;
        string valores[3];
        int i, j, contToken, contRegistro;
        TItem x;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
               // cout << "Registro " << contRegistro << " completo: " << string(registro) << endl;
                token = ""; // LIMPA INICIAL

                for (j=0; j < 3;j++){ // LIMPA TODAS AS POSIÇÕES DO VETOR
                    valores[j] = token;
                }

                i=0;
                contToken=0;
                while (i <= int(registro.length())){  // PERCORRENDO O VETOR DE CHAR (REGISTRO)
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  PREENCHE A VARIÁVEL TOKEN
                    }
                    else{
                       valores[contToken] = token;  // PREENCHE E ARMAZENA NA POSIÇÃO CERTA
                                                    // para as 2 primeiras palavras
//                       inserir(p, p.raiz, valores);
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA

                    }
                    i++;
                }
                valores[contToken] = token; // para a última palavra/TOKEN, que não tem ; no final
                //for (j=0; j<3;j++){
                //    cout << "     Token " << j << ": " << valores[j] << endl;
                //}
                x.nome = valores[0];
                x.chave = atoi(valores[2].c_str());
                x.preco = atoi(valores[1].c_str());
                inserir(p, p.raiz, x);

                contRegistro++;
            }
        }
    }
}

void Olivaras(TArvoreBin &p){
system("cls");
lendoArq("dados.txt",p);
percorrerINOrdem(p.raiz);
int i;
cin >> i;
}

void FloreioseBorroes(TArvoreBin &p){

}

void FarmaciaMullpeppers(TArvoreBin &p){

}

//procedimento para mostrar o menu, com um switch case dentro de um do while
void menu(){
    int i;
    TArvoreBin Aprodutos;
    string nome="produtos";
    criarArvoreBinVazia(Aprodutos,nome);
    do{
        titulo();
        lojas();
        cout << "                                  Opção:";
        cin>>i;
        switch(i){
            case 1:
                Olivaras(Aprodutos);
            break;
            case 2:
                FloreioseBorroes(Aprodutos);
            break;
            case 3:
                FarmaciaMullpeppers(Aprodutos);
            break;
        }
        system("cls");
    }while(i!=4);
}

