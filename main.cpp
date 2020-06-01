#include <iostream>
#include<ctime>
#include"MaxPointGA.h"

using namespace std;

int main()
{
    MaxPointGA meuga;
    meuga.setUpperLimit(20);
    meuga.setLowerLimit(-20);
    meuga.setPrecision(19);
    meuga.setPopTam(100);
    cout<<"o ponto maximo encontrado foi: "<<meuga.run(20);

}


