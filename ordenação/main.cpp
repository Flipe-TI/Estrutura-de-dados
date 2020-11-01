#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>
#include "ordenacaoVetor.h"
#include "ordenacaoLista.h"

using namespace std;


int main() {//essa parte da main para vetor foi feita por: Felipe gabriel da silva - 475189
    cout<<"[1] - Ordenar Vetor"<<endl;
    cout<<"[2] - Ordenar Lista"<<endl;
    int esc;
    cin>>esc;
    if(esc == 1){
        int op = 0;
        string tipo_ordenacao;
        menu();
        cin >> op;
        
        //fiz testes com os valores no arquivo de exemplo pois meu pc não aguentou o bubble sorte
        // com esses valores recomendado no pdf, ele simplesmente travou, pelo fato do meu pc ser antigo
        
        const int tam[] = {1000, 5000, 10000, 50000, 100000,500000, 1000000};//500,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,20000};
        
        int TOTAL_N = sizeof(tam)/sizeof(tam[0]); 
        
        gera_dados(TOTAL_N, tam);

        while(op != 0){
                switch (op){
                    case 1:
                        tipo_ordenacao = "Bubble";
                        break;
                    case 2:
                        tipo_ordenacao = "Bubble Recursive";
                        break;
                    case 3:
                        tipo_ordenacao = "Insertion";
                        break;
                    case 4:
                        tipo_ordenacao = "Insertion  Recursive";
                        break;
                    case 5:
                        tipo_ordenacao = "Selection";
                        break;
                    case 6:
                        tipo_ordenacao = "Selection Recursive";
                        break;
                    case 7:
                        tipo_ordenacao = "Merge";
                        break;
                    case 8:
                        tipo_ordenacao = "Merge Iterative";
                        break;
                    case 9:
                        tipo_ordenacao = "Heap";
                        break;
                    case 10:
                        tipo_ordenacao = "Heap iterative";
                        break;
                    case 11:
                        tipo_ordenacao = "Quick";
                        break;
                    case 12:
                        tipo_ordenacao = "Quick Iterative";
                        break;
                    default:
                        break;
                }
            std::ofstream ofs("resultados/resultado" + tipo_ordenacao + ".txt", std::ofstream::out ); 
            
            for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
                
                long double duracao_media = 0.0;
                int tamanho_vetor = tam[iteracao]; 
                int vetor[tamanho_vetor]; 
                
                for(int semente = 0; semente < 5; semente++) 
                {	
                    string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
                
                    ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
                    
                    auto ini = std::chrono::high_resolution_clock::now();
                    
                    switch (op){
                        case 1:
                            BubbleSort(tamanho_vetor, vetor);
                            break;
                        case 2:
                            bubbleSortRecursive(vetor,tamanho_vetor);
                            break;
                        case 3:
                            insertionSort(vetor, tamanho_vetor);
                            break;
                        case 4:
                            insertionSortRecursive(vetor, tamanho_vetor);
                            break;
                        case 5:
                            selectionSort(vetor, tamanho_vetor);
                            break;
                        case 6:
                            recurSelectionSort(vetor, tamanho_vetor, 0);
                            break;
                        case 7:
                            mergeSort(vetor, 0, tamanho_vetor);
                            break;
                        case 8:
                            itemergeSort(vetor, tamanho_vetor);
                            break;
                        case 9:
                            heapsort(vetor, tamanho_vetor);
                            break;
                        case 10:
                            iteheapSort(vetor, tamanho_vetor);
                            break;
                        case 11:
                            quicksort(vetor, 0, tamanho_vetor);
                            break;
                        case 12:
                            quickSortIterative(vetor, 0, tamanho_vetor);
                            break;
                        
                        default:
                            break;
                    }
                
                    auto fim = std::chrono::high_resolution_clock::now();
                
                    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
                    
                    duracao_media += duracao;
                    
                }
                
                duracao_media = duracao_media / 5.0;
                cout << "[" << tipo_ordenacao << "] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media << " microssegundos" << endl;
                
                //verificador para verificar se realmente esta ordenado
                verificador(vetor,tamanho_vetor);

                ofs << tamanho_vetor << " " << duracao_media << "\n"; 
            }
            ofs.close();
            menu();
            cin >> op;   
        }
    }else if(esc == 2){
        // parte da lista duplamente encadeada, feita por Ulisses Queiroz da Silva - 471285

        bool rodar = true;
        int op;
        const int tam[] = {500,1000,2000,3000,4000,5000};
        int TOTAL_N = sizeof(tam)/sizeof(tam[0]);
        gera_dados(TOTAL_N, tam);    
        MG_Lista *l = new MG_Lista();


        while (rodar){        
        menuLista();
        cin>>op;
        if(op == 1){
            system("clear");       
            std::ofstream ofs("resultados/resultadoBubblesort.txt", std::ofstream::out );
            for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
                long double duracao_media_cocktail = 0.0;
                int tamanho_vetor = tam[iteracao];
                int vetor[tamanho_vetor];

                for(int semente = 0; semente < 5; semente++){
                    string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";		
                    ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
                    for(int i = 0; i < tamanho_vetor; i++){
                        l->add(vetor[i]);
                    }
        

                    auto ini = std::chrono::high_resolution_clock::now();
                    l->bubblesort();
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
                    duracao_media_cocktail += duracao_cocktail;
                }
                duracao_media_cocktail = duracao_media_cocktail / 5.0;
                cout << "[Bubblesort] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_cocktail << " microssegundos" << endl;
                ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n"; 
                cout << "Ordenado com sucesso"<<endl;    
            }
            ofs.close();
        }else if(op == 2){
            std::ofstream ofs("resultados/resultadoInsertionsort.txt", std::ofstream::out );
            system("clear");
            for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
                long double duracao_media_cocktail = 0.0;
                int tamanho_vetor = tam[iteracao];
                int vetor[tamanho_vetor];

                for(int semente = 0; semente < 5; semente++){
                    string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";		
                    ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
                    for(int i = 0; i < tamanho_vetor; i++){
                        l->add(vetor[i]);
                    }
                    

                    auto ini = std::chrono::high_resolution_clock::now();
                    l->insertionsort();
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
                    duracao_media_cocktail += duracao_cocktail;
                }
                duracao_media_cocktail = duracao_media_cocktail / 5.0;
                cout << "[Insertionsort] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_cocktail << " microssegundos" << endl;
                ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n";        
                cout << "Ordenado com sucesso" <<endl;
            }
            ofs.close();
        }else if(op == 3){
            std::ofstream ofs("resultados/resultadoSelectionsort.txt", std::ofstream::out );
            system("clear");
            for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
                long double duracao_media_cocktail = 0.0;
                int tamanho_vetor = tam[iteracao];
                int vetor[tamanho_vetor];

                for(int semente = 0; semente < 5; semente++){
                    string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";		
                    ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
                    for(int i = 0; i < tamanho_vetor; i++){
                        l->add(vetor[i]);
                    }

                    auto ini = std::chrono::high_resolution_clock::now();
                    l->selectionsort();
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
                    duracao_media_cocktail += duracao_cocktail;
                }
                duracao_media_cocktail = duracao_media_cocktail / 5.0;
                cout << "[Selectionsort] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_cocktail << " microssegundos" << endl;
                ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n";        
                cout << "Ordenado com sucesso"<<endl;
            }
            ofs.close();
            }else{
                rodar = false;
            }
        
        }
    }
    

}