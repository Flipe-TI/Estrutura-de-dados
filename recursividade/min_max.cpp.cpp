#include <iostream>
using namespace std;
// função para verificar o maior numero que existe no vetor aplicando a recursividade
int maximo(int n, int v[]) {
    if (n == 1) //caso base onde o vetor so possui um elemento, e ele é o maior elemento do atual vetor
        return v[0];
    else {
        int max;
        max = maximo(n-1, v);// chamo novamente a função, para assim ele receber o valor do caso base 
        if (max > v[n -1])// verifica, qual dos termos é maior assim retornando max, caso max seja maior
            return max;
        else
            return v[n -1];// caso contrario retorna o elemento maior
    }
}
//esta função funciona da mesma forma só que de forma retornar sempre o menor elemento do vetor
int minimo(int n, int v[]){
    if (n == 1)
        return v[0];
    else {
        int min;
        min = minimo(n-1, v);
        if (min < v[n -1])
            return min;
        else
            return v[n -1];
    }
}
int main(){
    int n = 0;
    int min = 0, maxi = 0;
    cout << "informe o tamanho do vetor:" << endl;
    cin >> n;
    int v[n];

    for (int i = 0; i < n; i++){
        cout << "informe o numero a ser armazenado no vetor:" << endl;
        cin >> v[i];
    }

    maxi = maximo(n, v);
    min = minimo(n, v);

    

    cout <<"Este é a diferença entre o maximo e o minimo do vetor: "<< maxi-min << endl;

    return 0;
}