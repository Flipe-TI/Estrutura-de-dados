#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "informe a quantidade de elementos: " << endl;
    cin >> n;
    int v[n];
    //for para armazenar os numeros que o usuario informar
    for (int i = 0; i < n; i++){
        cout << "informe o elemento que deseja armazenar:" << endl;
        cin >> v[i];
    }
    //for para imprimir, ele parte de n-1, enquanto for maior ou igual a 0 vai imprimir os valores do vetor
    for (int i = n-1 ; i >= 0; i--){
        cout << v[i] << endl;
    }

    return 0;
}