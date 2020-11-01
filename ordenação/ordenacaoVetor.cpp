// feita por Felipe Gabriel da Silva - 475189

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>
#include "ordenacaoVetor.h"
using namespace std;

//VERIFICADOR 
// para verificar se realmente o vetor esta ordenado de forma crescente

int verifica (int v[], int n){
    if (n > 1) 
    for (int i = 1; i < n; i++) 
        if (v[i-1] > v[i]) 
            return 0;     
    return 1;
}

void verificador (int v[], int n){
    if(verifica(v,n))
        cout << "Foi ordenado com sucesso" <<endl;
    else
        cout << "Verifique o codigo de ordenação, pois não está ordenado!" <<endl;
}


void gera_dados(int num_iteracoes, const int vetor_tam[]){
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			string nome_arquivo = "dados/random"+ to_string(iteracao)+"_"+ to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); 
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); 
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

void ler_dados(int n, int arr[], const char *nomeArquivo){	
	ifstream fin(nomeArquivo, ios::binary); 
	for (int i = 0; i < n; i++){
		fin.read((char*)&arr[i], sizeof(int)); 
	}
	fin.close(); 
}

void menu(){
    cout<<"---------------------MENU DE VETOR--------------------"<<endl;
    cout<<"|           0 - Sair                                 |"<<endl;
    cout<<"|           1 - BubbleSort                           |"<<endl;
    cout<<"|           2 - Recursive BubleSort                  |"<<endl;
    cout<<"|           3 - InsertionSort                        |"<<endl;
    cout<<"|           4 - Recursive InsertionSort              |"<<endl;
    cout<<"|           5 - SelectionSort                        |"<<endl;
    cout<<"|           6 - Recursive SelectionSort              |"<<endl;
    cout<<"|           7 - MergeSort                            |"<<endl;
    cout<<"|           8 - Iterative MergeSort                  |"<<endl;
    cout<<"|           9 - HeapSort                             |"<<endl;
    cout<<"|          10 - Iterative HeapSort                   |"<<endl;
    cout<<"|          11 - QuickSort                            |"<<endl;
    cout<<"|          12 - Iterative QuickSort                  |"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"INFORME A OPÇÃO DESEJADA:";
}
void menuLista(){
    cout<<"#-------------- Menu --------------#"<<endl;
    cout<<"#                                  #"<<endl;
    cout<<"#[1] - Ordenar com bubblesort      #"<<endl;
    cout<<"#[2] - Ordenar com insertionsort   #"<<endl;
    cout<<"#[3] - Ordenar com selectionsort   #"<<endl;
    cout<<"#[5] - Sair                        #"<<endl;
    cout<<"#                                  #"<<endl;
    cout<<"#----------------------------------#"<<endl;
    cout<<"Sua opção: ";
}



// ==========================================================BubbleSort===================================================================

// bubblesort iterativo
void BubbleSort(int n, int arr[]) {   
    for (int i = 0; i < n-1; i++)      
		for (int j = 0; j < n-i-1; j++) // um for que vai até n-i-1, pois a  cada execução do for externo o ultimo termo é o maior 
            if (arr[j] > arr[j+1])  //verifica se arr[j] é maior
				swap(arr[j], arr[j+1]);  //troca
}


//bubblesort recursivo
void bubbleSortRecursive(int arr[], int n) { 
    //caso base quando o vetor só tem 1 termo ele já esta ordenado
    if (n == 1) 
        return; 
    
    // caso geral onde eu verifico todos os termos levando o maior para o final do vetor
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
    // chamado novamente a função recursivamente
    bubbleSortRecursive(arr, n-1); 
}


// ==========================================================insertionSort===================================================================


void insertionSort(int arr[], int n){  
    int i, key, j;

    for (i = 1; i < n; i++){  
        //key recebe arr[i] sempre que o for inicia
        key = arr[i];  
        //j recebe i-1, para comparar 
        j = i - 1;  
        //enquanato j maior ou igual a 0 e arr[j] > key, que armazena sempre  o arr[i] para levar ele até sua posição correta
        while (j >= 0 && arr[j] > key){  
            arr[j + 1] = arr[j];  // enquanto o while for satisfeito vai jogar, arr[j] para o final do vetor e assim trazendo key 
            j--; 
        }  // acaba quando o key estiver após um numero menor que ele
        arr[j + 1] = key;  // armazena o key na sua posição
    }  
}  
void insertionSortRecursive(int arr[], int n) { 
    // caso base onde n <= 1, return
    if (n <= 1) 
        return; 
    //chamada da função recursiva até que o caso base seja satisfeito.
    insertionSortRecursive( arr, n-1 ); 
    // estrutura basica de ordenação já demonstrada no insertionsort acima
    int last = arr[n-1]; 
    int j = n-2; 
    // while responsavel de rearranjar os termos de forma crescente
    while (j >= 0 && arr[j] > last) { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last; 
} 


// ==========================================================selectionSort===================================================================


void selectionSort(int arr[], int n)  {  
    int i, j, min_idx;
    //for que ira percorrer o vetor
    for (i = 0; i < n-1; i++){  
        min_idx = i; // o primeiro item do vetor é armazenado como o menor valor. 
        for (j = i+1; j < n; j++)  // for que ira de i+1 até n, verificando e atualizando o menor valor
            if (arr[j] < arr[min_idx])  
                min_idx = j;   // caso o valor do menor seja maior do que o valor do arr[j], o min_idx é atualizado com a posição do atual menor
        swap(arr[min_idx], arr[i]);  // a troca é feita
    }  
}  

int minIndex(int a[], int i, int j) { 
    if (i == j) 
        return i; 
  
    int k = minIndex(a, i + 1, j); 
  
    return (a[i] < a[k])? i : k; 
} 
  
void recurSelectionSort(int a[], int n, int index = 0){ 
    // caso base onde index == n
    if (index == n) 
       return; 
    // chamada da função minIndex, e armazena o index do menor valor do vetor
    int k = minIndex(a, index, n-1); 
    
    //se k diferente de index existe um valor menor que o primeiro termo
    if (k != index) 
       swap(a[k], a[index]); // caso o if seja satisfeito, a troca do menor valor para a[index]
       //ou o primeiro lugar do vetor dentro da função recursiva
  
    recurSelectionSort(a, n, index + 1); // chamada da função recursiva adicionando ao index + 1
    // pois o menor valor já está no primeiro lugar do vetor
} 




// ==========================================================MergeSort===================================================================


void merge(int arr[], int l, int m, int r); 

//função recusiva que ira separar o vetor para assim dar origem ao mergesort
void mergeSort(int arr[], int l, int r){ 
   if (l < r){ 
      int m = l+(r-l)/2;  
      mergeSort(arr, l, m); 
      mergeSort(arr, m+1, r); 
      merge(arr, l, m, r); 
   } 
} 
  
void merge(int arr[], int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    //vetore auxilirares
    int L[n1], R[n2]; 
    
    // armazeno o vetor nos vetores auxiliares
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    //reseto os indices auxiliares
    i = 0; 
    j = 0; 
    k = l; 
    
    //enquanto i< n1 e j<n2
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ // se L[i] for menor ou igual que  R[j]
            arr[k] = L[i]; //joga L[i] para arr[k]
            i++; 
        } 
        else{ // se não R[j] é menor
            arr[k] = R[j]; 
            j++; 
        } 
        k++; // incremento k
    } 
    
    //faço isso para caso algum dos lados acabe mas o outro ainda possua termos
    while (i < n1){ 
        arr[k] = L[i]; 
        i++;   
        k++; 
    } 
    // para ambos os lados
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void itemergeSort(int arr[], int n){ 
   int curr_size;   
   int left_start;  
   

   //funciona da mesma forme que o mergesort recursivo porem ele já
   // passa arranjando em pares de 1, 2, 4 assim sucessivamente, com os valores de curr_size e left_start 
   //chamando a função merge que faz o trabalho de ordenar 
   for (curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size){ 
       for (left_start = 0; left_start < n-1; left_start += 2*curr_size) { 
           
           int mid = min(left_start + curr_size - 1, n-1); 
  
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  
           merge(arr, left_start, mid, right_end); 
       } 
   } 
} 



// ==========================================================HeapSort===================================================================

void peneira (int A[], int n) {
    int f = 2;
    while (f <= n) {
        if (f < n && A[f] < A[f+1])
            f++;
    
        if (A[f/2] >= A[f])
            break ;
        std :: swap(A[f/2] , A[f]);
        f = f*2;
    }
}
  
void heapsort (int A[], int n) {
    constroiHeap (A, n);
    for (int k = n; k >= 2; k--) {
        std :: swap(A[1] , A[k]);
        peneira (A, k -1);
    }
}

void constroiHeap (int A[], int n) {
    for (int k = 1; k < n; k++) {
        int f = k + 1;
        while (f > 1 && A[f/2] < A[f]) {
            int aux = A[f/2];
            A[f/2] = A[f];
            A[f] = aux;
            f = f/2;
        }
    }
}
  
void iteheapSort(int arr[], int n){ 
    constroiHeap(arr, n); 
  
    for (int i = n - 1; i > 0; i--){ 
        swap(arr[0], arr[i]); 
        
        int j = 0, index; 
          
        do{ 
            index = (2 * j + 1); 
              
            if (arr[index] < arr[index + 1] && index < (i - 1)) 
                index++; 
          
            if (arr[j] < arr[index] && index < i) 
                swap(arr[j], arr[index]); 
          
            j = index; 
          
        } while (index < i); 
    } 
} 
// ==========================================================QuickSort======================================================================

int separa (int arr[], int p, int r) {
    int c = arr[r];//pega valor na posição r
    int j = p;// armazena o index p
    for (int k = p; k < r; k++) {
        if (arr[k] <= c) {// verifica se arr[k] é maior ou igual que o pivo
            std::swap(arr[k], arr[j]);//efetua a troca
            j++;
        }
    }
    arr[r] = arr[j];//leva o pivo para o meio dos termos,onde é o seu lugar
    arr[j] = c;
    return j; //return o indice j
}

void quicksort(int arr[], int p, int r) {
    if (p < r) {
        int i = separa(arr, p, r);// função separa, para separar os termos e colocar o pivo em seu lugar
        quicksort(arr, p, i-1);// chama a função para a outra metade excluindo o pivo que já esta em seu local
        quicksort(arr, i+1, r);
    }
}

  
void quickSortIterative(int arr[], int l, int h){ 
    int stack[h - l + 1]; 

    int top = -1; 
  
    stack[++top] = l; // armazena l e h
    stack[++top] = h; 
  
    //enquanto top maior ou igual a 0
    while (top >= 0) { 
        h = stack[top--]; 
        l = stack[top--]; 

        // armazena o index do pivo separado
        int p = separa(arr, l, h); 
  
        if (p - 1 > l) { //se p-1 for maior que l
            stack[++top] = l; //armazena na pilha
            stack[++top] = p - 1; //armazena na pilha
        } 
  
        if (p + 1 < h) { // se p+1 menor que h
            stack[++top] = p + 1; // armazena na pilha
            stack[++top] = h; //armazena na pilha
        } 
    } 
} 