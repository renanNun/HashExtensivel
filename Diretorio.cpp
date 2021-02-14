#include "Diretorio.h"

Diretorio::Diretorio(int m, int b)
{
    this->m = m;
    this->d_global = b;

    for (int i = 0; i < 1 << d_global; i++)
    {
        Balde *b = new Balde(m, d_global);
        baldes.push_back(b);
    }
}

Diretorio::~Diretorio()
{
    baldes.clear();
}

string Diretorio::hash(string k)
{
    return std::bitset<32>(k.c_str()[0]).to_string();
}

int Diretorio::toDecimal(int k)
{
    int decimal = 0;
    for (int i = 0; k > 0; i++)
    {
        decimal = decimal + pow(2, i) * (k % 10);
        k = k / 10;
    }

    return decimal;
}

int Diretorio::getIndex(string k)
{
    string h = hash(k);
    string bitStr = "";

    for (int i = 0; i < d_global; i++)
    {
        bitStr += h[i];
    }

    int id = stoi(bitStr);

    return toDecimal(id) % baldes.size();
}

void Diretorio::duplicaDiretorio()
{
    //cout << "Duplica diretorio " << endl;
    vector<Balde *> aux;
    aux.resize(baldes.size() * 2);

    for (int i = 0; i < baldes.size(); i++)
    {
        aux.push_back(baldes[i]);
    }

    baldes = aux;
    //cout << "Terminou de Duplicar diretorio " << endl;
}

void Diretorio::divideBaldes(int index)
{
    //cout << "Divide baldes" << endl;
    int z =  baldes[index]->d_local + 1;
    Balde *aux = new Balde(this->m,z);
    //cout << "Instanciamos um novo balde" << endl;
    baldes[index]->d_local++;

    for (int i = 0; i <= baldes[index]->pos; i++)
    {
        if(getIndex(baldes[index]->chaves[i]) != baldes[index]->d_local)
        {
            aux->inserir(baldes[index]->chaves[i]);
        }
    }

    for(int i = 0; i < aux->pos;i++)
    {
        baldes[index]->remover(aux->chaves[i]);
    }

    for(int i = 0; i < baldes.size();i++)
    {
        if(baldes[i]->d_local != baldes[index]->d_local)
        {
            baldes[i] = aux;
        }
    }
}

void Diretorio::inserir(string k)
{
    int pos = getIndex(k);

    if (!baldes[pos]->buscar(k))
    {
        if (baldes[pos]->cheio())
        {
            //cout << "CASO UM" << endl;
            baldes[pos]->inserir(k);
        }
        else
        {

            if (baldes[pos]->d_local == d_global)
            {
                //cout << "CASO 3" << endl;
                baldes[pos]->inserir(k);
                duplicaDiretorio();
                divideBaldes(pos);
            }
            else if (baldes[pos]->d_local < d_global)
            {
                //cout << "CASO 2" << endl;
                baldes[pos]->inserir(k);
                divideBaldes(pos);
            }
        }
    }
}

void Diretorio::print()
{
    for(int i = 0; i < baldes.size();i++)
    {
        baldes[i]->print();
    }
}