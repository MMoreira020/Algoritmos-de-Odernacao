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

double selectionSort(int *array, int tamanho){
    int i, j, min_index;
    // Calculo do tempo de execução do código
    double tempo;
    clock_t InicC, FimC;

    InicC = clock(); // captura o tempo inicial
    for (i = 0; i < tamanho - 1; i++){
        // encontrar o menor elemento na matriz
        min_index = i;
        for (j = i + 1; j < tamanho; j++){
            if (array[j] < array[min_index]){
                min_index = j;
            }
        }
        // trocar o menor elemento encontrado com o primeiro elemento 
        int temp = array[i];
        array[min_index] = array[i];
        array[i] = temp;
    }

    FimC = clock(); // tempo de execução final
    tempo = (FimC - InicC) / (double)CLOCKS_PER_SEC;
    cout <<"O algoritmo executou em: " << tempo << "segundos" <<endl;

    return tempo;
}

double bubbleSort(int *array, int tamanho){
    int i, j, aux;
    // calculo do tempo de execução do código
    double tempo;
    clock_t IniC, FimC;

    IniC = clock(); // tempo incial
    // loop externo --> corresponde ao número de elementos a serem classificados
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho - i; j++){
            if (array[j] > array[j + 1]){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    FimC = clock(); // tempo final de execução
    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;
    cout <<"O algoritmo executou em: " << tempo << "segundos" <<endl;

    return tempo;
    
}

double shellSort(int *array, int tamanho){
    int gap, i, j, temp;
    //calculo do tempo de execução do código
    double tempo;
    clock_t IniC, FimC;

    IniC = clock(); // tempo inicial;
    // Começa com um grande intervalo, depois reduz o intervalo
    for (gap = tamanho / 2; gap > 0; gap /= 2){
        // Realiza a ordenação por inserção para este intervalo

        for (i = gap; i < tamanho; i++){
            temp = array[i];
            for(j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
    FimC = clock(); // tempo final de execução
    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;
    cout <<"O algoritmo executou em: " << tempo << "segundos" <<endl;

    return tempo;
}

#endif
