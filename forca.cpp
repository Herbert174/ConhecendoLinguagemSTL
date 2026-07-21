#include <iostream>
#include <string> //necessario para utilizar variaveis do tipo string

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
bool nao_acerto = true;
bool nao_enforcou = true;

bool jogoterminou(){
    if(nao_acerto && nao_enforcou)
        return true;
    return false;
}

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

int main(){
    cout << PALAVRA_SECRETA << endl;

    while(jogoterminou()){
        char chute;
        cin >> chute;

        if(letra_existe(chute)){
            cout << "voce acertou seu chute esta na palavra" << endl;
        }else{
            cout << "voce errou seu chute nao esta na palavra" << endl;
        }
    }
}