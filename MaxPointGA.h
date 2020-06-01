#ifndef MAXPOINTGA_H_INCLUDED
#define MAXPOINTGA_H_INCLUDED
#include "Individuo.h"
#include <vector>
class MaxPointGA{
private:

    // Geração atual
    int POP_TAM=300;
    int BITS_SIZE;
    double upperLimit = 10.0;
    double lowerLimit = -10.0;
    int precision = 2;
    double parameters[4] = {1,1,1, sqrt(3)};
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
    void setParams(double* x);
    void setParams(double a, double b, double c, double d);
    double* getParams();


};


#endif // MAXPOINTGA_H_INCLUDED
