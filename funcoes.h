#ifndef FUNCOES_H
#define FUNCOES_H
#include <iostream>
#include <string>
#include "algoritmos.h"
#include <windows.h>
#include <fstream>

using namespace std;

string Algoritmo_Escolhido(int tipo){
    string tipo_algoritmo;

    switch (tipo){
    case 1:
        tipo_algoritmo = "Insertion_sort\\";
        return tipo_algoritmo;
        break;
    
    case 2:
        tipo_algoritmo = "SelectionSort\\";
        return tipo_algoritmo;
        break;
    
    case 3:
        tipo_algoritmo = "BubbleSort\\";
        return tipo_algoritmo;
        break;
    
    case 4:
        tipo_algoritmo = "ShellSort\\";
        return tipo_algoritmo;
        break;

    
    default:
        cout << "ERRO - NAO FOI POSSIVEL CRIAR A PASTA";
        exit(1);
        break;
    }

}

double Organiza(int algoritmo, int *array, int tamanho){
    double tempo;

    switch (algoritmo)
    {
    case 1:
        tempo = insertion_sort(array, tamanho);
        break;

    case 2:
        tempo = selectionSort(array, tamanho);
        break;
    
    case 3:
        tempo = bubbleSort(array, tamanho);
        break;
    
    case 4:
        tempo = shellSort(array, tamanho);
        break;
    
    default:
        cout << "ERRO - NAO ENTROU NA FUNCAO DE ORGANIZACAO!\n";
        exit(1);
    }    

    return tempo;
}

void Crescente(int tipo, int quantidade){
    int j, i;
    FILE *arquivo;
    double tempo; // armazenar o tempo de execução 
    string nome_do_arquivo; // concatena com o nome do arquivo gerado
    int seed; // sementes 

    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos De Entrada\\Crescente\\EntradaCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);

    j = 0;
    
    int *array = new int[quantidade]; // Alocação de um array de inteiros 

    // Gerar números aleatórios que serão usados no inicio do for

    seed = (rand() % 1000000) * 100; // gera números aleatórios 

    for  (i = seed; j < quantidade; i++){
        array[j] = i; // insere o número no array
        fprintf(arquivo, "%d\n", array[j]);
        j++;
    }
    fclose(arquivo);

    // arquivo de tempo
    tempo = Organiza(tipo, array, quantidade);

    // arquivo de tempo
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos De tempo\\Crescente\\TempoCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%.5f\n", tempo);
    fclose(arquivo);

    // arquivo de saída
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos De Saida\\Crescente\\SaidaCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);
    // escrever os elementos do array no arquivo
    for (i = 0; i < quantidade; i++){
        fprintf(arquivo, "%d\n", array[i]);
    }

    delete[] array; // liberando a memória
}

void Decrescente(int tipo, int quantidade){
    int j, i;
    FILE *arquivo;
    double tempo; // armazena o tempo
    string nome_do_arquivo; // concatena o nome do arquivo gerado
    int seed; // gera sementes

    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos De Entrada\\Decrescente\\EntradadeCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);

    j = 0;

    int *array = new int[quantidade]; // alocando memória para um array de inteiros

    seed = (rand() % 1000000) * 100; // gera números aleatórios

    for (i = seed; j < quantidade; i--){
        array[j] = i; // insere o número no array
        fprintf(arquivo, "%d\n", array[j]);
        j++;
    }
    fclose(arquivo);

    // arquivo de tempo
    tempo = Organiza(tipo, array, quantidade);
    // concatenar arquivo de tempo
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos de Tempo\\Decrescente\\TempodeCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%.5f\n", tempo);
    fclose(arquivo);

    // arquivo de saida
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos de Saida\\Decrescente\\SaidadeCrescente" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);
    for (i = 0; i < quantidade; i++){
        fprintf(arquivo, "%d\n", array[i]);
    }
    delete[] array;
}

void Random(int tipo, int quantidade){
    int i;
    int seed; // gerar sementes
    FILE *arquivo;
    double tempo; // armazenar o tempo
    string nome_do_arquivo; // concatena o nome do arquivo gerado

    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos de Entrada\\Random\\EntradaRandom" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);

    int *array = new int[quantidade]; // alocano um array de inteiros

    seed = (rand() % 1000000) * 100; // gerar números aleatórios

    for (i = 0; i < quantidade; i++){
        seed = ((rand() % 1000) * 1000) + rand () % 1000 + ((rand() % 9 + 1) * 1000000); // produz valores múltiplos de 1000, adiciona um número entre 0 e 999 e adiciona um número aleatório entre 1000000 e 9000000
        array[i] = seed; // armazena o número gerado no array
        fprintf(arquivo, "%d\n", array[i]); // escreve o número gerado  no arquivo
    }
    fclose(arquivo);

    // arquivo de tempo
    tempo = Organiza(tipo, array, quantidade);
    // concatena arquivo de tempo
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos de Tempo\\Random\\TempoRandom" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%.5f\n", tempo);
    fclose(arquivo);

    // arquivo de saída
    nome_do_arquivo = Algoritmo_Escolhido(tipo) + "Arquivos de Saida\\Random\\SaidaRandom" + to_string(quantidade) + ".txt";
    arquivo = fopen(nome_do_arquivo.c_str(), "w");
    fprintf(arquivo, "%d\n", quantidade);
    for (i = 0; i < quantidade; i++){
        fprintf(arquivo, "%d\n", array[i]);
    }
    delete[] array;

}

int muda_tamanho(int tamanho){
    if (tamanho == 1){
        tamanho = 10;
    }
    else if (tamanho == 2){
        tamanho = 100;
    }
    else if (tamanho == 3){
        tamanho = 1000;
    }
    else if (tamanho == 4){
        tamanho = 10000;
    }
    else if (tamanho == 5){
        tamanho = 100000;
    }
    else if (tamanho == 6){
        tamanho = 1000000;
    }

    return tamanho;
}

void criar_pasta (const string& pasta){
    if (!CreateDirectoryA(pasta.c_str(), NULL)){

        if (GetLastError() != ERROR_ALREADY_EXISTS){
        cerr << "ERRO AO CRIAR PASTA: " << pasta <<endl;
        exit(1);
        }
    }
}

void Pasta(string diretorio, int tipo){
    criar_pasta(diretorio);

    criar_pasta(diretorio + "\\Arquivos de entrada");
    criar_pasta(diretorio + "\\Arquivos de saida");
    criar_pasta(diretorio + "\\Arquivos de tempo");

    if (tipo == 1){
        criar_pasta(diretorio + "\\Arquivos de entrada\\Crescente");
        criar_pasta(diretorio + "\\Arquivos de saida\\Crescente");
        criar_pasta(diretorio + "\\Arquivos de tempo\\Crescente");
    }

    if (tipo == 2){
        criar_pasta(diretorio + "\\Arquivos de entrada\\Decrescente");
        criar_pasta(diretorio + "\\Arquivos de saida\\Decrescente");
        criar_pasta(diretorio + "\\Arquivos de tempo\\Decrescente");
    }

    if (tipo == 3){
        criar_pasta(diretorio + "\\Arquivos de entrada\\Random");
        criar_pasta(diretorio + "\\Arquivos de saida\\Random");
        criar_pasta(diretorio + "\\Arquivos de tempo\\Random");
    }
}

#endif