#include <iostream>
#include<ctime>
#include <cmath>
#include <vector>
#include<algorithm>
#include <iomanip>
#include"Individuo.h"

using namespace std;

int main()
{
    srand((unsigned)(time(0)));

    // Gera��o atual
    int geracao = 0;

    vector<Individuo> populacao;

    bool encontrado = false;

    // Cria a popula��o inicial
    for(int i = 0; i<POPULATION_SIZE; i++)
    {
        int* gnoma = new (nothrow) int[BITS_SIZE];
        gnoma = criar_gnoma();
        populacao.push_back(Individuo(gnoma));
        delete [] gnoma;
    }

    double ant = 0.0000;
    int cont =0;
    Individuo Melhor = populacao[0];

    while(! encontrado)
    {

        // Ordena a popula��o em ordem crescente e ap�s, inverte

        Melhor = melhor(populacao);

        // Condi��es de parada
        if((cont>=25))
        {
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

                if(menor.getFitness()>Melhor.getFitness()){
                    Melhor = menor;
                    cont =0;
                }
                else if (maior.getFitness()>Melhor.getFitness())
                {
                Melhor = maior;
                cont =0;
                }
                /*Metodo de reiniciar a popula��o

                cout<<endl<<"POPULACAO REINICIADA"<<endl;
                geracao =0;

                bool encontrado = false;
                populacao.clear();


                // Cria a popula��o inicial
                for(int i = 0; i<POPULATION_SIZE; i++)
                {
                    int* gnoma = new (nothrow) int[BITS_SIZE];
                    gnoma = criar_gnoma();
                    populacao.push_back(Individuo(gnoma));
                    delete [] gnoma;
                }

                double ant = 0.0000;
                 cont =0;*/

            }
        }

        // Iniciar nova gera��o
        vector<Individuo> nova_geracao;

        // Realiza Elitismo, onde 1% da popula��o com o melhor fitness
        // vai para a proxima gera��o
        populacao[0] = Melhor;


        // Os 80% melhores individuos v�o cruzar para gerar os
        // 99% restantes da nova popula��o
        for(int i = POPULATION_SIZE-1; i>0; i--)
        {
            int r = num_aleatorio(0, POPULATION_SIZE);
            Individuo pai1 = populacao[r];
            r = num_aleatorio(0, POPULATION_SIZE);
            Individuo pai2 = populacao[r];
            Individuo cruzamento = pai1.cruzar(pai2);
            nova_geracao.push_back(cruzamento);
        }

        populacao = nova_geracao;

        if(ant ==converte_gray_dec(Melhor.getCromossomo()))
            cont++;
        else
            cont =0;

        ant = converte_gray_dec(Melhor.getCromossomo());
        cout<< "Geracao: " << geracao << "\t";
        cout<< "X: "<<setprecision(15)<< converte_gray_dec(Melhor.getCromossomo()) <<"\t";
        cout<< "Y: "<< Melhor.getFitness() << "\n";

        geracao++;
    }
    cout<< "Geracao: " << geracao << "\t";
        cout<< "X: "<<setprecision(15)<< converte_gray_dec(Melhor.getCromossomo()) <<"\t";
        cout<< "Y: "<< Melhor.getFitness() << "\n";

}


