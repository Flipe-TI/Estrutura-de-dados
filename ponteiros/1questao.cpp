// Felipe Gabriel da Silva - 475189

#include <iostream>
using namespace std;

void  troca (int *a, int *b){
  // ultilizei o int c como auxiliar, armazenando nele o *a e assim podendo fazer a troca com *b
  int c = *a;
  *a = *b;
  *b = c;
    
}
int main(){
  int primeiro, segundo;
  
  cout <<"informe o primeiro numero:"<<endl;
  cin >> primeiro;
  cout <<"informe o segundo numero:"<<endl;
  cin >> segundo;
  troca(&primeiro, &segundo);
  
  cout << "Valor do primeiro = " << primeiro <<" e valor do segundo = "<< segundo <<endl;
  
  
  return 0;

}