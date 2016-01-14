//
//  Ejercicio12.cpp
//  Ejercicio 12 - Arborescencias
//
//  Created by Rubén Gómez on 11/11/15.
//  Copyright © 2015 Rubén Gómez. All rights reserved.
//


#include <stdio.h>
#include "GrafoDirigido.h"

// Que no tenga ciclos, que sea conexo,basicamente -> que sea "ArbolLibre"...
 #include "GrafoDirigido.h"
 #include "Arborescencia.h"
 
#include "GrafoDirigido.h"
#include "Arborescencia.h"

/*
bool resuelveCaso()
{
    size_t V, A, v, w;
    std::cin >> V; // número de vértices
    if (!std::cin)  // hemos terminado de procesar todos los casos
        return false;
    std::cin >> A; // número de aristas
    GrafoDirigido grafo(V);
    // leemos las aristas
    for (int i = 0; i < A; ++i)
    {
        std::cin >> v >> w;
        grafo.ponArista(v,w);
    }
    
    Arborescencia arbol = Arborescencia(grafo);
    
    if(arbol.grafoArborescente())
        std::cout << "SI " << arbol.raiz() << "\n";
    else
        std::cout << "NO\n";
    
    return true;
}
int main()
{
    while(resuelveCaso());
    return 0;
}
*/
// Un arbol es conexo si el numéro de aristas es igual al de vertices - 1.

