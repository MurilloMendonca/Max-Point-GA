#include <iostream>
#include<ctime>
#include"MaxPointGA.h"

using namespace std;

int main()
{
    srand(time(NULL));
    MaxPointGA meuga;
    meuga.setUpperLimit(2);
    meuga.setLowerLimit(-2);
    meuga.setPrecision(19);
    meuga.setPopTam(300);
    meuga.setParams(1.0, 7.8, 1.0, sqrt(3));
    cout<<"o ponto maximo encontrado foi: "<<meuga.run(20);

}


