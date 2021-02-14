#include "Balde.h"

Balde::Balde(int tam, int profundidade)
{
    cout << "Criando novo balde\n";
    this->m = tam;
    this->d_local = profundidade;
    this->pos = 0;
    
    chaves.resize(m);
}

Balde::~Balde()
{
    chaves.clear();
}

void Balde::inserir(string k)
{
    chaves.push_back(k);
    pos++;
}

void Balde::remover(string k)
{
    for(int i = 0; i <= pos; i++ )
    {
        if(chaves[i] == k)
        {
            chaves.erase(chaves.begin() + i);
            pos--;
            break;
        }
    }
}

bool Balde::buscar(string k) {
    
    for(auto it = chaves.begin(); it != chaves.end(); it++)
    {
        if(*it == k)
        {
            return true;
        }
    }

    return false;
}

int Balde::tamUsado()
{
    return chaves.size();
}

bool Balde::cheio()
{
    return chaves.size() == m;
}

void Balde::print()
{
    for(int i = 0; i < chaves.size();i++)
    {
        cout << "| " << chaves[i] << " |";
    }
    cout << endl;
}