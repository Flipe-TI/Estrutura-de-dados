#ifndef ORDENACAOVETOR_H
#define ORDENACAOVETOR_H
// feita por Felipe Gabriel da Silva - 475189
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>

void BubbleSort(int n, int A[]);
void bubbleSortRecursive(int arr[], int n);

void insertionSort(int arr[], int n);
void insertionSortRecursive(int arr[], int n);

void selectionSort(int arr[], int n);
int minIndex(int a[], int i, int j);
void recurSelectionSort(int a[], int n, int index);

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void itemergeSort(int arr[], int n);

void peneira (int A[], int n);
void heapsort (int A[], int n);
void constroiHeap (int A[], int n);
void iteheapSort(int arr[], int n);

int separa (int A[], int p, int r);
void quicksort(int A[], int p, int r); 
int partition(int arr[], int l, int h);
void quickSortIterative(int arr[], int l, int h);

int verifica (int v[], int n);
void verificador (int v[], int n);
void gera_dados(int num_iteracoes, const int vetor_tam[]);
void ler_dados(int n, int A[], const char *nomeArquivo);
void menu();
void menuLista();
#endif