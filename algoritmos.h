#ifndef ALGORITMOS_H
# define ALGORITMOS_H
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <conio.h>

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
    for (i = 1; i < tamanho; i++){
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

void merge(int *array, int inicio, int meio, int fim){
    int *temp, p1, p2, tam, i, j, k;
    int fim_1 = 0, fim_2 = 0;
    tam = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    temp = (int*)malloc(tam*sizeof(int));
    if (temp != NULL){
        for(i = 0; i < tam; i++){
            if(!fim_1 && !fim_2){
                if(array[p1] < array[p2])
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];
                
                if(p1 > meio) fim_1 = 1;
                if(p2 > fim) fim_2 = 1;
            }else{
                if(!fim_1)
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];
            }
        }
        for (j = 0, k = inicio; j < tam; j++, k++){
            array[k] = temp[j];
        }
    }
    free(temp);
}

double merge_sort(int *array, int inicio, int fim){
    double tempo;
    clock_t IniC, FimC;
    IniC = clock(); // tempo inicial

    int meio;

    if(inicio < fim){
        meio = floor((inicio + fim)/ 2);
        merge_sort(array, inicio, meio);
        merge_sort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }

    FimC = clock();

    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;

    return tempo;
}

// Quick Sort

void particao(int* vetor, int esq, int dir, int* i, int* j){
    int x, w;
    *i = esq;
    *j = dir;
    x = vetor[esq];

    do{
        while(x > vetor[*i])(*i)++;
        while(x < vetor[*j])(*j)--;
        if(*i <= *j){
            w = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = w;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void ordena(int* vetor, int esq, int dir){
    int i, j;
    particao(vetor, esq, dir, &i, &j);
    if(esq < j){
        ordena(vetor, esq, j);
    }
    if(i < dir){
        ordena(vetor, i, dir);
    }
}

double quick_sort(int* vetor, int n){
    double tempo;
    clock_t IniC, FimC;
    IniC = clock();

    ordena(vetor, 0, n-1);

    FimC = clock();
    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;

    return tempo;
}

// Heap Sort

void heapify(int* vet, int n, int i){
    int l = 2*n + 1;
    int r = 2*n + 2;
    int menor = n;

    if( l <= i && vet[l] < vet[n]){
        menor = l;
    }

    if(r <= i && vet[r] < vet[menor]){
        menor = r;
    }

    if (menor != n){
        int temp =  vet[n];
        vet[n] = vet[menor];
        vet[menor] = temp;
        heapify(vet, menor, i);
    }
}

void buildHeap(int* vet, int tamanho){
    for(int i = tamanho/2; i >= 0; i--){
        heapify(vet, i, tamanho);
    }
}

double heap_sort(int* vet, int tamanho){

    double tempo;
    clock_t IniC, FimC;
    IniC = clock();

    buildHeap(vet, tamanho);

    int i;
    for(i = tamanho; i >= 1; i--){
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;
        tamanho--;
        heapify(vet, 0, tamanho);
    }

    FimC = clock();
    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;

    return tempo;
}

// Quick Sort Média

void particaoMedia(int* vetor, int esq, int dir, int* i, int* j){
    int x, w;
    *i = esq;
    *j = dir;

    // calculo da média
    int resultado, t, posminima = 0, posmaxima = 0;
    int aux[3];
    aux[0] = *i + (rand()%(*j - *i));
    aux[1] = *i + (rand()%(*j - *i));
    aux[2] = *i + (rand()%(*j - *i));

    for (t = 0; t < 3; t++){
        if (vetor[aux[t]] < vetor[posminima]){
            posminima = t;
        }

        if(vetor[aux[t]] > vetor[posmaxima]){
            posmaxima = t;
        }
    }

    for (t = 0; t < 3; t++){
        if(t != posminima && t!= posmaxima){
            resultado = aux[t];
        }
    }

    x = vetor[resultado];

    do{
        while(x > vetor[*i]){
            (*i)++;
        }
        while(x < vetor[*j]){
            (*j)--;
        }
        if(*i <= *j){
            w = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = w;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void ordenaMedia(int *vetor, int esq, int dir){
    int i, j;
    particaoMedia(vetor, esq, dir, &i, &j);

    if(esq < j){
        ordenaMedia(vetor, esq, j);
    }

    if (i < dir){
        ordenaMedia(vetor, i, dir);
    }
}

double quickSortMedia(int* vetor, int n){
    double tempo;
    clock_t InicC, FimC;
    InicC = clock();

    ordenaMedia(vetor, 0, n - 1);

    FimC = clock();
    tempo = (FimC - InicC) / (double)CLOCKS_PER_SEC;

    return tempo;
}

// Mediana
void swap(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

int particaoMediana(int vetor[], int esq, int dir){
    int meio = (esq + dir) / 2;
    int a = vetor[esq];
    int b = vetor[meio];
    int c = vetor[dir];
    int medianaIndice;

    if(a < b){
        if (b < c){
            medianaIndice = meio;
        }else{
            if (a < c){
                medianaIndice = dir;
            }else{
                medianaIndice = esq;
            }
        }
    }
    else{
        if(c < b){
            medianaIndice = meio;
        }else{
            if(c < a){
                medianaIndice = dir;
            }else{
                medianaIndice = esq;
            }
        }
    }
    swap(vetor, medianaIndice, dir);
    int pivo = vetor[dir];
    int i = esq - 1;
    int j;

    for (j = esq; j <= dir - 1; j++){
        if (vetor[j] <= pivo){
            i = i + 1;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i + 1, dir);
    return i + 1;
}

void ordenaMediana(int vetor[], int esq, int dir){
    if(esq < dir){
        int q = particaoMediana(vetor, esq, dir);
        ordenaMediana(vetor, esq, q - 1);
        ordenaMediana(vetor, q + 1, dir);
    }
}

double quickSortMediana(int* vetor, int n){
    double tempo;
    clock_t IniC, FimC;
    IniC = clock();

    ordenaMediana(vetor, 0, n - 1);

    FimC = clock();
    tempo = (FimC - IniC) / (double)CLOCKS_PER_SEC;

    return tempo;
}

// Random
int particaoRandom(int vetor[], int esq, int dir){
    int k;
    double d;
    d = (double) rand() / ((double) RAND_MAX + 1);
    k = d * (dir - esq + 1);
    int randomIndex = esq + k;
    swap(vetor, randomIndex, dir);

    int pivo = vetor[dir];
    int i = esq - 1;
    int j;

    for (j = esq; j <= dir - 1; j++){
        if (vetor[j] <= pivo){
            i = i + 1;
            swap(vetor, i, j);
        }
    }
    swap(vetor, i + 1, dir);
    return i + 1;
}

void ordenaRandom(int vetor[], int esq, int dir){
    if (esq < dir){
        int q = particaoRandom(vetor, esq, dir);
        ordenaRandom(vetor, esq, q - 1);
        ordenaRandom(vetor, q + 1, dir);
    }
}

double quickSortRandom(int vetor[], int n){
    double tempo;
    clock_t InicC, FimC;
    InicC = clock();

    ordenaRandom(vetor, 0, n - 1);

    FimC = clock();
    tempo = (FimC - InicC) / (double)CLOCKS_PER_SEC;

    return tempo;
}
#endif
