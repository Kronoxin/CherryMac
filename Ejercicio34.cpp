//
//  Ejercicio34.cpp
//  Las Vacas Pensantes
//



#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"

//Solución con vector


int maximizar_comida(std::vector<int> &cubos, int nCubos, Matriz<int> &solucion){
    int acumulado  = 0;
    
    for (int d = 2; d<=nCubos; d++) {
        for (int i = 0; i<nCubos-d; i++) {
            int j = i + d;
            
            int izquierda =0;
            int derecha =0;
            
            if(cubos[i] > cubos[j-1])
            {
                derecha =cubos[i] + solucion[i+1][j-1];
            }
            else
            {
                derecha = cubos[j] + solucion
            }
            
        }
    }
    
    return acumulado;
}

bool resuelveCaso()
{
    
    
    const int infinidad= 1000001;
    int nCubos;
    
    std::cin >> nCubos;
    
    if(nCubos == 0)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<int> cubos(nCubos,0);
    
    for (int i = 0; i<nCubos; i++) {
        int num;
        std::cin >> num;
        cubos[i] = num;
    }
    
    Matriz<int> solucion(nCubos,nCubos,0);
    

    int resultado = maximizar_comida(cubos,nCubos,extremoIzq,extremoDrch);
    std::cout << resultado << " " << std::endl;
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}