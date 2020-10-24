#include <iostream>
using namespace std;

void piramide(int v[], int n){
    int aux[n]; // crio um vetor auxiliar   
    for(int i = 0; i < n; i++){
        aux[i] = v[i];// faço com que o auxiliar receba o vetor antes das modificações
    } 
    if(n == 0)//caso base, caso o numero de termos seja igual a 0 
        return;

    for(int i = 0; i < n-1; i++){
        v[i] += v[i + 1];// faço o somatorio dos termos do vetor
    }
 
    piramide(v, n - 1);// ativo a recursividade para assim começar o ciclo

    for(int i = 0; i < n; i++){
        cout << aux[i] << ", ";//printo o auxiliar para assim poder printar em forma de piramide 
    }cout << endl;
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
    
    piramide(v,n);

    return 0;
}
