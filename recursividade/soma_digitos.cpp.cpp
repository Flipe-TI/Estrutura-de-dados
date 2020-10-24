#include <iostream>
using namespace std;
int soma_digitos(int num){     
   if(num%10)// se houver um resto da divisão por 10
        return num%10 + soma_digitos(num/10);// adiciona o valor do resto da divisão por 10 que é exatamente o digito mais a direita do numero e o adiciona ao proximo
   else 
        return num;// se não houver um resto da divisão o numero possui somente um digito assim retorno somente ele

}

int main(){
    int n;
    cout << "informe o numero" << endl;
    cin >> n;

    cout <<"Esse é a soma dos digistos informados:"<< soma_digitos(n) << endl;

    return 0;
}
