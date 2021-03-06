#include "Individuo.h"

int Individuo::BITS_SIZE=19;
int Individuo::min=-20;
int Individuo::max=20;
int Individuo::POPULATION_SIZE=300;
double Individuo::param[4];
int getBitsSize()
{
    return Individuo::BITS_SIZE;
}

Individuo::Individuo(int* chromo)
{
    this->cromossomo = new int [BITS_SIZE];
    for(int i=0; i<BITS_SIZE; i++)
        cromossomo [i] = chromo[i];
    fitness = cal_fitness();
};

Individuo Individuo::cruzar(Individuo par2)
{
    int* cromossomo_filho  = new int[BITS_SIZE];
    do
    {
        for(int i = 0; i<BITS_SIZE; i++)
        {
            double p = num_aleatorio(0, 100)/100.0;



            if(p < 0.45)
                cromossomo_filho [i] = cromossomo [i];

            else if(p < 0.90)
                cromossomo_filho [i] = par2.cromossomo [i];

            else
                cromossomo_filho [i] = genes_mutados();
        }
    }
    while((converte_gray_dec(cromossomo_filho) <Individuo::min) || (converte_gray_dec(cromossomo_filho)>Individuo::max));

    return Individuo(cromossomo_filho);
};

double Individuo::cal_fitness()
{
    double x = converte_gray_dec(cromossomo);
    fitness = (param[0]*sin(param[1]*x) + param[2]*cos(param[3]*x));
    return fitness;
};

int* Individuo::getCromossomo()
{
    return cromossomo;
}

double Individuo::getFitness()
{
    return fitness;
}

void Individuo::setFitness(double x)
{
    fitness = x;
}

void Individuo::setCromossomo(int*x)
{
    for(int i =0 ;i<BITS_SIZE;i++)
    {
        cromossomo[i] = x[i];
    }
}

int*Individuo::maiorC()
{
    double a = converte_gray_dec(cromossomo);
    a = a + 0.0001;
    return converte_dec_gray(a);
}

int*Individuo::menorC()
{
    double a = converte_gray_dec(cromossomo);
    a = a - 0.0001;
    return converte_dec_gray(a);
}

int num_aleatorio(int inicio, int fim)
{
    int alcance = (fim-inicio)+1;
    int int_alea = inicio+(rand()%alcance);
    return int_alea;
}

int genes_mutados()
{
    int r = num_aleatorio(0,1);
    return GENES[r];
}

bool igualZero(double x)
{
    if((int)(x*1000)==0)
        return true;
    return false;
}

bool testeDerivada(double x)
{
    double y = cos(x) - sqrt(3)* sin(sqrt(3)* x);
    if (igualZero(y))
        return true;
    return false;
}

int* criar_gnoma()
{
    int* gnome = new int[getBitsSize()];
    do
    {
        for(int i = 0; i<getBitsSize(); i++)
            gnome[i] = genes_mutados();
    }
    while((converte_gray_dec(gnome) >Individuo::max) ||(converte_gray_dec(gnome) <Individuo::min) );
    return (gnome);
}

bool operator<(const Individuo &ind1, const Individuo &ind2)
{
    return ind1.fitness < ind2.fitness;
}

double converte_gray_dec(int*gray)
{
    int*bin = new (std::nothrow)int[getBitsSize()];
    int i= getBitsSize()-1;
    while(i>0)
    {
        if(i==(getBitsSize()-1))
        {
            bin[i]=gray[i];
        }
        else
        {
            bin[i]=gray[i]^bin[i+1];
        }
        i--;
    }
    bin[0] = gray[0];
    double dec =0;
    for(int i =0, j=(getBitsSize()-1); j>0; i++,j--)
    {
        dec += bin[j]*pow(2,i);
    }
    dec = dec/10000;
    int bit0 = bin[0];
    delete []bin;
    if (bit0==1)
        return (-dec);
    else
        return dec;

}

int* converte_dec_gray(double x)
{
    float decf = x*10000;
    int dec = decf;
    int*bin = new int[getBitsSize()];
    if(dec>0)
        bin[0] =0;
    else
    {
        bin[0] = 1;
        dec = -dec;
    }
    for(int i =(getBitsSize()-1); i>0; i--)
    {
        bin[i] = dec%2;
        dec = dec/2;
    }

    int*gray = new (std::nothrow)int[getBitsSize()];
    int i= getBitsSize()-1;
    while(i>0)
    {
        if(i==(getBitsSize()-1))
        {
            gray[i]=bin[i];
        }
        else
        {
            gray[i]=bin[i]^bin[i+1];
        }
        i--;
    }
    gray[0] = bin[0];
    delete []bin;


    return gray;
}

Individuo melhor(std::vector<Individuo> pop){
    Individuo melhor (pop[0].getCromossomo());
    for(int i=0;i<Individuo::POPULATION_SIZE;i++)
        if (pop[i].getFitness() > melhor.getFitness())
            melhor = pop[i];
    return melhor;
}
