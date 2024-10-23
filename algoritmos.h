#ifndef ALGORITMOS_H
# define ALGORITMOS_H
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <vector>

using namespace std;

double insertion_sort(int *array, int tamanho){
    int chave, j;
    // Calculo de tempo de execução do código
    double tempo;
    clock_t InciC, FimC;

    InciC = clock(); // capturar o tempo incial
    for (int i = 1; i < tamanho; i++){
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }

    FimC = clock(); // tempo final de execução
    tempo = (FimC - InciC) / (double)CLOCKS_PER_SEC;
    cout << "O algoritmo xecutou em: " << tempo << " segundos" << endl;

    return tempo;
}



#endif
