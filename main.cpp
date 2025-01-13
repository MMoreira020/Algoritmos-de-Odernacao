#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "menu.h"
#include "funcoes.h"
#include "algoritmos.h"
#include "Funcoes_heap.h"

using namespace std;

int main(){

    int algoritmo = 0;
    int tipo;
    int quantidade;
    string nome_do_arquivo;

    while(algoritmo != 15){

        algoritmo = menuOpcoes(); 
        system("cls");
        if(algoritmo == 15){
            return 0; // Sair do programa
        }

        if (algoritmo == 11){
            heap_minimum();
        }else if(algoritmo == 12){
            heap_extract_min();
        }else if(algoritmo == 13){
            heap_increase_key();
        }else if(algoritmo == 14){
            max_heap_insert();
        }else{

            tipo = menuDeEntrada();
            system("cls");
            quantidade = menuDeQuantidade();
            system("cls");

            nome_do_arquivo = Algoritmo_Escolhido(algoritmo);
            Pasta(nome_do_arquivo, tipo);

            quantidade = muda_tamanho(quantidade);

            switch(tipo){
                case 1:
                    Crescente(algoritmo, quantidade);
                    break;
                
                case 2:
                    Decrescente(algoritmo, quantidade);
                    break;
                
                case 3:
                    Random(algoritmo, quantidade);
                    break;
            }

        }
    }
    return 0;
}