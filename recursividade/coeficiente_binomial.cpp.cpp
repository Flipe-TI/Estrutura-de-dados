#include <iostream>
using namespace std;

//essa é a função recursiva que calcula o fatorial de um numero.
int fat(int n){
    if(n < 2) return 1;
    else return(n*fat(n-1));
}
// essa função utiliza da função recursiva de fatorial para aplicar a equação de probabilidade.
int cb(int n, int k){ 
       return fat(n)/fat(k)/fat(n-k);
}

int main(){
    int n = 0, k = 0;

    cout <<"informe o N:"<< endl;
    cin >> n;
    cout <<"informe o K:"<< endl;
    cin >> k;


    cout << "Este é o coeficiente binomial: " << cb(n,k) << endl;
}