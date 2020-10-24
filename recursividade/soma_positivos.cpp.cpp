#include <iostream>
using namespace std;
int soma_positivos(int v[], int n){     
    if(n == 0)// caso base, caso o vetor não tenha nenhum elemento a soma seria igual a zero
        return 0;
    else{
        if(v[n-1] < 0)// verificação para caso o numero seja negativo, ao inves de somar ao numero negativo somo a 0 que anula o numero negativo
            return 0 + soma_positivos(v, n-1);
        else
            return v[n-1] + soma_positivos(v, n-1);// a soma somente dos elementos positvos é feita apartir daqui
    }

}

int main(){
    int n;
    cout << "informe o tamanho do vetor:" << endl;
    cin >> n;
    int v[n];

    for (int i = 0; i < n; i++){
        cout << "informe o numero a ser armazenado no vetor:" << endl;
        cin >> v[i];
    }

    cout << soma_positivos(v, n) << endl;

    return 0;
}