#ifndef MAXPOINTGA_H_INCLUDED
#define MAXPOINTGA_H_INCLUDED
#include "Individuo.h"
#include <vector>
class MaxPointGA{
private:

    // Geração atual
    int geracao = 0;
    int POP_TAM=300;
    int BITS_SIZE;
    double upperLimit = 10.0;
    double lowerLimit = -10.0;
    int precision = 2;
    std::vector<Individuo> populacao;
    bool encontrado = false;

    void inicia();

    void setBitsSize();

public:
    MaxPointGA();
    MaxPointGA(double lower, double upper, int prec, int popTam);
    double run(int Ngenerations);


    //getters and setters
    void setUpperLimit(double x);
    double getUpperLimit();
    void setLowerLimit(double x);
    double getLowerLimit();
    void setPrecision(int x);
    int getPrecision();
    void setPopTam(int x);
    int getPopTam();


};


#endif // MAXPOINTGA_H_INCLUDED
