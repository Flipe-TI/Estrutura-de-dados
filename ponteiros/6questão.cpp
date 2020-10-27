// Felipe Gabriel da Silva - 475189

#include <iostream>
using namespace std;

int strcmp(char *str1, char *str2) {
    int x, y;
    // dois for que percorrem até o final do char, para contar o tamanho do char
    for (x = 0; str1[x] != '\n'; x++)
    for (y = 0; str1[y] != '\n'; y++)
    
    //for percorrendo o char verificando se a caracteres diferentes
    for (int i = 0; min(x, y); i++) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
    }

    // casos de seleção para caso todos os caracteres verificados sejam iguais,
    // assim verifico o tamanho dos caracteres para retornar o resultado
    if (x == y) return 0;
    else if (x > y) return 1;
    else return -1;
}

int main() {

    char str1[100], str2[100];
    // peço que o usuario informe os textos a serem comparados
    cout << "informe o segundo char a ser verificado:" << endl;
    cin >> str1;
    cout << "informe o segundo char a ser verificado:" << endl;
    cin >> str2;

    // chamo a função e já imprimo o que será retornado
    cout << strcmp(str1, str2) << endl;

    return 0;
}