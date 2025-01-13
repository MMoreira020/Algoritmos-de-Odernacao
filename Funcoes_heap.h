#include <iostream>

using namespace std;

void heapify1(int vet[], int n, int i){
    int l = 2*n + 1;
    int r = 2*n + 2;
    int menor = n;

    if (l <= i && vet[l] < vet[n]){
        menor = l;
    }
    if (r <= i && vet[r] < vet[menor]){
        menor = r;
    }
    if (menor != n){
        int temp = vet[n];
        vet[n] = vet[menor];
        vet[menor] = temp;
        heapify1(vet, menor, i);
    }
}

void buildHeap1(int vet[], int tamanho){
    for (int i = tamanho/2; i >= 0; i--){
        heapify1(vet, i, tamanho);
    }
}

void heap_minimum(){
    int vet[10];
    int seed;

    for (int i = 0; i < 10; i++){
        seed = ((rand() % 1000) * 1000) + rand() % 1000 + ((rand() % 9 + 1) * 1000000);
        vet[i] = seed;
    }
    cout << "Vetor Original (desordenado): ";
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }

    buildHeap1(vet, 10);

    cout << endl << "Vetor chamando Build: " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }

    cout << endl << "Elemento Minimo: " << vet[0];
}

void extract(int vet[]){
    for (int i = 0; i < 9; i++){
        cout << vet[i + 1];
    }
}

void heap_extract_min(){
    int vet[10];
    int seed;
    int n = 10;

    for (int i = 0; i < 10; i++){
        seed = ((rand() % 1000) * 1000) + rand() % 1000 + ((rand() % 9 + 1) * 1000000);
        vet[i] = seed;
    }

    cout << "Vetor Original (desordenado): " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }

    cout << endl << "Elemento Minimo: " << vet[0];

    heapify1(vet, 0, n);
    extract(vet);

    cout << endl << "Vetor chamado Heapify: " << endl;
    for (int i = 0; i < 9; i++){
        cout << vet[i] << " ";
    }

    int min;
    if(n<1){
        printf("Erro! nenhum elemento no vetor.\n");
        exit(1);
    }
}

void heap_increase_key(){
    int vet[10];
    int seed;
    int pos;

    for (int i = 0; i < 10; i++){
        seed = ((rand() % 1000) * 1000) + rand() % 1000 + ((rand() % 9 + 1) * 1000000);
        vet[i] = seed;
    }

    cout << "Vetor Original (desordenado): " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }

    buildHeap1(vet, 10);

    cout << endl << "Vetor chamando Build: " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }

    cout << endl << "Informe a posição do elemento que deseja aumentar a chave de 0 a 9: " << endl;
    cin >> pos;
    vet[pos] = 1000;

    cout << endl << "Vetor chamando Increase Key: " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }
}

void max_heap_insert(){
    int vet[10];
    int seed;
    int pos = 0;

    for (int i = 0; i < 10; i++){
        seed = ((rand() % 1000) * 1000) + rand() % 1000 + ((rand() % 9 + 1) * 1000000);
        vet[i] = seed;
    }

    cout << "Vetor Original (desordenado): " << endl;
    for (int i = 0; i < 10; i++){
        cout << vet[i] << " ";
    }
}