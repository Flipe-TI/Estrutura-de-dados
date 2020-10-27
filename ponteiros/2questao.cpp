// Felipe Gabriel da Silva - 475189

#include <iostream>
using namespace std;

void mm(int A[], int n, int *min, int *max){
    //nesse primeiro for percorro com o objetivo de armazenar somente o maior numero do vetor
    for (int i = 0; i < n; i++)
        if(A[i] >= *max) *max = A[i];
    /* em seguida faço min receber o maior valor do vetor para assim, novamente, 
    percorrer o vetor, so que agora em busca do menor valor possivel.*/    
    *min = *max;
    // aqui esta o for que percorre procurando um valor menor ou igual ao valor maximo do vetor.
    for (int i = 0; i < n; i++)
        if(A[i] <= *min) *min = A[i];
    
}
int main(){
  int n ,min, max = 0;
  // peço para que o usuario informe o tamanho do vetor.
  cout <<"informe a quantidade de termos do vetor"<<endl;
  cin >> n;
  
  int V[n];
  //percorro o vetor armazenando os numeros fornecido pelo o usuario.
  for (int i = 0; i < n; i++){
    cout <<"informe o numero a ser armazenado no vetor:"<<endl;
    cin >> V[i];
  }
  // chamo a função mm para assim ela me retornar os valores corretos para max e min
  mm(V, n, &min, &max);
  
  cout << "Maior numero fornecido foi: " << max << endl; 
  cout << "Menor numero fornecido foi: " << min << endl;
    return 0;

}