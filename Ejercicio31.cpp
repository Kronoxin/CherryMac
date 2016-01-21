//
//  Ejercicio31.cpp
//  Ejercicio1
//

/*
#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

bool resuelveCaso()
{
    
    //  monedas(i,j) = Numero minimo de monedas de tipo hasta i, con las que se puede pagar j.
    //
    //  monedas(i,0) = 0
    //  monedas(0,j) = inf.
    //
    //  monedas(i,j) =  monedas(i-1,j)      xi > j.
    //  monedas(i,j) =  1                   xi = j.
    //  monedas(i,j) =  min{ monedas(i-1), monedas(i-1,j-xi)+1 }
    //
    const int infinidad= 1000001;
    int nMonedas;
    
    std::cin >> nMonedas;
    
    
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    Matriz<int> monedas(nMonedas,nMonedas,infinidad);
    
    for (int i = 0 ; i< nMonedas ; i++)
    {
        for (int j = i; j < nMonedas; j++)
        {
            
            if( i == j)
            {
                monedas[i][j] = 0;
            }
            else{
                int c;
                std::cin >> c;
                monedas[i][j] = c;
            }
            
            
        }
    }
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}
*/