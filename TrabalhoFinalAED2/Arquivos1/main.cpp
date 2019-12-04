#include <iostream>
#include <fstream>

using namespace std;

// LENDO DO ARQUIVO E UTILIZANDO NA MEMÓRIA
int lendoArq(string nomeArq, int quantTokens){

    //fstream arq(nomeArq,ios::out);// instanciando e abrindo o arquivo
    fstream arq("dados.txt");// instanciando e abrindo o arquivo

    if (arq.is_open()){
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken, contRegistro;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
                cout << "Registro " << contRegistro << " completo: " << string(registro) << endl;
                token = ""; // LIMPA INICIAL

                for (j=0; j < quantTokens;j++){ // LIMPA TODAS AS POSIÇÕES DO VETOR
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
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA

                    }
                    i++;
                }
                valores[contToken] = token; // para a última palavra/TOKEN, que não tem ; no final
                for (j=0; j<quantTokens;j++){
                    cout << "     Token " << j << ": " << valores[j] << endl;
                }
                contRegistro++;
            }
        }
    }
    else{
        cout << "Problemas com a abertura do arquivo!" << endl;
	return -1;
    }
    arq.close();
    return 0;
}

// PEGANDO DA MEMÓRIA E LEVANDO PARA O ARQUIVO
int escrevendoArq(string nomeArq, string vetDados[], int quantTokens){

    int i;
    string registro = "";
    //fstream arquivo(nomeArq,ios::ate|ios::in|ios::out);
    fstream arquivo("dados.txt",ios::ate|ios::in|ios::out);

    if (arquivo.is_open()){
        for (i=0; i<quantTokens;i++){   // MONTANDO NOSSO REGISTRO!
            if (i < quantTokens-1){
                registro = registro + vetDados[i] + ";";
            }
            else{
                registro = registro + vetDados[i] + "\n";
            }
        }
        arquivo << registro; // ESCREVE O REGISTRO NO ARQUIVO!
        arquivo.close();
        cout << "Dados inseridos com sucesso!" << endl;
        return 0;
    }
    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}

int main()
{
    string valores[3];

    lendoArq("dados.txt", 3);

    valores[0] = "Juca";
    valores[1] = "1";
    valores[2] = "55";

    escrevendoArq("dados.txt", valores,3);

    lendoArq("dados.txt",3);

    return 0;
}
