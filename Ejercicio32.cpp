//
//  Ejercicio32.cpp
//  El Carpintero Ebanisto
//


#include <string>
#include <iostream>
#include <vector>


//Solución con vector

int esfuerzo_minimo(std::vector<int> &puntosDeCorte, int nCortes, std::vector<int> &solucion){
    
    
    return 1;
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
    //  esfuerzoMin(i,j) =  min{ esfuerzoMin(i-k) + esfuerzoMin(k,j)}  + 2(xj+xi)     i+1 <= k < j
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
    

    
    std::vector<int> solucion(nCortes,infinidad);
    solucion[0] = 0;
    
    
    std::cout << esfuerzo_minimo(puntosDeCorte,nCortes,solucion) << std::endl;
    
    
    
    
    return true;
    
}


int main()
{
    while(resuelveCaso());
    return 0;
}
