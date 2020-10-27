// Felipe Gabriel da Silva - 475189

#include <iostream>
using namespace std;

void MAX(int A[],int *n,int *k,int *l,int *c){
    // um for para percorrer as linhas e outro para percorrer as colunas da matriz
    for(int i = 0; i < *n; i++){
        for(int j = 0; j < *n; j++){
            if(A[i + (j * *n)]>= *k){ //trato a matriz como um vetor como foi explicado em sala uma matriz nada mais é do que um vetor, utilizei isso para melhor fixar
                *k = A[i + (j * *n)]; //recebo o maior valor encontrado até o momento da matriz
                *l = i; 
                *c = j; // e tambem armazeno  a sua localizaçao na matriz
            }
        }
    }
}
int main(){
    int n = 0,k = 0 ,l = 0, c = 0;
    cout << "informe o tamanho da matriz:"<< endl;//recebo o tamanho da matriz, que sempre vai ser quadrada.
    cin >> n;

    int A[n][n];
    // for para receber os valores da matriz
    for (int i = 0; i < n; i++){
        for ( int j = 0; j < n; j++){
            cout<< "informe o valor a ser armazenado na posição "<< i << " "<< j <<":" << endl;
            cin >> A[i][j];
        }
    }
    // chamo a função que armazenará o maior valor e sua localização nos inteiros 'k', 'l' e 'c'
    MAX(A[0], &n,&k,&l, &c);

    cout <<"Esse é o maior numero da matriz:"<< k <<endl;
    cout <<"Essa é a linha e a coluna do maior numero da matriz:"<< l<< "," << c <<endl;
}  