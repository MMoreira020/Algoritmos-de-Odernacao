#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int menuOpcoes(){
    int opcao1;

        // Menu de opções do algorítmo 

        cout << endl;
        cout<< "      PROJETO DE ALGORITMOS     " <<endl;
        cout << "===============================" <<endl;
        cout << "        MENU DE OPCOES        " <<endl;
        cout << "===============================" <<endl;

        cout << "Informe o algoritmo desejado" <<endl;

        cout << "Escolha uma opcao: " <<endl;
        cout << "1 - Ordenar com Insertion Sort" <<endl;
        cout << "2 - Ordenar com Selection Sort" <<endl;
        cout << "3 - Ordenar com Bubble Sort" <<endl;
        cout << "4 - Ordenar com Shell Sort" <<endl;
        cout << "0 - Sair" <<endl;

        cin >> opcao1;

        return opcao1;
}

int menuDeEntrada(){
    int opcao2;

        // Menu de opções, crescente, decrescente e randomico
        
        cout << "Informe o tipo da entrada: " <<endl << endl;
        cout << "===============================" <<endl;
        cout << "1 - Crescente" <<endl;
        cout << "2 - Decrescente" <<endl;
        cout << "3 - Randomico" <<endl;

        cin >> opcao2;

        return opcao2;
}

int menuDeQuantidade(){
    int opcao3;

        // Menu de opções quantidade: 10; 100; 1000; 10000; 100000; 1000000

        cout << "Informe a quantidade de numeros que devem ser gerados: " <<endl <<endl;
        cout << "1 - 10" <<endl;
        cout << "2 - 100" <<endl;
        cout << "3 - 1000" <<endl;
        cout << "4 - 10000" <<endl;
        cout << "5 - 100000" <<endl;
        cout << "6 - 1000000" << endl;

        cin >> opcao3;

        return opcao3;
}