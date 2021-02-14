#ifndef DIRETORIO_H_INCLUDED
#define DIRETORIO_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>

#include "Balde.h"

using namespace std;

class Diretorio{
    private:
        int d_global,m; //Profundidade Global

        vector<Balde*> baldes;
        string hash(string k);
        int getIndex(string k);
        int toDecimal(int k);

        void duplicaDiretorio();
        void divideBaldes(int index);
    public:
        Diretorio(int m,int b);
        ~Diretorio();

        void inserir(string k);
        void print();
};

#endif // DIRETORIO_H_INCLUDED