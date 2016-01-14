//
//  Ejercicio26.cpp
//  Ejercicio1
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Varillas.h"



bool resuelveCaso()
{
    
    
    int nVarillas;
    int longitudFinal;
    
    
    std::cin >> nVarillas;      //leemos el numero de varillas
    
    std::vector<int> varillas(nVarillas+1,0);
    std::vector<int> costes(nVarillas+1,0);
    
    if(!std::cin)               // si no tenemos entrada, terminamos
        return false;
    
    std::cin >> longitudFinal;  //longitud total alcanzable
    
    for(int i = 1 ; i<= nVarillas ; i++){
        int a;
        std::cin >> a;
        varillas[i] = a;
        std::cin >> a;
        costes[i] = a;
        
    }
    
    Varillas va(varillas,costes,nVarillas,longitudFinal);
    
    if(va.esPosible(longitudFinal))
        std::cout << "SI " << va.numCombinaciones(longitudFinal) << " " << va.numeroMinVarillas(longitudFinal) << " " << va.costeMinimo(longitudFinal) <<  "\n";
    else
        std::cout << "NO\n";

    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}