#ifndef INDIVIDUO_H_INCLUDED
#define INDIVIDUO_H_INCLUDED

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include<vector>
#include<random>



// Genes válidos
const int GENES[2] = {0,1};

class Individuo
{
private:

    int* cromossomo;
    double fitness;

public:
    static int BITS_SIZE;
    static int min;
    static int max;
    static int POPULATION_SIZE;
    static double param[4];
    int*getCromossomo();
    double getFitness();
    void setFitness(double x);
    void setCromossomo(int*x);
    Individuo(int* cromossomo );
    Individuo cruzar(Individuo parent2);
    //Retorna o número diretamente a direita do x passado
    int*maiorC();
    //Retorna o número diretamente a esquerda do x passado
    int*menorC();
    double cal_fitness();
    int getBitsSize();
    //Sobrecarga do operador <
    friend bool operator<(const Individuo &ind1, const Individuo &ind2);
    friend int* criar_gnoma();
    friend double converte_gray_dec(int*gray);
    friend int* converte_dec_gray(double x);
    friend Individuo melhor(std::vector<Individuo> pop);
};
 double converte_gray_dec(int*gray);
Individuo melhor(std::vector<Individuo> pop);

int num_aleatorio(int start, int end);
int* converte_dec_gray(double x);
int genes_mutados();
int* criar_gnoma();
bool testeDerivada(double x);

bool igualZero(double x);



#endif // INDIVIDUO_H_INCLUDED
