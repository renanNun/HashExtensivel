#ifndef BALDE_H_INCLUDED
#define BALDE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Balde{
    public:
        vector<string> chaves; //Vetor de chaves;
        int pos;  //Posição ocupada do vetor de chaves;
        int d_local,m; //Profundidade Local e tamanho do Balde

    public:
        Balde(int tam,int profundidade);
        ~Balde();

        void inserir(string k);
        void remover(string k);
        bool buscar(string k);

        int tamUsado();
        bool cheio();
        void print();
};

#endif // BALDE_H_INCLUDED