#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Diretorio.h"

using namespace std;

string intToString(unsigned int number)
{
    int quotient = number;
    int bynary[9];
    string bynStr;
    for (int i = 0; i < 9; i++)
    {
        bynary[i] = 0;
    }
    int i = 8;
    while (quotient != 0)
    {
        int remainder = quotient % 2;
        bynary[i] = remainder;
        quotient = quotient / 2;
        i--;
    }

    bynStr = to_string(bynary[0]);
    for (int i = 1; i < 9; i++)
    {
        bynStr += to_string(bynary[i]);
    }

    return bynStr;
}

void selecionar(int opcao);
int menu();
void laco();

void aleatorio();
void mesmoPadrao();

int main()
{
    laco();
    return 0;
}

int menu()
{
    int opcao;

    cout << "\t\tAtividade de Hash Extensivel" << endl;
menu:
    cout << "[ 1 ] Insercoes de N chaves aleatorias" << endl;
    cout << "[ 2 ] Insercoes de N chaves de mesmo padrao" << endl;
    cout << "[ 0 ] Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao != 0 && opcao != 1 && opcao != 2)
    {
        goto menu;
    }

    return opcao;
}

void laco()
{
    int opcao = -1;

    while (opcao != 0)
    {
        opcao = menu();
        if (opcao != 0)
            selecionar(opcao);
    }

    cout << "Finalizando Execucao" << endl;
}

void selecionar(int opcao)
{
    switch (opcao)
    {
    case 1:
        aleatorio();
        break;
    case 2:
        mesmoPadrao();
        break;
    default:
        menu();
        break;
    }
}

void aleatorio()
{
    clock_t inicio,fim;

    inicio = clock();
    Diretorio *d = new Diretorio(1, 5);
    cout << endl
         << "Inserindo 10 registros aleatorios" << endl;
    d->inserir(intToString(2));
    d->inserir(intToString(3));
    d->inserir(intToString(4));
    d->inserir(intToString(5487));

    d->print();
    fim = clock();

    cout << "O processo levou " << (float)(fim - inicio) / CLOCKS_PER_SEC << " segundos" 
        << " e usou de memoria " << endl << endl;
}

void mesmoPadrao()
{
    clock_t inicio,fim;

    inicio = clock();
    Diretorio *d = new Diretorio(5, 2);
    cout << endl
         << "Inserindo 10 registros aleatorios" << endl;
    d->inserir("a");
    d->inserir("b");
    d->inserir("c");
    d->inserir("d");
    d->inserir("e");
    d->inserir("f");
    d->inserir("g");
    d->inserir("h");
    d->inserir("i");
    d->inserir("j");

    d->print();

    fim = clock();

    cout << "O processo levou " << (float)(fim - inicio) / CLOCKS_PER_SEC << " segundos"
        << " e usou de memória " << endl << endl;
}