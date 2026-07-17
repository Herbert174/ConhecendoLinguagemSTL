#include <iostream> //biblioteca padrão utilizada para acessar as funções de entrada e saida em c++

using namespace std; //Utilizado para não precisar mais colocar o std:: toda vez que usar um recurso 
                     //de standart 
                     //DE std::cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << std::endl;
                     //PARA    cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << endl;

int main(){
    cout << "**************************************" << endl;
    cout << "* BEM-VINDOS AO JOGO DE ADIVINHACAO! *" << endl;
    cout << "**************************************" << endl;

    int numero_secreto = 19;
    cout << "O numero secreto e " << numero_secreto << " nao conte a ninguem" << endl;
    //sempre que quisermos passar uma variavel no cout quebrar o "" e então passar a variavel entre
    // << variavel << dessa forma invés de imprimir o nome da variavel será impresso o valor da mesma
}