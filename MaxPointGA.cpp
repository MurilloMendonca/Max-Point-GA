#include "MaxPointGA.h"
void MaxPointGA::inicia()
{
    for(int i = 0; i<this->POP_TAM; i++)
    {
        int* gnoma = new  int[this->BITS_SIZE];
        gnoma = criar_gnoma();
        populacao.push_back(Individuo(gnoma));
        delete [] gnoma;
    }
}
MaxPointGA::MaxPointGA()
{


}
MaxPointGA::MaxPointGA(double lower, double upper, int prec, int popTam)
{
    this->setUpperLimit(upper);
    this->setLowerLimit(lower);
    this->setPrecision(prec);
    this->setPopTam(popTam);
}
double MaxPointGA::run(int N_GERA)
{
    Individuo::max = this->upperLimit;
    Individuo::min = this->lowerLimit;
    Individuo::BITS_SIZE = 19;
    Individuo::POPULATION_SIZE = this->POP_TAM;
    for(int i=0;i<4;i++)
        Individuo::param[i] = this->parameters[i];
    inicia();
    Individuo Melhor = populacao[0];
    bool encontrado = false;
    int geracao = 0;
    while(! encontrado)
    {
        Melhor = melhor(populacao);
        if((geracao>=N_GERA))
        {
            encontrado = true;
            break;
            /*
            //Teste da derivada = 0
            if(testeDerivada(converte_gray_dec(Melhor.getCromossomo())))
            {
                encontrado = true;
                break;
            }
            else
            {
                int*m= Melhor.maiorC();
                int*n = Melhor.menorC();
                Individuo maior(m);
                Individuo menor(n);

                if(menor.getFitness()>Melhor.getFitness())
                {
                    Melhor = menor;
                    geracao =0;
                }
                else if (maior.getFitness()>Melhor.getFitness())
                {
                    Melhor = maior;
                    geracao =0;
                }
            }*/
        }
        std::vector<Individuo> nova_geracao;
        populacao[0] = Melhor;

        for(int i = this->POP_TAM-1; i>0; i--)
        {
            int r = num_aleatorio(0, this->POP_TAM-1);
            Individuo pai1 = populacao[r];
            r = num_aleatorio(0, this->POP_TAM-1);
            Individuo pai2 = populacao[r];
            Individuo cruzamento = pai1.cruzar(pai2);
            nova_geracao.push_back(cruzamento);
        }
        populacao = nova_geracao;
        geracao++;
    }
    return  converte_gray_dec(Melhor.getCromossomo());

}

//getters and setters
void MaxPointGA::setUpperLimit(double x)
{
    this->upperLimit = x;
}
double MaxPointGA::getUpperLimit()
{
    return this->upperLimit;
}
void MaxPointGA::setLowerLimit(double x)
{
    this->lowerLimit = x;
}
double MaxPointGA::getLowerLimit()
{
    return lowerLimit;
}
void MaxPointGA::setPrecision(int x)
{
    this->precision = x;
}
int MaxPointGA::getPrecision()
{
    return this->precision;
}
void MaxPointGA::setPopTam(int x)
{
    this->POP_TAM = x;
}
int MaxPointGA::getPopTam()
{
    return this->POP_TAM;
}
void MaxPointGA::setParams(double* x)
{
    for(int i=0;i<4;i++)
        this->parameters[i] = x[i];
}
void MaxPointGA::setParams(double a, double b, double c, double d)
{
    this->parameters[0]=a;
    this->parameters[1]=b;
    this->parameters[2]=c;
    this->parameters[3]=d;
}
double* MaxPointGA::getParams()
{
    return this->parameters;
}
