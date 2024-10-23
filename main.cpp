#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "menu.h"
#include "funcoes.h"
#include "algoritmos.h"

using namespace std;

int main(){

    int algoritmo = 0;
    int tipo;
    int quantidade;

    while(true){

        algoritmo = menuOpcoes(); 
        system("cls");
        if(algoritmo == 0){
            return 0; // Sair do programa
        }

        tipo = menuDeEntrada(); 
        system("cls");
        quantidade = menuDeQuantidade(); 
        system("cls");

        // Parte responsável por criar as pastas iniciais
        string nome_arquivo = Algoritmo_Escolhido(algoritmo); // Usando a função do novo menu
        Pasta(nome_arquivo, tipo); // Criando pastas com base no tipo de entrada

        quantidade = muda_tamanho(quantidade); // Ajustando a quantidade para o valor correto

        switch (tipo){
            case 1:
                Crescente(algoritmo, quantidade); // Chamada para gerar dados em ordem crescente
                break;
            case 2:
                Decrescente(algoritmo, quantidade); // Chamada para gerar dados em ordem decrescente
                break;
            case 3:
                Random(algoritmo, quantidade); // Chamada para gerar dados aleatórios
                break;
            default:
                cout << "Tipo de entrada inválido!" << endl; // Tratamento de erro para tipo inválido
                break;
        }
    }
    return 0;
}
