#include <iostream>
#include <string>  //necessario para utilizar variaveis do tipo string
#include <map>     //necessario para utilizar variaveis do tipo map
#include <vector>  //necessario para utilizar variaveis do tipo vector
#include <fstream> //necessario para utilizar a biblioteca do ifstream, fluxo de dados de arquivos
#include <ctime>   //necessario para utilizar o time 0 para setar a seed de random
#include <cstdlib> //necessario para utilizar as funções de random

using namespace std;

string palavra_secreta = "MELANCIA";

map<char, bool> chutou;
vector<char> chutes_errados;

vector<string> le_arquivo();


bool letra_existe(char chute){
    /*for(int i = 0; i < palavra_secreta.size(); i++){
        if(chute == palavra_secreta[i]){
            return true;
        }
    }*/                                         
    for(char letra : palavra_secreta){  //Esse for é o equivalente ao for comentado a cima onde letra
        if(chute == letra)              //é igual a palavra_secreta[i] ou seja letra varre toda a string
            return true;
    }                             //Por utilizar um recurso do C++11 pode ser necessario explicitar
    return false;                 //o seu uso na hora de compilar ex. g++forca.cpp -o forca.out -std=c++11
}                                 //Criando um arquivo chamado Makefile e atribuindo a flag -std=c++11
                                  //Podemos contornar esse comando extenso de compilação simplificando
                                  //para mingw32-make ARQUIVO sem a extensão ex. mingw32-make forca

bool nao_acertou(){
    for(char letra : palavra_secreta){
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
    for(char letra : palavra_secreta){  //letra só existe no for, ele varrerá toda palavra_secreta
        if(chutou[letra]){              //caso alguma das letras presentes em palavra_secreta estejam
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

    chutou[chute] = true;       //adicionando chute do usuario ao map chutou

    if(letra_existe(chute)){
        cout << "voce acertou seu chute esta na palavra" << endl;
    }else{
        cout << "voce errou seu chute nao esta na palavra" << endl;
        chutes_errados.push_back(chute); //Insere uma informação em um vector no final da lista
    }
    cout << endl;
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;  //Inicializa arquivo porém voltado para escrita OUTPUT ofstream
    arquivo.open("palavras.txt"); //Abre o arquivo palavras.txt
    if(arquivo.is_open()){        //Verifica se o mesmo foi encontrado e conseguiu ser aberto
        arquivo << nova_lista.size() << endl;  //Reescreve o valor da linha 0 (quantidade de palavras) pelo novo valor
        for(string palavra : nova_lista){   //passa por cada palavra do vetor nova_lista
            arquivo << palavra << endl;     //E escreve << cada string do vetor nova_lista no arquivo palavras.txt
        }
        arquivo.close(); //Fecha o arquivo após terminar de utiliza-lo
    }else{
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0); //Para execução do codigo
    }
}

void adiciona_palavra(){
    cout << "Digite a nova palavra, usando letras maiusculas." << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

void imprimindo_finalizacao(){
    cout << "Fim de jogo" << endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Voce perdeu! Tente novamente" << endl;
    }else{
        cout << "Parabens voce acertou a palavra secreta!" << endl;
        cout << "Voce deseja adicionar uma nova palavra? (S/N)" << endl;
        
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){ //utilizar aspas simples quando queremos trabalhar com caracteres
            adiciona_palavra();
        }
    }
}

vector<string> le_arquivo(){  //definido que o retorno da função será um vetor de strings
    ifstream arquivo;               //instanciado a variavel arquivo
    arquivo.open("palavras.txt");   //abrindo arquivo palavras.txt

    if(arquivo.is_open()){    //Verifica se o arquivo está aberto / foi encontrado
        int qntd_palavras;
        arquivo >> qntd_palavras;       //lendo a primeira palavra de arquivo (palavras.txt) e guardando na variavel

        vector<string> palavras_do_arquivo;

        for(int i=0; i<qntd_palavras; i++){
            string palavra_lida;          //declara uma string para guardar as informações do arquivo
            arquivo >> palavra_lida;      //guarda a palavra lida na string declarada
            palavras_do_arquivo.push_back(palavra_lida); //inserindo a palavra lida do arquivo no vetor de string declarado
        }
        arquivo.close();  //Sempre feche um arquivo depois de terminar de usa-lo
        return palavras_do_arquivo;   //retorna o vetor de string com todas as palavras lidas no arquivo
    }else{
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0); //Para execução do codigo
    }
}

void sorteia_palavra_secreta(){
    vector<string> palavras = le_arquivo();   //Chama le_arquivo e guarda no vetor palavras

    srand(time(0));
    int indice_sorteado = rand() % palavras.size(); //guarda um valor aleatorio baseado na quantidade de palavras no arquivo

    palavra_secreta = palavras[indice_sorteado];  //define a palavra secreta baseado no valor aleatorio gerado pelo rand
}

int main(){
    imprime_cabecalho();
    sorteia_palavra_secreta();
    while(jogonaoterminou()){
        imprime_chutes_errados();
        imprime_palavra_secreta();
        chuta_letra();
    }
    imprimindo_finalizacao();
}