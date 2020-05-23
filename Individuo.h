#ifndef INDIVIDUO_H_INCLUDED
#define INDIVIDUO_H_INCLUDED

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include<vector>


#define POPULATION_SIZE 300
#define BITS_SIZE 19
#define max 20
#define min -20

// Genes válidos
const int GENES[2] = {0,1};

class Individuo
{
private:
    int cromossomo [BITS_SIZE];
    double fitness;

public:
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
    //Sobrecarga do operador <
    friend bool operator<(const Individuo &ind1, const Individuo &ind2);
};


// Gera numeros aleatorios dentro do range
int num_aleatorio(int start, int end);

//Retorna um bit aleatorio
int genes_mutados();

//Cria Individuo com genoma aleatorio
int* criar_gnoma();

//Testa se a derivada do ponto x é igual a 0
bool testeDerivada(double x);

double converte_gray_dec(int*gray);

int* converte_dec_gray(double x);

//Verifica se o número passado é igual a 0 com precisão de 4 casas decimais
bool igualZero(double x);

Individuo melhor(std::vector<Individuo> pop);

#endif // INDIVIDUO_H_INCLUDED
