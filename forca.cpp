#include <iostream>
#include <string> //necessario para utilizar variaveis do tipo string
#include <map>    //necessario para utilizar variaveis do tipo map
#include <vector> //necessario para utilizar variaveis do tipo vector

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> chutou;
vector<char> chutes_errados;


bool letra_existe(char chute){
    /*for(int i = 0; i < PALAVRA_SECRETA.size(); i++){
        if(chute == PALAVRA_SECRETA[i]){
            return true;
        }
    }*/                                         
    for(char letra : PALAVRA_SECRETA){  //Esse for é o equivalente ao for comentado a cima onde letra
        if(chute == letra)              //é igual a PALAVRA_SECRETA[i] ou seja letra varre toda a string
            return true;
    }                             //Por utilizar um recurso do C++11 pode ser necessario explicitar
    return false;                 //o seu uso na hora de compilar ex. g++forca.cpp -o forca.out -std=c++11
}                                 //Criando um arquivo chamado Makefile e atribuindo a flag -std=c++11
                                  //Podemos contornar esse comando extenso de compilação simplificando
                                  //para mingw32-make ARQUIVO sem a extensão ex. mingw32-make forca

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

bool jogonaoterminou(){
    if(nao_acertou() && nao_enforcou())
        return true;
    return false;
}

void imprime_cabecalho(){
    cout << "***********************" << endl;
    cout << "**** JOGO DA FORCA ****" << endl;
    cout << "***********************" << endl;
    cout << endl;
}

void imprime_chutes_errados(){
    cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra_secreta(){
    for(char letra : PALAVRA_SECRETA){  //letra só existe no for, ele varrerá toda PALAVRA_SECRETA
        if(chutou[letra]){              //caso alguma das letras presentes em PALAVRA_SECRETA estejam
            cout << letra << " ";       //no map chutou, ele imprime a letra, caso contrario imprime _ 
        }else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta_letra(){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        cout << "voce acertou seu chute esta na palavra" << endl;
    }else{
        cout << "voce errou seu chute nao esta na palavra" << endl;
        chutes_errados.push_back(chute); //Insere uma informação em um vector no final da lista
    }
    cout << endl;
}

void imprimindo_finalizacao(){
    cout << "Fim de jogo" << endl;
    cout << "A palavra secreta era " << PALAVRA_SECRETA << endl;
    if(nao_acertou()){
        cout << "Voce perdeu! Tente novamente" << endl;
    }else{
        cout << "Parabens voce acertou a palavra secreta!" << endl;
    }
}

int main(){
    imprime_cabecalho();
    while(jogonaoterminou()){
        imprime_chutes_errados();
        imprime_palavra_secreta();
        chuta_letra();
    }
    imprimindo_finalizacao();
}