#ifndef ORDENACAO_H
#define ORDENACAO_H

// feita por Ulisses Queiroz da Silva - 471285

struct Lista;

class MG_Lista{
    private:
        Lista *head;
    public:
        MG_Lista();
        ~MG_Lista();
        void add(int);
        Lista* search(int);
        void remove(int);
        void print();
        bool isEmpty();
        void clear();
        Lista* comeco();
        Lista* fim();
        int size();


        void bubblesort();
        void insertionsort();
        void selectionsort();

        // void Intercala (int *A, int p, int q, int r);
        // void margeSort(int *A, int p, int r);
        Lista* separa (Lista*, Lista*);
        void quickSort(Lista*, Lista*);

};


#endif