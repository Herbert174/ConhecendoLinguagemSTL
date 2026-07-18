#include <iostream> //biblioteca padrão utilizada para acessar as funções de entrada e saida em c++

using namespace std; //Utilizado para não precisar mais colocar o std:: toda vez que usar um recurso 
                     //de standart 
                     //DE std::cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << std::endl;
                     //PARA    cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << endl;

int main(){
    cout << "**************************************" << endl;
    cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << endl;
    cout << "**************************************" << endl;

    const int NUMERO_SECRETO = 19; //É uma convenção declarar constantes sempre em capslock

    //cout << "O numero secreto e " << numero_secreto << " nao conte a ninguem" << endl;
    //sempre que quisermos passar uma variavel no cout quebrar o "" e então passar a variavel entre
    // << variavel << dessa forma invés de imprimir o nome da variavel será impresso o valor da mesma

    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    while(nao_acertou){
        tentativas++;
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute ";
        cin >> chute;
        cout << "O valor do seu chute e " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;    //boas praticas colocar a condicional a ser verificada em uma variavel
        bool chutemaior = chute > NUMERO_SECRETO;  //com nome que descreve o que ele representa para utiliza-lo no respectivo
        bool chutemenor = chute < NUMERO_SECRETO;  //if, dessa forma o codigo fica mais facil de entender

        if(acertou){
            cout << "Parabens voce acertou o numero secreto" << endl;
            nao_acertou = false;
        }else if(chutemaior){
            cout << "O seu chute e maior que o numero secreto" << endl;
        }else{
            cout << "O seu chute e menor que o numero secreto" << endl;
        }
        cout << endl;
    }
    cout << "Fim de jogo!" << endl;
    cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
    cout.precision(2); //Define o nivel de precisao a ser utilizado na impressão da variavel no proximo cout
    cout << fixed;     //Formata o valor a ser imprimido no cout  //ex. 956.00 (2 casas depois da , pelo precision)
    cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
}