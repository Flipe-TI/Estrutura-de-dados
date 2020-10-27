// Felipe Gabriel da Silva - 475189

#include <iostream>
using namespace std;

char *strcpy(char *destino, char *origem){
    int i;
    // for para verficar a quantidade de caracteres no char origem e assim armazenar no inteiro i.
    for (i = 0; origem[i] != '\0'; i++)
    // for para copiar origem para destino caracter por caracter e no final do char colocar o digito terminador que é o \0
    for (int j = 0; j <= i; j++)
        destino[j] = origem[j];
    destino[i+1] = '\0';

    return destino;
}

int main(){
    char destino[100] = "vazio", origem[100]; // destino é inicializado cotendo "vazio", para melhor entendimento e verificação.
    // peço para o usuario informar o texto que deseja ser copiado para destino
    cout <<"digite o texto desejado: "<< endl;
    cin >> origem;
    cout << "esse é origem: "<< origem<< " e esse é destino: " << destino<< "." <<endl; 
    
    strcpy(destino,origem);

    cout << "esse é origem: "<< origem << ", após a troca, esse é destino: " << destino << "." <<endl;
    


    
}