//
//  Ejercicio32.cpp
//  El Carpintero Ebanisto
//

#include <string>
#include <iostream>
#include <vector>
#include "Matriz.h"


//Solución con vector

int esfuerzo_minimo(std::vector<int> &puntosDeCorte, int nCortes, Matriz<int> &solucion)
{
    for ( int d = 1 ; d <nCortes; d++){
        
        
        for (int i =1; i <= nCortes-d; i++)
        {
            int j = i + d;
            int min = 1000001;
            for (int k = i+1; k < j; k++)
            {
                min = std::min(min,(solucion[i][k]+solucion[k][j])+2*(puntosDeCorte[j]-puntosDeCorte[i]));
            }
            solucion[i][j] = min;
        }
    }
    
    return solucion[1][nCortes];
}

bool resuelveCaso()
{
    
    //  esfuerzoMin(i,j) = Esfuerzo minimo para cortar una tabla de longitud Xj - Xi en j-i-1 trozos.
    //
    //  esfuerzoMin(i,0) =
    //  esfuerzoMin(0,j) =
    //
    //  esfuerzoMin(i,j) =                                                              xi >= xj.
    //  esfuerzoMin(i,j) =  0                                                           xj = xi+1.
    //  esfuerzoMin(i,j) =  min{ esfuerzoMin(i,k) + esfuerzoMin(k,j)}  + 2(xj-xi)     i+1 <= k < j
    //
    
    const int infinidad= 1000001;
    int longitudTablon;
    int nCortes;
    
    std::cin >> longitudTablon;
    std::cin >> nCortes;
    
    
    
    if(longitudTablon == 0 && nCortes == 0)               // si no tenemos entrada, terminamos
        return false;
    
    
    std::vector<int> puntosDeCorte(nCortes,0);
    
    for (int i = 0; i<nCortes; i++) {
        int num;
        std::cin >> num;
        puntosDeCorte[i] = num;
    }
    
    
    
    Matriz<int> solucion(nCortes+1,nCortes+1,0);
    
    std::cout << esfuerzo_minimo(puntosDeCorte,nCortes,solucion) << std::endl;
    
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}