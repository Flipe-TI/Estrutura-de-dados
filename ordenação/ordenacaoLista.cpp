#include <bits/stdc++.h>
#include "ordenacaoLista.h"
#include <iostream>
using namespace std;

// feita por Ulisses Queiroz da Silva - 471285

struct Lista{
    int key;
    Lista *prev;
    Lista *next; 
};

MG_Lista::MG_Lista() {
    head = new Lista;
    head->key = 0;
    head->next = head;
    head->prev = head;
}

MG_Lista::~MG_Lista() {
    clear();
    delete head;
}


void MG_Lista::clear() {
    Lista *aux;
    while(head->next != head) {
        aux = head->next;
        head->next = aux->next;
        aux->next = head;
        std::cout << "Removendo " << aux->key << std::endl;
        delete aux;
    }
}

void MG_Lista::add(int x) {
    Lista *novo = new Lista();
    novo->key = x;
    novo->prev = head->prev;
    novo->next = head;
    head->prev->next = novo;
    head->prev = novo;    
}

Lista* MG_Lista::search(int x){
    Lista *node = head;
    while(node->next != head && (node->next)->key != x)
        node = node->next; 
    return (node->next == head) ? NULL : node;
}

void MG_Lista::remove(int x) {
    Lista *anterior = search(x);
    if(anterior != head) {
        Lista *aux;
        aux = anterior->next;
        anterior->next = aux->next;
        aux->next = head;
        delete aux;
    }
}

void MG_Lista::print(){
    Lista *aux = head->next;
    while(aux != head) {
        std::cout << aux->key <<endl;
        aux = aux->next;
    }
}

int MG_Lista::size(){
    int cont = 0;
    Lista *aux = head;

    while(aux->next != head){
        cont++;
        aux = aux->next;
    }
    return cont;
}

Lista* MG_Lista::comeco(){
    return head->next;
}

Lista* MG_Lista::fim(){
    return head->prev;
}


// ------------------------------ ORDENAÇÂO ----------------------------------------------------
void MG_Lista::bubblesort(){
    Lista *first = head->next;
    Lista *last = head->prev;
    for(Lista *aux = first; aux !=head; aux = aux->next){
        for(Lista *aux2 = last; aux2 != aux; aux2 = aux2->prev){
            if(aux2->key < aux2->prev->key)
                std::swap(aux2->key, aux2->prev->key);
        }
    }
            
}
 void MG_Lista::insertionsort(){
    Lista *first = head->next;
    Lista *last = head->prev;
    Lista *chave = new Lista();
    Lista *aux = new Lista();
    for(Lista *aux2 = first->next; aux2 != last->next; aux2 = aux2->next){
        chave->key = aux2->key;
        aux = aux2->prev;
        while(aux!=head && aux->key > chave->key){
            aux->next->key = aux->key;
            aux = aux->prev;
        }
        aux->next->key = chave->key;
    }
}


void MG_Lista::selectionsort(){
    Lista *first = head->next;
    Lista *last = head->prev;
    for(Lista *aux = first; aux != last->prev; aux = aux->next){
        Lista *min = aux;
        for(Lista *aux2 = aux->next; aux2 != last->next; aux2 = aux2->next){
            if(aux2->key < min->key)
                min = aux2;
        }
        std::swap(aux->key, min->key);
    }
}

Lista* MG_Lista::separa (Lista *comeco, Lista *fim){
    Lista *c = new Lista();
    c->key = fim->key;
    Lista *j = comeco;
    for(Lista *k = comeco; k != fim; k = k->next){
        if(k->key <= c->key){
            std::swap(k->key, j->key);
            j = j->next;
        }
    }
    head->prev->key = j->key;
    j->key = c->key;
    return j;
} 

void MG_Lista::quickSort(Lista *comeco, Lista *fim){
    if(comeco != fim){
        Lista *i = separa(comeco, fim);
        quickSort(comeco, i->prev);
        quickSort(i->next, fim);
    }
}