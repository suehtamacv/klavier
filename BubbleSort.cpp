#include "BubbleSort.h"

void BubbleSort(int Vetor[], int Tamanho) {
    int aux, i, j, k = Tamanho-1;
    for(i=0; i<Tamanho; i++) {
        for(j=0; j<k; j++) {
            if(Vetor[j]>Vetor[j+1]) {
                aux=Vetor[j];
                Vetor[j]=Vetor[j+1];
                Vetor[j+1]=aux;
            }
        }
        k--;
    }
}
