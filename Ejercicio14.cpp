//
//  Ejercicio14.cpp
//  Ejercicio1
//
//  Created by Rubén Gómez on 22/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//
/*
#include "Grafo.h"
#include "Manchas.h"
#include <string.h>
using namespace std;



bool resuelveCaso()
{
    unsigned int f, co;
    
    std::cin >> f; // número de filas
    
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    
    std::cin >> co; // número de columnas
    
    Matriz<bool> mapa = Matriz<bool>(f,co);
    
    //Ignoramos el \n
    std::cin.ignore();
    
    std::string linea;
    for(int i = 0; i < f; i++)
    {
        std::getline(std::cin,linea);
        
        for(int j = 0; j < co; j++)
        {
            mapa[i][j] = (linea[j] == '#');
        }
    }
    
    Manchas m = Manchas(mapa,f,co);
    std::cout << m.mayorNumeroManchas() << "\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}
*/