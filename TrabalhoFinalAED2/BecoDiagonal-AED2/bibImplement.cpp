#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include "bibAssinaturas.h"
using namespace std;



// opera��es da arvore bin�ria
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
                cout << "N�o posso inserir. Item j� existe!" << endl;
            }
        }

    }
}

void mostrarprod(TNo *&no){
    if(no!=NULL){
        mostrarprod(no->esquerda);
        cout << "--==|| Produto: " << no->item.nome << " | ";
        cout << "Gale�es: " << no->item.preco << " | ";
        cout << "C�digo: " << no->item.chave << " ||==--"<<endl;
        mostrarprod(no->direita);
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
cout << "            --==m�gicos necess�rios para seus feiti�os e po��es!!==--"<<endl;
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
//Floreios o Borr�es
cout << "    --==||       __     __                     __                     ||==--"<<endl;
cout << "    --==||        _) _ |_ | _  _ _. _  _   _  |__) _  _ _ ~  _ _      ||==--"<<endl;
cout << "    --==||       /__   |  |(_)| (-|(_)_)  (-  |__)(_)| | (_)(-_)      ||==--"<<endl;
//Farm�cia Mullpeppers
cout << "    --==||   __     __                                                ||==--"<<endl;
cout << "    --==||    _) _ |__ _  _ _  ,  _. _   |\\/|   || _  _ _  _  _ _ _   ||==--"<<endl;
cout << "    --==||   __)   |  (_|| |||(_|(_|(_|  |  ||_||||_)(-|_)|_)(-| _)   ||==--"<<endl;
cout << "    --==||________________________________________|____|__|___________||==--"<<endl<<endl;
cout << "                      --==4-Para sair do Beco Diagonal==--"<<endl<<endl;
}

// LENDO DO ARQUIVO E UTILIZANDO NA MEM�RIA
int lendoArq(string nomeArq, TArvoreBin &p){

    fstream arq(nomeArq.c_str());// instanciando e abrindo o arquivo
    //fstream arq("olivaras.txt");// instanciando e abrindo o arquivo

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

                for (j=0; j < 3;j++){ // LIMPA TODAS AS POSI��ES DO VETOR
                    valores[j] = token;
                }

                i=0;
                contToken=0;
                while (i <= int(registro.length())){  // PERCORRENDO O VETOR DE CHAR (REGISTRO)
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  PREENCHE A VARI�VEL TOKEN
                    }
                    else{
                       valores[contToken] = token;  // PREENCHE E ARMAZENA NA POSI��O CERTA
                                                    // para as 2 primeiras palavras
//                       inserir(p, p.raiz, valores);
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA

                    }
                    i++;
                }
                valores[contToken] = token; // para a �ltima palavra/TOKEN, que n�o tem ; no final
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
string arq = "olivaras.txt";
system("cls");
lendoArq(arq,p);
mostrarprod(p.raiz);
int i;
cin >>i;
}

void FloreioseBorroes(TArvoreBin &p){
string arq = "floreioseborroes.txt";
system("cls");
lendoArq(arq,p);
mostrarprod(p.raiz);
int i;
cin >> i;
}

void FarmaciaMullpeppers(TArvoreBin &p){
string arq = "farmaciamulpeppers.txt";
system("cls");
lendoArq(arq,p);
mostrarprod(p.raiz);
int i;
cin >> i;
}

//procedimento para mostrar o menu, com um switch case dentro de um do while
void menu(){
    int i;
    TArvoreBin Avarinhas, Alivros, Apocoes;
    string nome="varinhas";
    criarArvoreBinVazia(Avarinhas,nome);
    nome="livros";
    criarArvoreBinVazia(Alivros,nome);
    nome="pocoes";
    criarArvoreBinVazia(Apocoes,nome);

    do{
        titulo();
        lojas();
        cout << "                                  Op��o:";
        cin>>i;
        switch(i){
            case 1:
                Olivaras(Avarinhas);
            break;
            case 2:
                FloreioseBorroes(Alivros);
            break;
            case 3:
                FarmaciaMullpeppers(Apocoes);
            break;
        }
        system("cls");
    }while(i!=4);
}

